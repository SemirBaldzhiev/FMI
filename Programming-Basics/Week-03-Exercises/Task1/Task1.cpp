#include <iostream>

int main()
{
	int age;

	std::cin >> age;

	if (age >= 18)
	{
		std::cout << "Can elect" << std::endl;
	}
	else 
	{
		std::cout << "Cannot elect" << std::endl;
	}

	return 0;
}
