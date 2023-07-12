#include "Book.h"
#include <cstring>
#include <fstream>
#include <iostream>

#include <bitset>

Book::Book() : PrintEdition(), author(nullptr), publishers(nullptr), genre(0) {

}

Book::Book(const char* title, const char* description, unsigned libraryNumber, unsigned year, 
           const char* author, const char* publishers, Characteristic c, Type type, TargetAudience ta)
    : PrintEdition(title, description, libraryNumber, year) {
    setAuthor(author);
    setPublishers(publishers);
    this->genre = 0;
    setCharacteristic(c);
    setType(type);
    setTargetAudience(ta);
    setControlBit();
}

Book::Book(const Book& other) : PrintEdition(other) {
    copy(other);
}

Book& Book::operator=(const Book& other) {

    if (this != &other) {
        PrintEdition::operator=(other);
        clear();
        copy(other);
    }

    return *this;
}

Book::~Book() {
    clear();
}

void Book::copy(const Book& other) {
    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);

    publishers = new char[strlen(other.publishers) + 1];
    strcpy(publishers, other.publishers);

    genre = other.genre;
}

void Book::setAuthor(const char* author) {
    
    if (author != nullptr) {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);
    }
    else {
        std::cout << "Author is nullptr!\n";
    }
}

const char* Book::getAuthor() const {
    return author;
}

void Book::setPublishers(const char* publishers) {

    if (publishers != nullptr) {
        this->publishers = new char[strlen(publishers) + 1];
        strcpy(this->publishers, publishers);
    }
    else {
        std::cout << "Publihers is nullptr!\n";
    }
}

void Book::setCharacteristic(Characteristic ch){
    genre |= ((int)ch & 0x7F);
}

void Book::setType(Type type) {
    genre |= (((int)type & 0xF) << 7);
}    

void Book::setTargetAudience(TargetAudience ta) {
    genre |= (((int)ta & 0xF) << 11);
}

void Book::setGenre(unsigned short genre) {

    this->genre = genre;
    setControlBit();
}

void Book::setControlBit() {
    
    genre |= (countSetBits(genre) % 2) << 15;
}

unsigned Book::countSetBits(unsigned short genre) {
    unsigned count = 0;
    
    while(genre) {
        count += genre & 1;
        genre >>= 1;
    }

    return count;
}

const char* Book::getCharacteristic() const {
    
    switch(genre & 0x7F) {
        case Characteristic::FICTION:       return "Fiction";
        case Characteristic::CRIME_FICTION: return "Crime Fiction";
        case Characteristic::THRILLER:      return "Thriller";
        default:                            return "Unknown";
    }
}

const char* Book::getType() const {

    switch ((genre >> 7) & 0xF) {
        case Type::DRAMA:  return "Drama";
        case Type::POETRY: return "Poetry";
        case Type::PROSE:  return "Prose";
        default:           return "Unknown";
    }
}

const char* Book::getTargetAudience() const {

    switch ((genre >> 11) & 0xF) {
        case TargetAudience::CHILDREN:    return "Children";
        case TargetAudience::ADOLESCENTS: return "Adolescents";
        case TargetAudience::ADULTS:      return "Adults";
        default:                          return "Unknown";
    }
}

const char* Book::getGenreAsText() const {
    return nullptr;
}

unsigned short Book::getGenre() const {
    return genre;
}

PrintEdition* Book::clone() const {
    return new Book(*this);
}

void Book::readBook(std::ifstream& ifs) {

    char c;
    char bufferAuthor[128];
    int authorLen= 0;
    char bufferPublisher[128];
    int pubLen = 0;
    unsigned short genre;
    ifs >> std::noskipws;
    ifs >> c;
    while (c != '|') {
        bufferAuthor[authorLen] = c;
        authorLen++; 
        ifs >> c;
    }

    bufferAuthor[authorLen] = '\0';
    setAuthor(bufferAuthor);

    ifs >> c;
    while (c != '|') {
        bufferPublisher[pubLen] = c;
        pubLen++;
        ifs >> c;
    }

    bufferPublisher[pubLen] = '\0';
    setPublishers(bufferPublisher);

    ifs >> genre;
    setGenre(genre);
}

void Book::read(std::ifstream& ifs) {
    PrintEdition::read(ifs);
    readBook(ifs);
    char c;
    ifs >> std::noskipws;
    ifs >> c;
}

void Book::writeBook(std::ofstream& ofs) const {
    ofs << author << "|" << publishers << "|" << genre;
}

void Book::write(std::ofstream& ofs) const {
    ofs << "Book: ";
    PrintEdition::write(ofs);
    writeBook(ofs);
    ofs << "] ";
}

const char* Book::getPublishers() const {
    return publishers;
}

const char* Book::getTypeEdition() const {
    return "Book";
}

void Book::clear() {
    delete[] author;
    delete[] publishers;
}