#ifndef COMPUTER_STORE_READER_H
#define COMPUTER_STORE_READER_H

#include "ComputerStore.h"

class ComputerStoreReader {
public:
	static ComputerStore readStore(const char* fileName);
};

#endif // !COMPUTER_STORE_READER_H

