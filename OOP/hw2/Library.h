#ifndef LIBRARY_H__
#define LIBRARY_H__

#include "PrintEdition.h"
#include "User.h"
#include <fstream>

#define INITIAL_CAPACITY 8
#define DUE_TIME_SEC 300

class Library {

    public:
        Library();
        Library(const Library& other);
        Library& operator=(const Library& other);
        ~Library();

        void addEdition(PrintEdition& edition);
        void removeEdition(unsigned libraryNumber);
        void printEditionsInfo();
        void addUser(const User& user);
        void removeUser(const char* name);
        void printUsersNotReturnedEdition(unsigned libraryNumber) const;
        void printUsersByReadedEditions();
        void printOverdueEditions();
        void borrowEdition(User& user, unsigned libraryNumber);
        void returnEdition(User& user, unsigned libraryNumber);

        void writeEditions(std::ofstream& ofs) const;
        void writeUsers(std::ofstream& ofs) const;

        void readEditions(std::ifstream& ifs);
        void readUsers(std::ifstream& ifs);

        const PrintEdition* getEditionByLibNum(unsigned libNum) const;

    private:
        PrintEdition** editions;
        unsigned* copiesCount;
        User* users;
        PrintEdition** overdueEditions = nullptr;

        unsigned editionsCapacity;
        unsigned usersCapacity;
        unsigned editionsCount;
        unsigned usersCount;
        int capOverdue;
        int countOverdue;

        void resizeEditions();
        void resizeUsers();
        void clear();
        void copy(const Library& other);
        void resizeOverdue();

        bool compareEditions(const PrintEdition* first, const PrintEdition* second) const;
        int findUser(User& user) const;
        int availableEdition(unsigned libNum) const;
        void fillOverdueEditions();
        void clearOverdue();
        void printInfo(PrintEdition** editions, unsigned count) const;
        void sortEditions(PrintEdition** editions, unsigned count);
};

#endif