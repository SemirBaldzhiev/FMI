#include "PeriodicalEdition.h"
#include <cstring>
#include <iostream>


PeriodicalEdition::PeriodicalEdition() 
    : PrintEdition(), periodicity(Periodicity::UNKNOWN_P), count(0) {

}

PeriodicalEdition::PeriodicalEdition(const char* title, const char* description, unsigned libraryNumber, 
                                     unsigned year, Periodicity p, unsigned count) 
                                     : PrintEdition(title, description, libraryNumber, year){
    setPeriodicity(p);
    setCount(count);
}


PeriodicalEdition::PeriodicalEdition(const PeriodicalEdition& other) 
    : PrintEdition(other) {
    copy(other);
}

PeriodicalEdition PeriodicalEdition::operator=(const PeriodicalEdition& other) {
    if (this != &other) {
        PrintEdition::operator=(other);
        copy(other);
    }

    return *this;
}

PeriodicalEdition::~PeriodicalEdition() { }

void PeriodicalEdition::setPeriodicity(Periodicity p) {
    periodicity = p;
}
void PeriodicalEdition::setCount(unsigned count) {
    this->count = count;
}
unsigned PeriodicalEdition::getCount() const {
    return count;
}


PrintEdition* PeriodicalEdition::clone() const {
    return new PeriodicalEdition(*this);
}

void PeriodicalEdition::setPeriodicityFromText(const char* period) {
    
    if (strcmp(period, "Monthly") == 0) {
        periodicity = Periodicity::MONHTLY;
    } 
    else if (strcmp(period, "Weekly") == 0) {
        periodicity  = Periodicity::WEEKLY;
    }
    else if (strcmp(period, "Once a year") == 0) {
        periodicity = Periodicity::ONCE_A_YEAR;
    }
    else {
        periodicity = Periodicity::UNKNOWN_P;
    }
}

const char* PeriodicalEdition::getPeriodicityAsText() const {
    switch(periodicity) {
        case Periodicity::MONHTLY: return "Monthly";
        case Periodicity::WEEKLY: return "Weekly";
        case Periodicity::ONCE_A_YEAR: return "Once a year";
        case Periodicity::UNKNOWN_P: return "Unknown";
    }

    return nullptr;
}

void PeriodicalEdition::writePeriodicalEdition(std::ofstream& ofs) const {
    ofs << getPeriodicityAsText() << "|" << count;
}

void PeriodicalEdition::readPeriodicalEdition(std::ifstream& ifs) {
    
    char c;
    char bufferPeriod[128];
    int periodLen = 0;
    unsigned count;

    ifs >> std::noskipws;

    ifs >> c;

    ifs >> c;
    while (c != '|') {
        bufferPeriod[periodLen] = c;
        periodLen++;
        ifs >> c; 
    }

    bufferPeriod[periodLen] = '\0';
    setPeriodicityFromText(bufferPeriod); 

    ifs >> count;
    setCount(count);
}

void PeriodicalEdition::read(std::ifstream& ifs) {
    PrintEdition::read(ifs);
    readPeriodicalEdition(ifs);
    char c;
    ifs >> std::noskipws;
    ifs >> c;
}

void PeriodicalEdition::write(std::ofstream& ofs) const {
    ofs << "PeriodicalEdition: ";
    PrintEdition::write(ofs);
    writePeriodicalEdition(ofs);
    ofs << "] ";
} 

void PeriodicalEdition::copy(const PeriodicalEdition& other) {
    periodicity = other.periodicity;
    count = other.count;
}

const char* PeriodicalEdition::getTypeEdition() const {
    return "PeriodicalEdition";
}