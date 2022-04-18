#include "ComputerStoreReader.h"
#include "ComputerPartReader.h"


#include <exception>

ComputerStore ComputerStoreReader::readStore(const char* fileName) {

	std::ifstream in(fileName);

	if (!in.is_open()) {
		throw std::exception("Cannot open file");
	}

	char name[128];
	char workingTime[12];
	unsigned int itemCount;
	double money;
	size_t availability;

	in.getline(name, 128);
	in.getline(workingTime, 16);
	in >> itemCount;

	in.get();
	in.get();
	in.get();

	Item* items = new Item[itemCount];

	for (int i = 0; i < itemCount; i++) {
		items[i].setItem(ComputerPartReader::readPart(in));
		in.get();
		in >> availability;
		in.get();
		items[i].setAvailability(availability);
	}

	in.get();
	in >> money;

	ComputerStore res(name, workingTime, itemCount, items, money);
	
	return res;
}