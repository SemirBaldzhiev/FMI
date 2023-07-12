#include "User.h"
#include <cstring>
#include <iostream>


User::User() {
    countRead = 0;
    borrowCount = 0;
    readedCapacity = 8;
    name = nullptr;

    editionsRead = new unsigned[readedCapacity];
}

User::User(const char* name) {
    setName(name);
    countRead = 0;
    borrowCount = 0;
    readedCapacity = 8;
    editionsRead = new unsigned[readedCapacity];
}


User::~User() {
    clear();
}

User::User(const User& other) {
    copy(other);
}

User& User::operator=(const User& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

User& User::operator+=(unsigned editionLibNum){
    
    if (borrowCount >= 5) {
        std::cout << "Cannot borrow more than 5 edtions!\n";
        return *this;
    }

    borrowedEditions[borrowCount] = editionLibNum;
    borrowTimes[borrowCount] = std::time(0);
    borrowCount++;
    return *this;
}

User& User::operator-=(unsigned editionLibNum) {
    
    returnEdition(editionLibNum);
    addInReaded(editionLibNum);
    return *this;
}

const User operator+(const User& usr, unsigned editionLibNum) {

    User result = usr;
    result += editionLibNum;
    return result;
}

const User operator-(const User& usr, unsigned editionLibNum) {
    User result = usr;
    result -= editionLibNum;
    return result;
}

bool operator==(const User& lhs, const User& rhs) {
    return strcmp(lhs.getName(), rhs.getName()) == 0;
}

bool operator!=(const User& lhs, const User& rhs) {
    return !(lhs == rhs);
}

bool operator<(const User& lhs, const User& rhs) {
    return lhs.getCountRead() < rhs.getCountRead();
}

bool operator<=(const User& lhs, const User& rhs) { 
    return !(rhs < lhs);
}

bool operator>(const User& lhs, const User& rhs) {
    return rhs < lhs;
}

bool operator>=(const User& lhs, const User& rhs) {
    return !(lhs < rhs);
}

// borrow     ->  1
// read       ->  0
// not borrow -> -1
int User::operator[](unsigned libNumber) {
    
    for (int i = 0; i < borrowCount; i++) {
        if (borrowedEditions[i] == libNumber) {
            return 1;
        }
    }

    for (int i = 0; i < countRead; i++) {
        if (editionsRead[i] == libNumber) {
            return 0;
        }
    }

    return -1;
}

void User::setName(const char* name) {

    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    else {
        std::cout << "Name you try to set is null!\n";
    }
}

const char* User::getName() const {
    return name;
}

unsigned User::getCountRead() const {
    return countRead;
}

void User::clear() {
    delete[] name;
    delete[] editionsRead;  
}

void User::copy(const User& other) {

    editionsRead = new unsigned[other.readedCapacity];
    readedCapacity = other.readedCapacity;
    countRead = other.countRead;
    borrowCount = other.borrowCount;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    for (int i = 0; i < other.countRead; i++) {
        editionsRead[i] = other.editionsRead[i];
    }    

    for (int i = 0; i < borrowCount; i++) {
        borrowedEditions[i] = other.borrowedEditions[i];
        borrowTimes[i] = other.borrowTimes[i];
    }
}

void User::write(std::ofstream& ofs) const {
    ofs <<  name << '\n';
    ofs << borrowCount << " - Borrow count" << "\n" << countRead << " - Borrow count" << '\n';
    ofs << "Borrow editions:\n";
    for (int i = 0; i < borrowCount; i++) {
        ofs << borrowedEditions[i] << " "; 
    }
    ofs << "\nTimes:\n";
    for (int i = 0; i < borrowCount; i++) {
        ofs << borrowTimes[i] << " ";
    }
    ofs << "\nReaded editions:\n";
    for (int i = 0; i < countRead; i++) {
        ofs << editionsRead[i] << " ";
    }
    ofs << '\n';
}

void User::returnEdition(unsigned editionLibNum) {
    int idx = -1;
    for (int i = 0; i < borrowCount; i++) {
        if (borrowedEditions[i] == editionLibNum) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
       std::cout << "There is no borrowed editions with this library number!\n";
       return;
    }

    borrowCount--;
    unsigned temp = borrowedEditions[borrowCount];
    borrowedEditions[borrowCount] = borrowedEditions[idx];
    borrowedEditions[idx] = temp;

    std::time_t tempTime = borrowTimes[borrowCount];
    borrowTimes[borrowCount] = borrowTimes[idx];
    borrowTimes[idx] = tempTime;
}

void User::addInReaded(unsigned editionLibNum) {

    if (countRead == readedCapacity) {
        resize();
    }

    editionsRead[countRead] = editionLibNum;
    countRead++;

}

void User::resize() {

    readedCapacity *= 2;
    unsigned* newEditionsRead = new unsigned[readedCapacity];

    for (int i = 0; i < countRead; i++) {
        newEditionsRead[i] = editionsRead[i];
    }

    delete[] editionsRead;
    editionsRead = newEditionsRead;
}

const std::time_t* User::getBorrowTimes() const{
    return borrowTimes;
}

const unsigned* User::getBorrowEditions() const {
    return borrowedEditions;
}

unsigned User::getBorrowCount() const {
    return borrowCount;
}

const unsigned* User::getReadEditions() const {
    return editionsRead;
}

void User::read(std::ifstream& ifs) {
    
    char bufferName[128];
    char dummyLine[256];

    ifs.getline(dummyLine, 256);
    ifs.getline(bufferName, 128);

    bufferName[strlen(bufferName)] = '\0';
    setName(bufferName);

    ifs >> borrowCount;

    ifs.getline(dummyLine, 256);


    ifs >> countRead;

    ifs.getline(dummyLine, 256);
    ifs.getline(dummyLine, 256);

    for (int i = 0; i < borrowCount; i++) {
        ifs >> borrowedEditions[i];
    }

    ifs.getline(dummyLine, 256);
    ifs.getline(dummyLine, 256);

    
    for (int i = 0; i < borrowCount; i++) {
        ifs >> borrowTimes[i];
    }

    ifs.getline(dummyLine, 256);
    ifs.getline(dummyLine, 256);

    for (int i = 0; i < countRead; i++) {
        ifs >> editionsRead[i];
    }
}