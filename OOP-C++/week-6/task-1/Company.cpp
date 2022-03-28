#include "Company.h"

Company::Company() {
	employees = nullptr;
	count = 0;
}

Company::Company(const Company& other) {
	
}

Company::~Company() {
	delete[] employees;
}

