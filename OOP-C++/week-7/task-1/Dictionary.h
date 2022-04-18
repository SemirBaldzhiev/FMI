#include "Pair.h"
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>

const size_t MIN_CAPACITY = 4;

class Dictionary {
public:
	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);
	Dictionary(Dictionary&& other);
	Dictionary& operator=(Dictionary&& other);
	~Dictionary();

	void printPairs() const;
	void addPair(const Pair pair);
	bool contains(const char* word) const;

	friend std::ostream& operator<<(std::ostream& out,const Pair& pair);
	friend std::istream& operator>>(std::istream& out, Pair& pair);


private:
	void copy(const Dictionary& other);
	void resize(const size_t capacity);

private:
	Pair* pairs;
	size_t size;
	size_t capacity;
};

#endif // !DICTIONARY_H

