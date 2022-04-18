#ifndef COMPUTER_PART_H
#define COMPUTER_PART_H

#include <fstream>

enum class Type {
	UNKNOWN = -1,
	MONITOR,
	COMPUTER,
	LAPTOP,
	MOUSE,
	KEYBOARD,
	HEADPHONES,
	CAMERA
};

class ComputerPart {
private:
	Type type;
	unsigned int yearsWarranty;
	double price;
	char* brand;
	char* model;

public:
	ComputerPart();
	ComputerPart(Type type, const char* brand, const char* model, const unsigned int yearsWarranty, const double price);
	ComputerPart(const ComputerPart& other);
	ComputerPart& operator=(const ComputerPart& other);
	~ComputerPart();

	const char* getTypeAsString() const;
	const Type getType() const;
	unsigned int getYearsWarranty() const;
	double getPrice() const;
	char* getBrand() const;
	char* getModel() const;

	

	void setPrice(const double newPrice);
	void setType(const Type type);
	void setBrand(const char* brand);
	void setModel(const char* model);
	void setYearsWarranty(const unsigned int year);

	bool operator==(const ComputerPart& item);

	bool operator!=(ComputerPart& item);

	void writePartBin(std::ofstream& out);

private:
	void copy(const ComputerPart& other);
	void destroy();
};

#endif // COMPUTER_PART_H

