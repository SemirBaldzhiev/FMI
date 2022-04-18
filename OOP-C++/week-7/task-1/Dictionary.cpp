#include "Dictionary.h"

#include <iostream>
#include <cstring>

Dictionary::Dictionary() : size(0), capacity(4) {
	pairs = new Pair[capacity];
}

Dictionary::Dictionary(const Dictionary& other) {
	copy(other);
}

Dictionary& Dictionary::operator=(const Dictionary& other) {
	if (this != &other) {
		delete[] pairs;
		copy(other);
	}

	return *this;
}

Dictionary::Dictionary(Dictionary&& other) {
	pairs = other.pairs;
	other.pairs = nullptr;
}

Dictionary& Dictionary::operator=(Dictionary&& other) {
	if (this != &other) {
		delete[] pairs;
		pairs = other.pairs;
		other.pairs = nullptr;
	}

	return *this;
}
 
Dictionary::~Dictionary() {
	delete[] pairs;
}

void Dictionary::printPairs() const{
	for (int i = 0; i < size; i++) {
		std::cout << "(" << pairs[i].getWord() << ", " << pairs[i].getInterpretation() << ")" << std::endl;
	}
}

void Dictionary::addPair(const Pair pair) {
	if (size >= capacity) {
		capacity *= 2;
		resize(capacity);
	}
	
	pairs[size] = pair;
}

bool Dictionary::contains(const char* word) const {
	for (int i = 0; i < size; i++) {
		if (strcmp(pairs[i].getWord(), word) == 0) {
			return true;
		}
	}

	return false;
}

void Dictionary::resize(const size_t capacity) {
	
	Pair* newPairs = new Pair[capacity];

	for (int i = 0; i < size; i++) {
		newPairs[i] = pairs[i];
	}

	delete[] pairs;
	pairs = newPairs;
}

void Dictionary::copy(const Dictionary& other) {
	pairs = new Pair[other.capacity];

	for (int i = 0; i < other.size; i++) {
		pairs[i] = other.pairs[i];
	}

	size = other.size;
	capacity = other.capacity;
}
