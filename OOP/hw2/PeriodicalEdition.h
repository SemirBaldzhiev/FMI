#ifndef PERIODICAL_EDITION_H__
#define PERIODICAL_EDITION_H__

#include "PrintEdition.h"
#include <fstream>

enum Periodicity {
    UNKNOWN_P = -1,
    
    WEEKLY,
    MONHTLY,
    ONCE_A_YEAR,
    
    COUNT_P
};

class PeriodicalEdition : public virtual PrintEdition {

    public:
        PeriodicalEdition();
        PeriodicalEdition(const char* title, const char* description, unsigned libraryNumber, unsigned year, Periodicity p, unsigned count);
        PeriodicalEdition(const PeriodicalEdition& other);
        PeriodicalEdition operator=(const PeriodicalEdition& other);
        virtual ~PeriodicalEdition();

        virtual PrintEdition* clone() const override;

        virtual void write(std::ofstream& ofs) const override;
        virtual void read(std::ifstream& ifs) override;

        void setPeriodicity(Periodicity p);
        const char* getPeriodicityAsText() const;

        void setCount(unsigned count);
        unsigned getCount() const;

        void setPeriodicityFromText(const char* period);
        virtual const char* getTypeEdition() const override;  



    protected:
        Periodicity periodicity;
        unsigned count;

        void writePeriodicalEdition(std::ofstream& ofs) const;
        void readPeriodicalEdition(std::ifstream& ifs);

    private:
        void copy(const PeriodicalEdition& other);
        
};


#endif