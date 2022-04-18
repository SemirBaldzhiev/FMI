#ifndef COMPUTER_PART_READER_H
#define COMPUTER_PART_READER_H

#include "ComputerPart.h"

class ComputerPartReader {
public:
	static ComputerPart& readPart(std::ifstream& in);
};

#endif // !COMPUTER_PART_READER_H

