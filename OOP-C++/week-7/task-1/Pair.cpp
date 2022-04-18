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

Pair::Pair(Pair&& other) noexcept {
	word_ = other.word_;
	other.word_ = nullptr;
	interpretation_ = other.interpretation_;
	other.interpretation_ = nullptr;
}

Pair& Pair::operator=(Pair&& other) {
	if (this != &other) {
		delete[] word_;
		delete[] interpretation_;
		word_ = other.word_;
		other.word_ = nullptr;
		interpretation_ = other.interpretation_;
		other.interpretation_ = nullptr;
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

std::ostream& operator<<(std::ostream& out, const Pair& pair)
{
	out << "Word: " << pair.getWord() << "\n" << "Meaning: " << pair.getInterpretation() << "\n";
 
	return out;
}

std::istream& operator>>(std::istream& in, Pair& pair)
{
	char wordBuffer[1024];
	in.getline(wordBuffer, 1024);

	pair.word_ = new char[strlen(wordBuffer) + 1];
	strcpy(pair.word_, wordBuffer);
	
	char interpretationBuffer[1024];
	in.getline(interpretationBuffer, 1024);

	pair.interpretation_ = new char[strlen(interpretationBuffer) + 1];
	strcpy(pair.interpretation_, interpretationBuffer);

	return in;

}
