#include <cstring>
#include "Pair.h"

Pair::Pair() : word_(nullptr), interpretation_(nullptr) { }

Pair::Pair(const Pair& other) {
	copy(other);
}

Pair& Pair::operator=(const Pair& other) {

	if (this != &other) {
		delete[] word_;
		delete[] interpretation_;
		copy(other);
	}

	return *this;
}

Pair::~Pair() {
	delete[] word_;
	delete[] interpretation_;
}


const char* Pair::getWord() const {
	return word_;
}

const char* Pair::getInterpretation() const{
	return interpretation_;
}

void Pair::setWord(const char* word) {
	delete[] word_;
	if (strlen(word) > 100){
		throw "Length is too large: " + strlen(word);
	}

	strcpy(word_, word);
}

void Pair::setInterpretation(const char* interpretation) {
	delete[] interpretation_;
	if (strlen(interpretation) > 500) {
		throw "Length is too large: " + strlen(interpretation);
	}
	strcpy(interpretation_, interpretation);
}

void Pair::copy(const Pair& other) {
	word_ = new char[strlen(other.word_) + 1];
	strcpy(word_, other.word_);

	interpretation_ = new char[strlen(other.interpretation_) + 1];
	strcpy(interpretation_, other.interpretation_);
}