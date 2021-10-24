#include <iostream>

int main()
{
    char symbol;

    std::cin >> symbol;

	if ((int)symbol >= 48 && (int)symbol <= 57)
	{
		std::cout << symbol << " is a digit. " << symbol << " + 1 = " << (char)((int)symbol + 1) << std::endl;
	}
	else if ((int)symbol >= 97 && (int)symbol <= 122) 
	{
		std::cout << symbol << " is an lowercase letter. It transforms into " << (char)((int)symbol - 32) << std::endl;
	}
	else 
	{
		std::cout << symbol << " is an uppercase letter. It transforms into " << (char)((int)symbol + 32) << std::endl;
	}

	return 0;
}
