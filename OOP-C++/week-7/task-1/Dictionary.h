#include "Pair.h"
#ifndef DICTIONARY_H
#define DICTIONARY_H

const size_t MIN_CAPACITY = 4;

class Dictionary {
public:
	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);
	~Dictionary();

	void printPairs() const;
	void addPair(const Pair pair);
	bool contains(const char* word) const;


private:
	void copy(const Dictionary& other);
	void resize(const size_t capacity);

private:
	Pair* pairs;
	size_t size;
	size_t capacity;
};

#endif // !DICTIONARY_H

