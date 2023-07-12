#ifndef __USER_MANAGER_H
#define __USER_MANAGER_H

#include <iostream>
#include <cstring>
#include "Utils.h"
#include <fstream>

class UserManager {
    public: 
        UserManager();
        UserManager(const UserManager& other) = delete;
        UserManager& operator=(const UserManager& other) = delete;
        ~UserManager();

        unsigned createUser(const char* name);
        unsigned removeUser(const char* name);

        unsigned getUsersCount() const;
        User* getUsers() const ;

        bool containsUser(const char* userName) const;
        bool existId(const unsigned id) const;

        int writeBinary(const char* fileName);
        void readBianry(const char* fileName);
    private:
        User* users;
        std::size_t capacity;
        std::size_t count;
        User sysUsr;
        unsigned lastSetId;

        void resize();
        int indexOf(const char* name);
};


#endif