#include <iostream>
#include "Employee.h"


int main()
{
    Employee emp;

    emp.setName("NameExample");
    emp.setAge(5);
    emp.setSalary(123);

    emp.print();

    return 0;
}