#ifndef PAIR_H
#define PAIR_H

#include <fstream>

class Pair {

public:
	Pair();
	Pair(const Pair& other);
	Pair& operator=(const Pair& other);
	Pair(Pair&& other);
	Pair& operator=(Pair&& other);
	~Pair();

	const char* getWord() const;
	const char* getInterpretation() const;

	void setWord(const char* word);
	void setInterpretation(const char* interpretation);
	friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
	friend std::istream& operator>>(std::istream& in, Pair& pair);

private:
	void copy(const Pair& other);

private:
	char* word_;
	char* interpretation_;
};


#endif // !PAIR_H

