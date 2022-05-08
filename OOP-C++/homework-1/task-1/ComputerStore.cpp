#include "ComputerStore.h"
#include <cstring>
#include <exception>

ComputerStore::ComputerStore() : countItems(0), capacity(4), currentTurnover(0), storeName(nullptr), workingTime(nullptr) {
	items = new Item[capacity];
}

ComputerStore::ComputerStore(const char* name, const char* workingTime, const size_t countItems, Item* items, const double money) {

	setStoreName(name);
	setWorkingTime(workingTime);
	setTurnover(money);
	this->countItems = countItems;
	for (int i = 0; i < countItems; i++) {
		this->items[i] = items[i];
	}

}

ComputerStore::ComputerStore(const ComputerStore& other) {
	copy(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other) {
	if (this != &other) {
		destroy();
		copy(other);
	}

	return *this;
}

ComputerStore::~ComputerStore() {
	destroy();
}


void ComputerStore::addItem(ComputerPart& item) {
	if (countItems >= capacity) {
		resize();
	}

	bool isNew = true;

	for (int i = 0; i < countItems; i++) {
		if (items[i].getItem() == item) {
			items[i].increaseAvailability();
			isNew = false;
		}
	}
	if (isNew) {

		items[countItems].setItem(item);
		items[countItems].increaseAvailability();
	}

	countItems++;
} 

void ComputerStore::removeItem(const ComputerPart& item) {

	for (int i = 0; i < countItems; i++) {
		if (items[i].getItem() == item) {
			
			currentTurnover += items[i].getItem().getPrice();
			items[i].decreaseAvailability();
			
			if (items[i].getAvailability() == 0) {
				
				for (int j = i + 1; j < countItems; j++) {
					items[j - 1] = items[j];
				}
			}
		}
	}
}

const ComputerPart& ComputerStore::searchByType(const char* type) const {
	
	if (type == "Unknown" || type == nullptr) {
		throw std::exception("Invalid type");
	}

	for (int i = 0; i < countItems; i++) {
		if (items[i].getItem().getTypeAsString() == type) {
			return items[i].getItem();
		}
	}
}
const ComputerPart& ComputerStore::searchByBrand(const char* model) const {

	for (int i = 0; i < countItems; i++) {
		if (items[i].getItem().getBrand() == model) {
			return items[i].getItem();
		}
	}
}

double ComputerStore::turnoverReport() const {
	return currentTurnover;
}

const size_t ComputerStore::getCountItems() const {
	return countItems;
}

Item* ComputerStore::getItems() const {
	return items;
}

const char* ComputerStore::getStoreName() const {
	return storeName;
}

const char* ComputerStore::getWorkingTime() const {
	return workingTime;
}

void ComputerStore::setStoreName(const char* name) {
	
	if (name == nullptr || strlen(name) >= 128) {
		throw std::exception("Store name is too large");
	}

	int sizeName = strlen(name) + 1;
	storeName = new char[sizeName];
	strcpy_s(storeName, sizeName, name);
}

void ComputerStore::setTurnover(const double money) {

	if (money <= 0) {
		throw std::exception("Turnover cannot be negative number");
	}

	currentTurnover = money;
}

void ComputerStore::setWorkingTime(const char* time) {
	if (time[2] != ':' || time[8] != ':' || time[5] != '-' || strlen(time) != 11) {
		throw std::exception("Invalid time format");
	}

	int digitsIndexes[] = { 0, 1, 3, 4, 6, 7, 9, 10};

	for (size_t i = 0; i < sizeof(digitsIndexes) / sizeof(int); i++)
	{
		if (isDigit(time[digitsIndexes[i]]) == false)
		{
			throw std::exception("Not a digit!");
		}
	}

	workingTime = new char[strlen(time) + 1];
	strcpy_s(workingTime, strlen(time) + 1, time);
}

bool ComputerStore::isDigit(char c) {
	return ('0' <= c && c <= '9');
}

void ComputerStore::copy(const ComputerStore& other) {
	storeName = new char[strlen(other.storeName) + 1];
	strcpy_s(storeName, strlen(other.storeName) + 1, other.storeName);

	workingTime = new char[strlen(other.workingTime) + 1];
	strcpy_s(workingTime, strlen(other.workingTime) + 1, other.workingTime);

	currentTurnover = other.currentTurnover;

	items = new Item[other.countItems];
	
	for (int i = 0; i < other.countItems; i++) {
		items[i] = other.items[i];
	}

	countItems = other.countItems;
}

void ComputerStore::destroy() {
	delete[] workingTime;
	delete[] items;
	delete[] storeName;
}
void ComputerStore::resize() {
	Item* newItems = new Item[capacity];

	for (int i = 0; i < countItems; i++) {
		newItems[i] = items[i];
	}

	delete[] items;
	items = newItems;
}