#pragma warning (disable: 4996)

#include <cstring>
#include <iostream>

#include "Employee.h"

Employee::Employee() {
	name = nullptr;
	age = 0;
	salary = 0;
}

Employee::Employee(const Employee& emp) {
	setName(emp.name);
	setAge(emp.age);
	setSalary(emp.salary);
}

Employee::~Employee() {
	delete[] name;
}

void Employee::setName(const char* _name) {
	if (strlen(_name) >= 2) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
}

char* Employee::getName() const{
	return name;
}

void Employee::setAge(const int _age) {
	
	if (_age >= 0 && _age <= 100) {
		age = _age;
	}

}

int Employee::getAge() const {
	return age;
}

void Employee::setSalary(const int _salary) {
	
	if (_salary >= 0 && _salary < 1000000) {
		salary = _salary;
	}

}

int Employee::getSalary() const {
	return salary;
}

Employee Employee::operator=(const Employee& emp) {
	
	Employee newEmp;

	newEmp.setName(emp.name);
	newEmp.setAge(emp.age);
	newEmp.setSalary(emp.salary);

	return newEmp;
}

void Employee::print() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Salary: " << salary << std::endl;
}