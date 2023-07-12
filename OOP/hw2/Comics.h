#ifndef COMICS_H__
#define COMICS_H__

#include "Book.h"
#include "PeriodicalEdition.h"
#include <fstream>
class Comics : public Book, public PeriodicalEdition {
    
    public:
        Comics();
        Comics(const char* title, const char* description, unsigned libraryNumber, unsigned year, 
           const char* author, const char* publishers, Characteristic c, Type type, TargetAudience ta,
           Periodicity p, unsigned count);
        Comics(const Comics& other);
        Comics& operator=(const Comics& other);
        ~Comics();

        PrintEdition* clone() const override;
        void write(std::ofstream& ofs) const override; 
        void read(std::ifstream& ifs) override;
        const char* getTypeEdition() const override;
};

#endif