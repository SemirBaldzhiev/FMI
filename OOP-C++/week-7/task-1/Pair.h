#ifndef PAIR_H
#define PAIR_H
class Pair {

public:
	Pair();
	Pair(const Pair& other);
	Pair& operator=(const Pair& other);
	~Pair();

	const char* getWord() const;
	const char* getInterpretation() const;

	void setWord(const char* word);
	void setInterpretation(const char* interpretation);


private:
	void copy(const Pair& other);

private:
	char* word_;
	char* interpretation_;
};


#endif // !PAIR_H

