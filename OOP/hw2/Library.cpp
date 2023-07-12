#include "Library.h"
#include <cstring>
#include <iostream>
#include "Book.h"
#include "PeriodicalEdition.h"
#include "Comics.h"

Library::Library() {
    editionsCapacity = INITIAL_CAPACITY;
    usersCapacity = INITIAL_CAPACITY;
    editionsCount = 0;
    usersCount = 0;
    editions = new PrintEdition* [editionsCapacity];
    users = new User[usersCapacity];
    copiesCount = new unsigned[editionsCapacity];
    overdueEditions = nullptr;
    countOverdue = 0;
    capOverdue = INITIAL_CAPACITY*2;
}

Library::Library(const Library& other) {
    copy(other);
}

Library& Library::operator=(const Library& other) {

    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Library::~Library() {
    clear();
}


void Library::borrowEdition(User& user, unsigned libraryNumber) {
    
    int indexEdition = availableEdition(libraryNumber);

    if (indexEdition == -1) {
        std::cout << "There is no edition with this lib num!\n";
        return;
    }
    
    if (copiesCount[indexEdition] == 0) {
        std::cout << "There is no available copies for this edition\n";
        return;
    }

    int index = findUser(user);
    
    if (index == -1) {
        std::cout << "User do not exists!\n";
        return;
    }

    users[index] += libraryNumber;
    copiesCount[indexEdition]--;
}

void Library::returnEdition(User& user, unsigned libraryNumber) {
    int index = findUser(user);

    if (index == -1) {
        std::cout << "User do not exists!\n";
        return;
    }

    int indexEdition = availableEdition(libraryNumber);

    if (indexEdition == -1) {
        std::cout << "There is no edition with this lib num\n";
        return;
    }

    users[index] -= libraryNumber;
    copiesCount[indexEdition]++;
}


void Library::addEdition(PrintEdition& edition) {

    for (int i = 0; i < editionsCount; i++) {
        if (editions[i]->getLibNumber() == edition.getLibNumber()) {
            std::cout << "There is another edition with this library number!\n";
            return;
        }
    }

    if (editionsCapacity == editionsCount) {
        resizeEditions();
    }

    editions[editionsCount] = edition.clone();
    copiesCount[editionsCount] = 5;
    editionsCount++; 

}

void Library::removeEdition(unsigned libraryNumber) {

    int remIndex = availableEdition(libraryNumber);

    if (remIndex == -1) {
        std::cout << "There is no edition with this library number!\n";
        return;
    }
    
    for (int i = 0; i < usersCount; i++) {
        for (int j = 0; j < users[i].getBorrowCount(); j++) {
            if (users[i].getBorrowEditions()[j] == libraryNumber) {
                std::cout <<"Cannot remove this editions because is borrowed\n";
                return;
            }
        }
    }

    // I think that if this editions is in user(s) read collection
    // it can't be removed from the library, because this will affect
    // user(s) data and the edition will disapear from his/her collection
    // Other way solve this is to remove it from usre(s) collection also
    // but i choose the first one because its not strictly mentioned in homework terms 

    for (int i = 0; i < usersCount; i++) {
        for (int j = 0; j < users[i].getCountRead(); j++) {
            if (users[i].getReadEditions()[j] == libraryNumber) {
                std::cout << "Cannot remove this editions because is in read collection of user!\n";
                return;
            }
        }
    }

    editionsCount--;
    PrintEdition* temp = editions[editionsCount];
    editions[editionsCount] = editions[remIndex];
    editions[remIndex] = temp;

    unsigned tempCnt = copiesCount[editionsCount];
    copiesCount[editionsCount] = copiesCount[remIndex];
    copiesCount[remIndex] = tempCnt;
    copiesCount[editionsCount] = 0;
}


void Library::addUser(const User& user) {
    
    for (int i = 0; i < usersCount; i++) {
        if (users[i] == user) {
            std::cout << "There is another user with this username\n";
            return;
        }
    }

    if (usersCapacity == usersCount) {
        resizeUsers();
    }
    users[usersCount] = user;
    usersCount++;
}

void Library::removeUser(const char* name) {

    if (name == nullptr) {
        std::cout << "Name is null!\n";
        return;
    }

    int remIndex = -1;
    for (int i = 0; i < usersCount; i++) {

        if (strcmp(users[i].getName(), name) == 0) {
            remIndex = i;
            break;
        }   
    }

    if (remIndex == -1) {
        std::cout << "There is no user with this name!\n";
        return;
    }

    if (users[remIndex].getBorrowCount() > 0) {
        std::cout << "User should return editions before remove";
        return;
    }

    User temp = users[usersCount - 1];
    users[usersCount - 1] = users[remIndex];
    users[remIndex] = temp;
    usersCount--;

}

void Library::printUsersByReadedEditions() {
    
    for (int i = 0; i < usersCount - 1; i++) {

        for (int j = 0; j < usersCount - i - 1; j++) {
            if (users[j].getCountRead() < users[j + 1].getCountRead()) {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < usersCount; i++) {
        std::cout << "Name: " << users[i].getName() 
                  << " Readed editions count: " << users[i].getCountRead() << "\n";
    }
}

bool Library::compareEditions(const PrintEdition* first,const  PrintEdition* second) const {

    if (first == nullptr || second == nullptr) {
        return false;
    }

    if (first->getYear() != second->getYear()) {
        return first->getYear() < second->getYear();
    }

    if (strcmp(first->getTitle(), second->getTitle()) != 0) {
        return strcmp(first->getTitle(), second->getTitle()) < 0;
    }

    if (strcmp(first->getTypeEdition(), "PeriodicalEdition") == 0 && 
        strcmp(second->getTypeEdition(), "PeriodicalEdition") == 0) {
        const PeriodicalEdition* p1 = dynamic_cast<const PeriodicalEdition*>(first);
        const PeriodicalEdition* p2 = dynamic_cast<const PeriodicalEdition*>(second);

        if (p1->getCount() != p2->getCount()) {
            return p1->getCount() < p2->getCount();
        }
    }

    return false;
}

void Library::printEditionsInfo() {
    
    PrintEdition** newEditions = new PrintEdition*[editionsCount];
    
    for(int i = 0; i < editionsCount; i++) {
        newEditions[i] = editions[i]->clone();
    }
    sortEditions(newEditions, editionsCount);
    printInfo(newEditions, editionsCount);

    for (int i = 0; i < editionsCount; i++) {
        delete newEditions[i];
    }

    delete[] newEditions;
}

void Library::printUsersNotReturnedEdition(unsigned libraryNumber) const {

    for (int i = 0; i < usersCount; i++) {
        if (users[i][libraryNumber] == 1) {
            std::cout << "Name: " << users[i].getName() << "\n";
        }
    }
}  

void Library::printOverdueEditions() {

    fillOverdueEditions();
    sortEditions(overdueEditions, countOverdue);
    printInfo(overdueEditions, countOverdue);
}

void Library::fillOverdueEditions() {
    
    if (overdueEditions != nullptr) {
        clearOverdue();
    }
    overdueEditions = new PrintEdition*[capOverdue];

    time_t currTime = std::time(0);
    for (int i = 0; i < usersCount; i++) {
        for (int j = 0; j < users[i].getBorrowCount(); j++) {
            unsigned libNum = users[i].getBorrowEditions()[j];
            time_t time = users[i].getBorrowTimes()[j];
            double diffTime = std::difftime(currTime, time);

            // DUE_TIME_SEC is set to 300 for test purposes should be 1 month 
            if (diffTime > DUE_TIME_SEC) {
                if (countOverdue==capOverdue) {
                    resizeOverdue();
                }

                overdueEditions[countOverdue] = getEditionByLibNum(libNum)->clone();
                countOverdue++;
            }
        }
    }
}

const PrintEdition* Library::getEditionByLibNum(unsigned libNum) const {
    for (int i = 0; i < editionsCount; i++) {
        if (editions[i]->getLibNumber() == libNum) {
            return editions[i];
        }
    }

    return nullptr;
}

void Library::writeEditions(std::ofstream& ofs) const {
    
    ofs << editionsCount << '\n';
    for (int i = 0; i < editionsCount; i++) {
        editions[i]->write(ofs);
        ofs << copiesCount[i] << '\n';
    }
}

void Library::readEditions(std::ifstream& ifs) {
    int cnt;
    ifs >> cnt;

    for (int i = 0; i < cnt; i++) {

        char c;
        char bufferTypeEdition[128];
        int lenTypeEdition = 0;

        ifs >> c;
        while (c != ':') {
            bufferTypeEdition[lenTypeEdition] = c;
            lenTypeEdition++;
            ifs >> c;
        }

        bufferTypeEdition[lenTypeEdition] = '\0';

        if (strcmp(bufferTypeEdition, "Book") == 0) {
            Book b;
            b.read(ifs);
            addEdition(b);
            ifs >> c;
            ifs >> copiesCount[editionsCount - 1];
        }
        else if (strcmp(bufferTypeEdition, "PeriodicalEdition") == 0) {
            PeriodicalEdition pe;
            pe.read(ifs);
            addEdition(pe);
            ifs >> c;

            ifs >> copiesCount[editionsCount - 1];
        }
        else if (strcmp(bufferTypeEdition, "Comics") == 0){
            Comics co;
            co.read(ifs);
            addEdition(co);
            ifs >> c;
            ifs >> copiesCount[editionsCount - 1];
        }
        else {
            throw std::invalid_argument("Cannot read edition with this type!");
        }

        ifs >> c;
    }
}

void Library::writeUsers(std::ofstream& ofs) const {
    ofs << usersCount << '\n'; 
    for (int i = 0; i < usersCount; i++) {
        users[i].write(ofs);
    }
}

void Library::resizeEditions() {
    editionsCapacity *= 2;

    PrintEdition** newEditions = new PrintEdition* [editionsCapacity];
    unsigned* newCopiesCount = new unsigned[editionsCapacity];

    for (int i = 0; i < editionsCount; i++) {
        newEditions[i] = editions[i];
    }

    delete[] editions;
    editions = newEditions;
}

void Library::resizeUsers() {

    usersCapacity *= 2;
    User* newUsers = new User[usersCapacity];

    for (int i = 0; i < usersCount; i++) {
        newUsers[i] = users[i];
    }

    delete[] users;
    users = newUsers;
}

void Library::clear() {
    for (int i = 0; i < editionsCount; i++) {
        delete editions[i];    
    }

    delete[] editions;
    delete[] users;
    delete[] copiesCount;

    if (overdueEditions != nullptr) {
        clearOverdue();
    }
}

void Library::copy(const Library& other) {

    users = new User[other.usersCapacity];
    editions = new PrintEdition* [other.editionsCapacity];
    usersCapacity = other.usersCapacity;
    usersCount = other.usersCount;
    editionsCapacity = other.editionsCapacity;
    editionsCount = other.editionsCount;
    copiesCount = new unsigned[other.editionsCapacity];
    capOverdue = other.capOverdue;
    countOverdue = other.countOverdue;

    overdueEditions = new PrintEdition*[capOverdue];

    for (int i = 0; i < countOverdue; i++) {
        overdueEditions[i] = other.overdueEditions[i]->clone();
    }

    for (int i = 0; i < usersCount; i++) {
        users[i] = other.users[i];
    }

    for (int i = 0; i < editionsCount; i++) {
        editions[i] = other.editions[i]->clone();
    }

    for (int i = 0; i < editionsCount; i++) {
        copiesCount[i] = other.copiesCount[i];
    }
}

int Library::findUser(User& user) const {

     for (int i = 0; i < usersCount; i++) {
  
        if (users[i] == user) {
            return i;
        }
    }

    return -1;
}
int Library::availableEdition(unsigned libNum) const {
    for (int i = 0; i < editionsCount; i++){
        if (editions[i]->getLibNumber() == libNum) {
            return i;
        }
    }

    return -1;
}

void Library::resizeOverdue() {
    capOverdue*=2;
    PrintEdition** newOverdueEditions = new PrintEdition*[capOverdue];
    
    for (int i = 0; i < countOverdue; i++) {
        newOverdueEditions[i] = overdueEditions[i];
    }

    delete[] overdueEditions;
    overdueEditions = newOverdueEditions;
}

void Library::clearOverdue() {
    for (int i = 0; i < countOverdue; i++) {
        delete overdueEditions[i];
    } 

    delete[] overdueEditions;
}

void Library::readUsers(std::ifstream& ifs) {   
    int count;
    ifs >> count;

    for (int i = 0; i < count; i++) {
        User u;
        u.read(ifs);
        addUser(u);
    }
}

void Library::printInfo(PrintEdition** editions, unsigned count) const {
    for (int i = 0; i < count; i++) {
        std::cout << "Title: " << editions[i]->getTitle() << ", "
                  << "Type: " << editions[i]->getTypeEdition() << ", "
                  << "Description: " << editions[i]->getDescription() << ", "
                  << "LibNumber: " << editions[i]->getLibNumber() << '\n';
    }
}
void Library::sortEditions(PrintEdition** editions, unsigned count) {
    if (count == 0) {
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compareEditions(editions[j], editions[j + 1])) {
                std::swap(editions[j], editions[j + 1]);
            }
        } 
    }
}