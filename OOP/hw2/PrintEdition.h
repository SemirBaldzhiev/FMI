#ifndef PRINT_EDITION_H__
#define PRINT_EDITION_H__

#include <fstream>

class PrintEdition {
    public:
        PrintEdition();
        PrintEdition(const char* title, const char* description, unsigned libraryNumber, unsigned year);
        PrintEdition(const PrintEdition& other);
        PrintEdition& operator=(const PrintEdition& other);
        virtual ~PrintEdition();

        virtual PrintEdition* clone() const = 0;    
        virtual const char* getTypeEdition() const = 0;

        void setTitle(const char* title);
        const char* getTitle() const;
        void setDescription(const char* description);
        const char* getDescription() const;
        void setLibNumber(unsigned libNumber);
        unsigned getLibNumber() const;
        void setYear(unsigned year);
        unsigned getYear() const;

        virtual void write(std::ofstream& ofs) const;
        virtual void read(std::ifstream& ifs);

    protected:
        char* title;
        char* description;
        unsigned libraryNumber;
        unsigned year;

    private:
        void clear();
        void copy(const PrintEdition& other);
};

#endif
