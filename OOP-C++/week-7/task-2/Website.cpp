#include "Website.h"

#include <cstring>
#include <cstdlib>

Website::Website() : name(nullptr), urlAddress(nullptr), countVisits(0) { }

Website::Website(const Website& other) {
	copy(other);
}

Website& Website::operator=(const Website& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

Website::~Website() {
	clear();
}

void Website::visit() {
	countVisits++;
}

char* Website::getName() const {
	return name;
}

char* Website::getUrlAddress() const {
	return urlAddress;
}

size_t Website::getCountVisits() const {
	return countVisits;
}

void Website::setName(const char* name) {

	if (name != nullptr) {

		if (this->name != nullptr) {
			delete[] this->name;
		}

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

void Website::setUrlAddress(const char* urlAddress) {
	if (urlAddress != nullptr) {

		if (this->urlAddress != nullptr) {
			delete[] this->urlAddress;
		}

		this->urlAddress = new char[strlen(urlAddress) + 1];
		strcpy(this->urlAddress, urlAddress);
	}
}


void Website::copy(const Website& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	urlAddress = new char[strlen(other.urlAddress) + 1];
	strcpy(urlAddress, other.urlAddress);

	countVisits = other.countVisits;
}

void Website::clear() {
	delete[] name;
	delete[] urlAddress;
}