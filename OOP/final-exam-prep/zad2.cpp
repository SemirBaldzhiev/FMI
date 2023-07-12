#include <fstream>
#include <cstring>
#include <iostream>
#include <new>
#include <exception>
class Vacation {

    public:
        Vacation(int duration,const char name[],const char* desc, double price);
        Vacation(const Vacation& other);
        Vacation& operator=(const Vacation& other);
        virtual ~Vacation();

        virtual double getPrice() const = 0;
        virtual void printInfo() const = 0;
        virtual void save(std::ostream& out) const;
        virtual void load(std::istream in);

        int getDuration() const{
            return durationInDays;
        }

        virtual Vacation* clone() const = 0;

    protected:
        int durationInDays;
        char name[127];
        char* description;

        double basePrice;

    private:  
        void copy(const Vacation& other);
        void free();

};

class NatureVacation : public Vacation{

    public:
        NatureVacation(int duration, char name[], const char* desc, double price)
        : Vacation(duration, name, desc, price) {
        }
    
        ~NatureVacation() {}

        void printInfo() const override {
            std::cout << "Name: " << name << ", Description: " << description << "\n"; 
        }

        double getPrice() const override {
            return basePrice;
        }

        virtual Vacation* clone() const override {
            return new NatureVacation(*this);
        }

};

enum class Rank {
    FIRST = 0,
    SECOND = 1,
    THIRD = 2
};


class ShipVacation : public Vacation {
    public:
        ShipVacation(int duration, char name[], const char* desc, const char* shipName, Rank rank, double price)
            : Vacation(duration, name, desc, price)
        {
            this->shipName = new (std::nothrow) char[strlen(shipName) + 1];

            if (!this->shipName) {
                throw std::bad_alloc{};
            }

            strcpy(this->shipName, shipName);
            this->rank = rank;
        }
        ShipVacation(const ShipVacation& other) : Vacation(other) {
            this->shipName = new (std::nothrow) char[strlen(other.shipName) + 1];
            if (!this->shipName) {
                throw std::bad_alloc{};
            }

            strcpy(this->shipName, other.shipName);
            this->rank = other.rank;
        }
        ShipVacation& operator=(const ShipVacation& other) {
            if (this != &other) 
            {
                Vacation::operator=(other);
                delete[] shipName;
                this->shipName = new (std::nothrow) char[strlen(other.shipName) + 1];
                if (!this->shipName) {
                    throw std::bad_alloc{};
                }
                strcpy(this->shipName, other.shipName);
                this->rank = other.rank;
            }

            return *this;
        }
        ~ShipVacation() override {
            delete[] shipName;
        }

        void printInfo() const override {
            std::cout << "Name: " << name << ", ShipName: " << shipName << ", Description: " << description << "\n";
        }

        double getPrice() const override{
            if (this->rank == Rank::SECOND) {
                return basePrice;
            }
            else if (this->rank == Rank::FIRST) {
                return basePrice * 2;
            }
            else if (this->rank == Rank::THIRD) {
                return basePrice / 2;
            }
        }

        virtual Vacation* clone() const override {
            return new ShipVacation(*this);
        }
    private:
        char* shipName;
        Rank rank;
};

class PromoVacation : public Vacation {
    public:
        PromoVacation(int duration, char name[], const char* desc,const Vacation* vac, double perc) : Vacation(duration, name, desc, 0) {
            
            percentPromo = perc;
            this->vac = vac->clone();

        }

        PromoVacation(const PromoVacation& other) : Vacation(other) {
            vac = other.vac->clone();
            percentPromo = other.percentPromo;
        }

        PromoVacation& operator=(const PromoVacation& other) {
            if (this != &other) {
                Vacation::operator=(other);
                delete vac;
                vac = other.vac->clone();
                percentPromo = other.percentPromo;
            }
        }

        double getPrice() const override {
            return vac->getPrice() - vac->getPrice() * percentPromo;
        }

        void printInfo() const override {
            std::cout << "PROMOTION! ";
            vac->printInfo();
        }

        virtual Vacation* clone() const override {
            return new PromoVacation(*this);
        }
    private:
        Vacation* vac;
        double percentPromo;
};


class CombinedVacation : public Vacation {

    public:
        CombinedVacation(const char name[], const char* desc, const Vacation** vacs, int countVacs) : Vacation(1, name, desc, 0) {

            vacations = new Vacation*[countVacs];
            for (int i = 0; i < countVacs; ++i) {
                vacations[i] = vacs[i]->clone();
                durationInDays += vacations[i]->getDuration();
            }
            count = countVacs;
        } 

        CombinedVacation(const CombinedVacation& other) : Vacation(other) {
            count = other.count;
            for (int i = 0; i < count; i++) {
                vacations[i] = other.vacations[i]->clone();
            }
        }

        CombinedVacation& operator=(const CombinedVacation& other) {
            if (this != &other) {
                Vacation::operator=(other);
                for (int i = 0;i < count; i++) {
                    delete vacations[i];
                }
                delete[] vacations;

                count = other.count;
                for (int i = 0; i < count; i++) {
                    vacations[i] = other.vacations[i]->clone();
                }                
            }

            return *this;
        }

        double getPrice() const override {
            double res = 0;
            for (int i = 0; i < count; i++) {
                res += vacations[i]->getPrice();
            }

            return res;
        }

        void printInfo() const override {
            for (int i = 0; i < count; ++i) {
                vacations[i]->printInfo();
                std::cout << "\n";
            }
        }

        Vacation* clone() const override{
            return new CombinedVacation(*this);
        }

    private:
        Vacation** vacations;
        int count;
};

Vacation::Vacation(int duration, const char name[], const char* desc, double price) : durationInDays(duration) {
    strcpy(this->name, name);
    this->description = new (std::nothrow) char[strlen(desc) + 1];

    if (!this->description) {
        throw std::bad_alloc{};
    }

    strcpy(this->description, desc);
    basePrice = price;
} 

Vacation::Vacation(const Vacation& other) {
    copy(other);
}

Vacation& Vacation::operator=(const Vacation& other) {
    if (this != &other) {
        free();
        copy(other);
    }

    return *this;
}

void Vacation::copy(const Vacation& other) {
    
    this->description = new (std::nothrow) char[strlen(other.description) + 1];

    if (!this->description) {
        throw std::bad_alloc{};
    }

    strcpy(this->description,other.description);
    strcpy(name, other.name);
    this->durationInDays = other.durationInDays;
    basePrice = other.basePrice;
}

void Vacation::free() {
    delete[] description;
}

Vacation::~Vacation() {
    free();
}

int main() {
    return 0;
}