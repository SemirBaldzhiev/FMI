#ifndef USER_H__
#define USER_H__

#include "PrintEdition.h"
#include <ctime>

class User {
    public:
        User();
        User(const char* name);
        User(const User& other);
        User& operator=(const User& other);
        ~User();

        void setName(const char* name);
        const char* getName() const;

        unsigned getCountRead() const;
        const unsigned* getReadEditions() const;
        const std::time_t* getBorrowTimes() const;
        const unsigned* getBorrowEditions() const;
        unsigned getBorrowCount() const;

        User& operator+=(unsigned editionLibNum);
        User& operator-=(unsigned editionLibNum);
        int operator[](unsigned libNumber);

        void write(std::ofstream& ofs) const;
        void read(std::ifstream& ifs);

    private:
        char* name;
        unsigned* editionsRead;
        unsigned borrowedEditions[5];
        std::time_t borrowTimes[5];
        unsigned countRead;
        unsigned readedCapacity;
        unsigned borrowCount;

        void returnEdition(unsigned editionLibNum);
        void addInReaded(unsigned editionLibNum);

        void copy(const User& other);
        void clear();
        void resize();
};

bool operator==(const User& lhs, const User& rhs);
bool operator!=(const User& lhs, const User& rhs);
bool operator<(const User& lhs, const User& rhs);
bool operator<=(const User& lhs, const User& rhs);
bool operator>(const User& lhs, const User& rhs);
bool operator>=(const User& lhs, const User& rhs);

const User operator+(const User& usr, unsigned editionLibNum);
const User operator-(const User& usr, unsigned editionLibNum);


#endif