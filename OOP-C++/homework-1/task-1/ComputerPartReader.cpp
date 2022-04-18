#include "ComputerPart.h"
#include "ComputerPartReader.h"

#include <fstream>
#include <cstring>
#include <exception>


ComputerPart& ComputerPartReader::readPart(std::ifstream& in) {
	
	if (!in.is_open()) {
		throw std::exception("Cannot open file");
	}

	char type[32];
	char brand[128];
	char model[128];
	unsigned int yearsWarranty;
	double price;

	in.get();
	in.getline(type, 32, '|');
	in.getline(brand, 128, '|');
	in.getline(model, 128, '|');
	
	in >> yearsWarranty;
	in.get();
	in >> price;

	Type typeEnum;

	if (strcmp(type, "MONITOR") == 0) {
		typeEnum = Type::MONITOR;
	}
	else if (strcmp(type, "CAMERA") == 0) {
		typeEnum = Type::CAMERA;
	}
	else if (strcmp(type, "COMPUTER") == 0) {
		typeEnum = Type::COMPUTER;
	}
	else if (strcmp(type, "HEADPHONES") == 0) {
		typeEnum = Type::HEADPHONES;
	}
	else if (strcmp(type, "KEYBOARD") == 0) {
		typeEnum = Type::KEYBOARD;
	}
	else if (strcmp(type, "LAPTOP") == 0) {
		typeEnum = Type::LAPTOP;
	}
	else if (strcmp(type, "MOUSE") == 0) {
		typeEnum = Type::MOUSE;
	}
	else if (strcmp(type, "UNKNOWN") == 0) {
		typeEnum = Type::UNKNOWN;
	}
	else {
		throw std::exception("Invalid type");
	}

	ComputerPart part(typeEnum, brand, model, yearsWarranty, price);

	return part;
}