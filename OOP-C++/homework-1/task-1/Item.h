#ifndef AVAILABLE_ITEMS_H
#define AVAILABLE_ITEMS_H

#include "ComputerPart.h"
#include <fstream>


class Item {
private:
	ComputerPart item;
	size_t availabity;

public:
	Item();
	size_t getAvailability() const;
	ComputerPart getItem() const;
	
	void setItem(ComputerPart& item);
	void increaseAvailability();
	void decreaseAvailability();
	void writeInBinary(std::ofstream& out);
	void setAvailability(size_t avalability);
};

#endif // !AVAILABLE_ITEMS_H

