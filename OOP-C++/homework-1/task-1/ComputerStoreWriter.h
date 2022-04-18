#ifndef COMPUTER_STORE_WRITER_H
#define COMPUTER_STORE_READER_H

#include "ComputerStore.h"

class ComputerStoreWriter {
public:
	static void writeStore(const ComputerStore& store, const char* fileName);
};

#endif // !COMPUTER_STORE_WRITER_H
