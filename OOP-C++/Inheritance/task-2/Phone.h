#ifndef PHONE_H
#define PHONE_H

#include "Device.h"

enum class SecurityLockType{
	Unknown = -1,
	Face,
	FingerPrint
};

class Phone : public Device {
private:
	int countCamera;
	SecurityLockType type;

};


#endif // !PHONE_H

