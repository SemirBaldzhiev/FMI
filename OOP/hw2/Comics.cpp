#include "Comics.h"

Comics::Comics() 
    : Book(), PeriodicalEdition(), PrintEdition() {

}

Comics::Comics(const char* title, const char* description, unsigned libraryNumber, unsigned year, 
           const char* author, const char* publishers, Characteristic c, Type type, TargetAudience ta,
           Periodicity p, unsigned count) 
           : PrintEdition(title, description, libraryNumber, year) {
    Book::setAuthor(author);
    Book::setPublishers(publishers);
    Book::setCharacteristic(c);
    Book::setType(type);
    Book::setTargetAudience(ta);
    PeriodicalEdition::setPeriodicity(p);
    PeriodicalEdition::setCount(count);
}

Comics::Comics(const Comics& other) 
    : Book(other), PeriodicalEdition(other), PrintEdition(other) {

}
Comics& Comics::operator=(const Comics& other) {

    if (this != &other) {
        Book::operator=(other);
        PeriodicalEdition::operator=(other);
        PrintEdition::operator=(other);
    }

    return *this;
}

Comics::~Comics() { }

PrintEdition* Comics::clone() const {
    return new Comics(*this);
}

void Comics::read(std::ifstream& ifs) {
    PrintEdition::read(ifs);
    Book::readBook(ifs);
    PeriodicalEdition::readPeriodicalEdition(ifs);
    char c;
    ifs >> std::noskipws;
    ifs >> c;
}

void Comics::write(std::ofstream& ofs) const {
    ofs << "Comics: ";
    PrintEdition::write(ofs);
    Book::writeBook(ofs);
    ofs << "|";
    PeriodicalEdition::writePeriodicalEdition(ofs);
    ofs << "] ";
}

const char* Comics::getTypeEdition() const {
    return "Comics";
}  