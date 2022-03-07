#include <iostream>
#include <fstream>
#include <cstring>

const unsigned int MAX_ANIMAL_COUNT = 16;

enum AnimalType {
    UNKNOWN = -1,
    DOG,
    CAT,
    RABBIT,
    COUNT
};

struct Animal {
    AnimalType type;
    char name[16];
    unsigned int age;
    char gender;
};

struct ZooMag {
    char name[32];
    Animal listOfAnimals[MAX_ANIMAL_COUNT];
    unsigned int countAnimals;

    void addAnimal(const Animal& animal) {
        if (countAnimals < MAX_ANIMAL_COUNT) {
            listOfAnimals[countAnimals].type = animal.type;

            for (int i = 0; name[i] != '\0'; i++) {
                listOfAnimals[countAnimals].name[i] = animal.name[i];
            }

            listOfAnimals[countAnimals].age = animal.age;
            listOfAnimals[countAnimals].gender = animal.gender;

            countAnimals++;
        }
    }

    void printAnimal(const char animalName[], const AnimalType type) {

        bool isNotFound = true;;

        for (int i = 0; i < countAnimals; i++) {
            if (strcmp(animalName, listOfAnimals[i].name) == 0 && type == listOfAnimals[i].type) {
                
                std::cout << "Type: ";
                switch (type)
                {
                    case AnimalType::CAT: std::cout << "Cat\n"; break;
                    case AnimalType::DOG: std::cout << "Dog\n"; break;
                    case AnimalType::RABBIT: std::cout << "Rabbit\n"; break;
                    case AnimalType::UNKNOWN: std::cout << "Unknown type\n"; break;
                }
                std::cout << "Name: " << listOfAnimals[i].age << std::endl;
                std::cout << "Age: " << listOfAnimals[i].name << std::endl;
                std::cout << "Gender: " << listOfAnimals[i].name << std::endl;
                
                isNotFound = false;
                break;
            }
        }

        if (isNotFound) {
            std::cout << "Animal is not found!" << std::endl;
        }
    }

    void saveAnimalsData(const char filePath[]) {

        std::ofstream file;

        for (int i = 0; i < countAnimals; i++) {
            saveToFile(listOfAnimals[i], filePath);
        }
    }
};

void saveToFile(const Animal& animal, const char filePath[]) {

    std::fstream file;

    char animalType[8];

    file.open(filePath, std::ios::out | std::ios::app);

    if (file.is_open()) {

        switch (animal.type)
        {
            case AnimalType::CAT: file << "Cat\n"; break;
            case AnimalType::DOG: file << "Dog\n"; break;
            case AnimalType::RABBIT: file << "Rabbit\n"; break;
            case AnimalType::UNKNOWN: file << "Unknown type\n"; break;
        }

        file << animal.name << "\n";
        file << animal.age << "\n";
        file << animal.gender << "\n";

        file.close();
    }
    else {
        std::cout << "Cannot open file!" << std::endl;
    }
}

void readFromFile(const char filePath[], Animal& animal) {
    std::ifstream file;

    file.open(filePath);

    char buffer[64];

    char type[8];

    file >> type;

    if (strcmp(type, "Dog") == 0) {
        animal.type = AnimalType::DOG;
    }
    else if (strcmp(type, "Cat") == 0) {
        animal.type = AnimalType::CAT;
    }
    else if (strcmp(type, "Rabbit") == 0) {
        animal.type = AnimalType::RABBIT
    }
    else {
        animal.type = AnimalType::UNKNOWN;
    }

    file >> animal.name;
    file >> animal.age;
    file >> animal.gender;

    file.close();
}

int main()
{
    return 0;
}
