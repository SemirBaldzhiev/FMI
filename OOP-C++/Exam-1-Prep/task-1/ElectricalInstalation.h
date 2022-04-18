#ifndef ELECTRICAL_INSTALATION_H
#define	ELECTRICAL_INSTALATION_H

#include <cstdlib>
#include "ElectricalDevice.h"

class ElectricalInstalation {
private:
	ElectricalDevice* devices;
	size_t capacity;
	size_t count;

public:
	ElectricalInstalation();
	ElectricalInstalation(const size_t capacity);
	ElectricalInstalation(const ElectricalInstalation& other);
	ElectricalInstalation& operator=(const ElectricalInstalation& other);
	~ElectricalInstalation();

	size_t getCapacity() const;

	void addDevice(const ElectricalDevice& device);
	void removeDevice(const char* modelName);

private :
	void copy(const ElectricalInstalation& other);
	void clear();

};

#endif // !ELECTRICAL_INSTALATION_H

