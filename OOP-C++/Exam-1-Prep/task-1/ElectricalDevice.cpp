#include "ElectricalDevice.h"
#include <cstring>


ElectricalDevice::ElectricalDevice() : model(nullptr), brand(nullptr), dateOfValidWarranty(Date()), power(0) { }

ElectricalDevice::ElectricalDevice(const char* model, const char* brand, const Date& date, const int power) :
	dateOfValidWarranty(date), power(power) {

	setModel(model);
	setBrand(brand);
}

ElectricalDevice::ElectricalDevice(const ElectricalDevice& other) {
	copy(other);
}

ElectricalDevice& ElectricalDevice::operator=(const ElectricalDevice& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

ElectricalDevice::~ElectricalDevice() {
	clear();
}

char* ElectricalDevice::getModel() const {
	return model;
}

char* ElectricalDevice::getBrand() const {
	return brand;
}

int ElectricalDevice::getPower() const {
	return power;
}

const Date& ElectricalDevice::getDateOfValidWarranty() const {
	return dateOfValidWarranty;
}

void ElectricalDevice::setModel(const char* model) {

	if (model != nullptr) {

		if (this->model != nullptr) {
			delete[] this->model;
		}

		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
}

void ElectricalDevice::setBrand(const char* brand) {

	if (brand != nullptr) {

		if (this->brand != nullptr) {
			delete[] this->brand;
		}

		this->brand = new char[strlen(brand) + 1];
		strcpy(this->brand, brand);
	}
	
}

void ElectricalDevice::copy(const ElectricalDevice& other) {
	model = new char[strlen(other.model) + 1];
	strcpy(model, other.model);

	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);

	dateOfValidWarranty = other.dateOfValidWarranty;
}

void ElectricalDevice::clear() {
	delete[] model;
	delete[] brand;
}
