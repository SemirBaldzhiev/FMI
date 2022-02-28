#include <iostream>

enum BuildingType {
    UNKNOWN= -1,
    HOUSE,
    HOTEL,
    OFFICE  
};

enum Gender {
    MALE,
    FEMALE
};

struct Location {
    double x;
    double y;
};

struct Worker {
    char* workerName;
    char egn[10];
    double* rating;
    Gender gender;
};

struct Building {
    char* buldingName;
    BuildingType type;
    Worker workers[2];
    size_t height;
};




int main()
{
    return 0;
}