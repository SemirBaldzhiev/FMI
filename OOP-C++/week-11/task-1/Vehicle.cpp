#include "Vehicle.h"
#include <cstring>

/*char* color;
char* brand;
int year;
int countSeats;
int maxSpeed;*/

Vehicle::Vehicle() : color(nullptr), brand(nullptr), year(0), countSeats(0), maxSpeed(0) { }

Vehicle::Vehicle(const Vehicle& other) {
	copy(other);
}

void Vehicle::copy(const Vehicle& other) {
	int colorSize = strlen(other.color) + 1;
	color = new char[colorSize];
	strcpy(color, other.color);

	int brandSize = strlen(other.brand) + 1;
	brand = new char[brandSize];
	strcpy(brand, other.brand);
}
