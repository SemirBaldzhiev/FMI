#include <iostream>

enum Division {
    ASSASSIN,
    MEDIC,
    MAGE,
    TANK
};

enum Combat {
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero {
    char* name;
    Division division;
    Combat combat;
};

void initialize(Hero& hero) {
    int nameSize;
    std::cin >> nameSize;

    hero.name = new char[nameSize];

    std::cin >> hero.name;
    //std::cin >> hero.division;
}

void printHero(const Hero& hero) {
    std::cout << "Name: " << hero.name << std::endl;

    switch (hero.division)
    {
        case Division::ASSASSIN: std::cout << "Assasin"; break;
        case Division::MAGE: std::cout << "Mage"; break;
        case Division::MEDIC: std::cout << "Medic"; break;
        case Division::TANK: std::cout << "Tank"; break;
    }
}

void deleteHero(Hero& hero) {
    delete[] hero.name;
}

int main()
{
    return 0;
}