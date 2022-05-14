#ifndef LAPTOP_H
#define LAPTOP_H

enum class OperationSystem {
	Unknown = -1,
	MacOS,
	Linux,
	Windows
};

class Laptop : public Device {
private:
	OperationSystem os;
	bool isUsb;
	int countPorts;
};

#endif // !LAPTOP_H
