#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "ComputerPart.h"
#include "Item.h"

#include <cstdlib>

class Configuration {
private:
	Item* computerConfiguration;
	size_t count;

public:
	Configuration();
	Configuration(const Item* computerConfig, const size_t count);
	Configuration(const Configuration& other);
	Configuration& operator=(const Configuration& other);
	~Configuration();

	const size_t getCount() const;
	Item* getComputerConfiguration() const;




private:
	void copy(const Configuration& other);
	void destroy();

};

#endif // !CONFIGURATION_H
