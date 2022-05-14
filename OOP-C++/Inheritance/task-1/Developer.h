#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee { 
	
public:
	Developer(const char* name, const unsigned int months, bool knowCPlusPlus, bool knowCSharp);
	virtual Employee* clone() override; 

private:
	bool knowCPlusPlus;
	bool knowCSharp;
};

#endif // !DEVELOPER_h

