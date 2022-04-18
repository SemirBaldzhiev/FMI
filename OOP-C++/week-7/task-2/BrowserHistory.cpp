#include "BrowserHistory.h"

#include <cstring>
#include <cstdlib>

BrowserHistory::BrowserHistory() : size(0) { 
	history = new Website[20];
}

BrowserHistory::BrowserHistory(const BrowserHistory& other) {
	copy(other);
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

BrowserHistory::~BrowserHistory() {
	clear();
}

void BrowserHistory::addNewSiteToHistory(const Website& newWebsite) {
	history[size] = newWebsite;
	size++;
}

Website BrowserHistory::findURL(const char* name) {
	for (int i = 0; i < size; i++) {
		if (strcmp(history[i].getName(), name) == 0) {
			return history[i];
		}
	}
}

size_t BrowserHistory::getCountOfVisits(const char* name) {
	for (int i = 0; i < size; i++) {
		if (strcmp(history[i].getName(), name) == 0) {
			return history[i].getCountVisits();
		}
	}
}

void BrowserHistory::clearHistory() {
	clear();
	size = 0;
}

Website* BrowserHistory::getHistory() const {
	return history;
}

size_t BrowserHistory::getSize() const {
	return size;
}

void BrowserHistory::copy(const BrowserHistory& other) {
	history = new Website[other.size];
	
	for (int i = 0; i < other.size; i++) {
		history[i] = other.history[i];
	}

	size = other.size;
}

void BrowserHistory::clear() {
	delete[] history;
}