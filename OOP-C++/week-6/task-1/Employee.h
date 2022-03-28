#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

public: 
	Employee(const Employee& emp);
	Employee();
	~Employee();

	void setName(const char* name);
	char* getName() const;

	void setAge(const int age);
	int getAge() const;

	void setSalary(const int salary);
	int getSalary() const;
	Employee operator=(const Employee& emp);
	void print();
private:
	char* name;
	int age;
	int salary;
};


#endif // !EMPLOYEE_H


