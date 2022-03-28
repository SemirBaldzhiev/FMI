#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h" 

class Company {
public: 
	Company();
	Company(const Company& other);
	~Company();

	void addEmployee(const Employee& newEmployee);
	const Employee& getMostPaid() const;
	void saveWorkers(const char* fileName);

private:
	Employee* employees;
	int count;
};

#endif // COMPANY_H
