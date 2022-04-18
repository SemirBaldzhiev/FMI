#include "Configuration.h"
#include "Item.h"
#include <cstdlib>


Configuration::Configuration() : count(0), computerConfiguration(nullptr) {}

Configuration::Configuration(const Item* computerConfig, const size_t count) {
	
	if (computerConfiguration == nullptr) {
		computerConfiguration = new Item[count];
	}

	for (int i = 0; i < count; i++) {
		computerConfiguration[i] = computerConfig[i];
	}

	this->count = count;
}

Configuration::Configuration(const Configuration& other) {
	copy(other);
}

Configuration& Configuration::operator=(const Configuration& other) {

	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

Configuration::~Configuration() {
	destroy();
}

const size_t Configuration::getCount() const {
	return count;
}

Item* Configuration::getComputerConfiguration() const {
	return computerConfiguration;
}

void Configuration::copy(const Configuration& other) {
	
	for (int i = 0; i < other.count; i++) {
		computerConfiguration[i] = other.computerConfiguration[i];
	}
	count = other.count;
}

void Configuration::destroy() {
	delete[] computerConfiguration;
}
