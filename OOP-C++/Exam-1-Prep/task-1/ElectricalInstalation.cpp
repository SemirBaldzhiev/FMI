#include "ElectricalInstalation.h"
#include <cstdlib>

ElectricalInstalation::ElectricalInstalation() : capacity(0), devices(nullptr) { }

ElectricalInstalation::ElectricalInstalation(const size_t capacity) : capacity(capacity) {
	devices = new ElectricalDevice[capacity];
}

ElectricalInstalation::ElectricalInstalation(const ElectricalInstalation& other) {
	copy(other);
}

ElectricalInstalation& ElectricalInstalation::operator=(const ElectricalInstalation& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

ElectricalInstalation::~ElectricalInstalation() {
	clear();
}

size_t ElectricalInstalation::getCapacity() const {
	return capacity;
}

void ElectricalInstalation::addDevice(const ElectricalDevice& device)
{
}

void ElectricalInstalation::removeDevice(const char* modelName)
{
}

void ElectricalInstalation::copy(const ElectricalInstalation& other) {
	
	for (int i = 0; i < other.count; i++) {
		devices[i] = other.devices[i];
	}

	capacity = other.capacity;
}

void ElectricalInstalation::clear() {
	delete[] devices;
}
