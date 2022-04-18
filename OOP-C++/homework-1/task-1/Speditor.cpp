#include "Speditor.h"
#include "Date.h"

#include <exception>
#include <fstream>


Speditor::Speditor(const ComputerStore& store) {
	this->store = store;
}

void Speditor::processConfigurationOrder(const Configuration& config, Date date) {

	if (!containsAllConfigsInStore(config)) {
		throw std::exception("Cannot make this configuration.");
	}

	Item* configs = config.getComputerConfiguration();
	
	Item* storeItems = store.getItems();

	for (int i = 0; i < config.getCount(); i++) {

		for (int j = 0; j < store.getCountItems(); j++) {
			if (configs[i].getItem() == storeItems[j].getItem()) {
				store.removeItem(configs[i].getItem());
			}
		}
	}

	writeOrder(config, date);
}

bool Speditor::containsAllConfigsInStore(const Configuration& config) const {
	
	bool contains = false;

	for (int i = 0; i < config.getCount(); i++) {

		for (int j = 0; j < store.getCountItems(); j++) {
			if (config.getComputerConfiguration()[i].getItem() == store.getItems()[j].getItem()) {
				contains = true;
			}
		}

		if (contains == false) {
			return false;
		}

		contains = false;
	}

	return true;
}

void Speditor::writeOrder(const Configuration& config, Date date) {

	std::ofstream out;

	out.open(store.getStoreName(), std::ios::binary | std::ios::app);

	if (!out.is_open()) {
		throw std::exception("Cannot open file");
	}

	size_t count = config.getCount();
	out << date.getDay() << date.getMonth() << date.getYear();
	out.write(reinterpret_cast<const char*>(&count), sizeof(count));

	for (int i = 0; i < count; i++) {
		config.getComputerConfiguration()[i].writeInBinary(out);
	}

	out.close();
}
