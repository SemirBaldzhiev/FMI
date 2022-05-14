#include "Manager.h"

Manager::Manager(const char* name, const unsigned int months, unsigned int countEmployees) {
	setName(name);
	setMonths(months);
	this->countEmployees = countEmployees;
}

Employee* Manager::clone() {
	return new Manager(*this);
}
