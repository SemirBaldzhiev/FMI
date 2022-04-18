#include "ComputerPart.h"
#ifndef COMPUTER_PART_WRITER_H
#define COMPUTER_PART_WRITER_H	

class ComputerPartWriter {
public:
	static void writePart(const ComputerPart& item, std::ofstream& out);
};

#endif
