#include "UserManager.h"

UserManager::UserManager() : capacity(4), lastSetId(1) {
    users = new User[capacity];
    std::strcpy(sysUsr.name, "System user");
    sysUsr.id = 0;
    this->count = 0;
}
UserManager::~UserManager() {
    delete[] users;
}

unsigned UserManager::createUser(const char* name) {

    if (name == nullptr) {
        std::cout << "In function createUser parameter name is nullptr!";
        return 0;
    }

    if (count == capacity) {
        resize();
    }

    User newUser;
    std::strcpy(newUser.name, name);
    setUserID(newUser, lastSetId);

    users[this->count] = newUser;
    this->count++;
    return newUser.id;
}

unsigned UserManager::removeUser(const char* name) { 

    if (name == nullptr) {
        std::cout << "In function removeUser parameter name is nullptr!";
        return 0;
    }
    
    int index = indexOf(name);
    unsigned retId = users[index].id;
    
    if (index == -1) {
        std::cout << "User with name: " << name << " does not exist!";
        return 0;
    }

    for (int i = index; i < count - 1; i++) {
        users[i] = users[i + 1];
    }

    this->count--;
    return retId;
}

int UserManager::writeBinary(const char* fileName) {

    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Cannot open file " << fileName << " for writing in binary!";
        return -1;
    }

    for (int i = 0; i < count; i++) {
        ofs.write(reinterpret_cast<char *>(&users[i]), sizeof(User));
    }

    ofs.close();
    return 0;
}

User* UserManager::getUsers() const {
    return this->users;
}

unsigned UserManager::getUsersCount() const {
    return this->count;
}

void UserManager::readBianry(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "File with name " << fileName << " does not exist!\n";
        return;
    }

    ifs.seekg(0, std::ios::end);
    int fileSize = ifs.tellg();

    ifs.seekg(0, std::ios::beg);

    unsigned countUsers = fileSize / sizeof(User);

    for (int i = 0; i < countUsers; i++) {
        
        if (count == capacity) {
            resize();
        }
        
        ifs.read(reinterpret_cast<char *>(&users[i]), sizeof(User));

        count++;
    } 
    unsigned max = 0;
    for (int i = 0; i < countUsers; i++) {
        if (users[i].id > max) {
            max = users[i].id;
        }
    }

    lastSetId = max+1;
    ifs.close();
}

int UserManager::indexOf(const char* name) {

    for (int i = 0; i < this->count; i++) {
        if (!std::strcmp(users[i].name, name)){
            return i;
        }
    }

    return -1;
}

void UserManager::resize() {
    User* newStorage = new User[capacity * 2];

    for (int i = 0; i < count; ++i) {
        newStorage[i] = users[i];
    }

    capacity *= 2;

    delete[] users;
    users = newStorage;
}

bool UserManager::containsUser(const char* userName) const {


    for (int i = 0; i < count; i++) {
        if (!std::strcmp(users[i].name, userName)) {
            return true;
        }
    }

    return false;
} 

bool UserManager::existId(const unsigned id) const {
    for (int i = 0; i < count; i++) {
        if (users[i].id == id) {
            return true;
        }
    }

    return false;
}

