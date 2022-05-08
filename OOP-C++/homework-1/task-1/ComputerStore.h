#include "ComputerPart.h"
#include <cstdlib>
#include "Item.h"


#ifndef COMPUTER_STORE_H
#define COMPUTER_STORE_H

class ComputerStore {
private:
	char* storeName;
	char* workingTime;
	//double turnover;
	Item* items;
	size_t countItems;
	size_t capacity;

	double currentTurnover;

public:
	ComputerStore();
	ComputerStore(const char* name, const char* workingTime, const size_t countItems, Item* items, const double money);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	void addItem(ComputerPart& item);
	void removeItem(const ComputerPart& item);
	const ComputerPart& searchByType(const char* type) const;
	const ComputerPart& searchByBrand(const char* brand) const;
	double turnoverReport() const;

	const size_t getCountItems() const;
	Item* getItems() const;
	const char* getStoreName() const;
	const char* getWorkingTime() const;

	void setStoreName(const char* name);
	void setWorkingTime(const char* time);
	void setTurnover(const double money);

private:
	void copy(const ComputerStore& other);
	void destroy();
	void resize();
	bool isDigit(char c);
};


#endif // !COMPUTER_STORE_H
