#ifndef ELECTRICAL_DEVICE_H
#define ELECTRICAL_DEVICE_H

#include "Date.h"

class ElectricalDevice {
private:
	char* model;
	char* brand;
	Date dateOfValidWarranty;
	int power;

public:
	ElectricalDevice();
	ElectricalDevice(const char* model, const char* brand, const Date& date, const int power);
	ElectricalDevice(const ElectricalDevice& other);
	ElectricalDevice& operator=(const ElectricalDevice& other);
	~ElectricalDevice();

	char* getModel() const;
	char* getBrand() const;
	int getPower() const;
	const Date& getDateOfValidWarranty() const;

	void setModel(const char* model);
	void setBrand(const char* brand);

private:
	void copy(const ElectricalDevice& other);
	void clear();
};


#endif // !ELECTRICAL_DEVICE_H

