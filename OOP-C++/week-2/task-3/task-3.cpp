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
    
    char divisionInput[8];

    std::cin >> divisionInput;

    if (strcmp(divisionInput, "Assasin") == 0) {
        hero.division = ASSASSIN;
    }
    else if (strcmp(divisionInput, "Medic") == 0) {
        hero.division = MEDIC;
    }
    else if (strcmp(divisionInput, "Mage") == 0) {
        hero.division = MAGE;
    }
    else if (strcmp(divisionInput, "Tank") == 0) {
        hero.division = TANK;
    }
    
    char combatInput[8];
    std::cin >> combatInput;

    if (strcmp(divisionInput, "Range") == 0) {
        hero.combat = RANGE;
    }
    else if (strcmp(divisionInput, "Mele") == 0) {
        hero.combat = MELEE;
    }
    else if (strcmp(divisionInput, "Both") == 0) {
        hero.combat = BOTH;
    }
}

void printHero(const Hero& hero) {
    std::cout << "Name: " << hero.name << std::endl;

    std::cout << "Division: ";

    switch (hero.division)
    {
        case Division::ASSASSIN: std::cout << "Assasin" << std::endl; break;
        case Division::MAGE: std::cout << "Mage" << std::endl; break;
        case Division::MEDIC: std::cout << "Medic" << std::endl; break;
        case Division::TANK: std::cout << "Tank" << std::endl; break;
    }

    std::cout << "Combat: ";

    switch (hero.combat)
    {
        case Combat::RANGE: std::cout << "Range" << std::endl; break;
        case Combat::MELEE: std::cout << "Mele" << std::endl; break;
        case Combat::BOTH: std::cout << "Both" << std::endl; break;
    }
}

void deleteHero(Hero& hero) {
    delete[] hero.name;
}

int main()
{
    return 0;
}