#include "Item.h"
#include "ComputerPart.h"

Item::Item() : availabity(0), item(ComputerPart()) {}

ComputerPart Item::getItem() const {
	return item;
}

size_t Item::getAvailability() const {
	return availabity;
}

void Item::setItem(ComputerPart& item) {
	this->item = item;
}

void Item::increaseAvailability() {
	availabity++;
}

void Item::decreaseAvailability() {
	
	if (availabity <= 0) {
		availabity = 0;
	}
	else {
		availabity--;
	}
}

void Item::setAvailability(size_t availability) {
	this->availabity = availability;
}

void Item::writeInBinary(std::ofstream& out) {
	out.write(reinterpret_cast<const char*>(&availabity), sizeof(availabity));
	this->getItem().writePartBin(out);
}