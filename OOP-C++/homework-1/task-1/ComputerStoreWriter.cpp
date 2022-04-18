#include "ComputerStoreWriter.h"
#include "ComputerPartWriter.h"


#include <exception>

void ComputerStoreWriter::writeStore(const ComputerStore& store, const char* fileName) {
	std::ofstream ofs;

	ofs.open(fileName, std::ios::app);

	if (!ofs.is_open()) {
		throw std::exception("Cannot open file");
	}

	ofs << store.getStoreName() << '\n' << store.getWorkingTime() << '\n' << store.getCountItems() << "\n[\n";

	for (int i = 0; i < store.getCountItems(); i++) {
		ofs << '\t';
		ComputerPartWriter::writePart(store.getItems()[i].getItem(), ofs);
	}

	ofs << ']\n' << store.turnoverReport();

}