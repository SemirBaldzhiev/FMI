#ifndef BOOK_H__
#define BOOK_H__

#include "PrintEdition.h"

enum Characteristic {
    UNKNOWN_C = -1,

    FICTION,
    THRILLER,
    CRIME_FICTION,

    COUNT_C
};

enum Type {
    UNKNOWN_T = -1,

    POETRY,
    PROSE,
    DRAMA,

    COUNT_T
};

enum TargetAudience {
    UNKNOWN_TA= -1,

    CHILDREN,
    ADOLESCENTS,
    ADULTS,

    COUNT_TA
};

class Book : public virtual PrintEdition {

    public:
        Book();
        Book(const char* title, const char* description, unsigned libraryNumber, unsigned year,
            const char* author, const char* publishers, Characteristic c, Type type, TargetAudience ta);
        Book(const Book& other);
        Book& operator=(const Book& other);
        virtual ~Book();

        virtual PrintEdition* clone() const override;
        virtual const char* getTypeEdition() const override;

        void setAuthor(const char* author);
        const char* getAuthor() const;
        void setPublishers(const char* publishers);
        const char* getPublishers() const;

        virtual void write(std::ofstream& ofs) const override;
        virtual void read(std::ifstream& ifs) override;
        
        void setCharacteristic(Characteristic ch);
        void setType(Type type);
        void setTargetAudience(TargetAudience ta);
        void setGenre(unsigned short genre);

        const char* getCharacteristic() const;
        const char* getType() const;
        const char* getTargetAudience() const;
        unsigned short getGenre() const;
        const char* getGenreAsText() const;
    protected:
        char* author;
        char* publishers;
        unsigned short genre;

        void writeBook(std::ofstream& ofs) const;
        void readBook(std::ifstream& ifs);

    private:
        void clear();
        void copy(const Book& other);
        void setControlBit();
        unsigned countSetBits(unsigned short genre);

};

#endif