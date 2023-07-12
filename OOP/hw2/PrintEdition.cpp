#include "PrintEdition.h"
#include <cstring>
#include <fstream>
#include <iostream>

PrintEdition::PrintEdition() : title(nullptr), description(nullptr), libraryNumber(0), year(0) {

}

PrintEdition::PrintEdition(const char* title, const char* description, unsigned libraryNumber, unsigned year) {
    setTitle(title);
    setDescription(description);
    setLibNumber(libraryNumber);
    setYear(year);
}

PrintEdition::PrintEdition(const PrintEdition& other) {
    copy(other);
}

PrintEdition& PrintEdition::operator=(const PrintEdition& other) {

    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
} 

PrintEdition::~PrintEdition() {
    clear();
}

void PrintEdition::setTitle(const char* title) {
    if (title != nullptr) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }
    else {
        std::cout << "Title is nullptr!\n";
    }
}

const char* PrintEdition::getTitle() const {
    return title;
}

void PrintEdition::setDescription(const char* description) {
    if (description != nullptr) {
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
    }
    else {
        std::cout << "Description is nullptr!\n";
    }
}

const char* PrintEdition::getDescription() const {
    return description;
}

void PrintEdition::setLibNumber(unsigned libNumber) {
    libraryNumber = libNumber;
}

unsigned PrintEdition::getLibNumber() const {
    return libraryNumber;
}

void PrintEdition::setYear(unsigned year) {
    if (year <= 2023) {
        this->year = year;
    }
    else {
        std::cout << "Year is greater than 2023!\n";
    }
}

unsigned PrintEdition::getYear() const {
    return year;
}

void PrintEdition::write(std::ofstream& ofs) const {
    ofs << "[" << libraryNumber << "|" << title << "|" << year << "|" << description << "|"; 
}

void PrintEdition::read(std::ifstream& ifs) {
    
    char c;
    char bufferTitle[128];
    unsigned lenTitle = 0;
    char bufferDescription[256];
    unsigned lenDescription = 0;
    unsigned libNum;
    unsigned year;

    // removes [
    ifs >> std::noskipws;
    ifs >> c;
    ifs >> c;

    ifs >> libNum;
    setLibNumber(libNum);

    ifs >> c;

    ifs >> c;
    while (c != '|') {
        bufferTitle[lenTitle] = c;
        lenTitle++;
        ifs >> c;
    }

    bufferTitle[lenTitle] = '\0';
    setTitle(bufferTitle);


    ifs >> year;
    setYear(year);

    ifs >> c;

    ifs >> c;
    while (c != '|') {
        bufferDescription[lenDescription] = c;
        lenDescription++;
        ifs >> c;
    }

    bufferDescription[lenDescription] = '\0';
    setDescription(bufferDescription);

}

void PrintEdition::copy(const PrintEdition& other) {

    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);

    libraryNumber = other.libraryNumber;
    year = other.year;
}

void PrintEdition::clear() {
    delete[] title;
    delete[] description;
}

