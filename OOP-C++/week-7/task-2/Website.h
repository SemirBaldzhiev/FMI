#ifndef WEBSITE_H
#define WEBSITE_H

#include <cstdlib>

class Website {
private:
	char* name;
	char* urlAddress;
	size_t countVisits;

public:
	Website();
	Website(const Website& other);
	Website& operator=(const Website& other);
	~Website();

	void visit();

	char* getName() const;
	char* getUrlAddress() const;
	size_t getCountVisits() const;

	void setName(const char* name);
	void setUrlAddress(const char* urlAddress);
	// void setCountVisits(const size_t countVisits);

private:
	void copy(const Website& other);
	void clear();
};

#endif // !WEBSITE_H

