#include "ComputerPart.h"
#include "ComputerPartWriter.h"

#include <fstream>
#include <iostream>


void ComputerPartWriter::writePart(const ComputerPart& item, std::ofstream& ofs) {
	
	if (!ofs.is_open()) {
		std::cout << "Cannot open file!";
		return;
	}

	ofs << "{" << item.getTypeAsString() << "|" << item.getBrand() << "|" << item.getModel() << "|" 
		<< item.getYearsWarranty() << "|" << item.getPrice() << "}\n";

	ofs.close();
}
