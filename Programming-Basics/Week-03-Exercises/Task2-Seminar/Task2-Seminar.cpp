#include <iostream>

int main()
{
	int age;
	int points = 0;

	std::cin >> age;

	if (age < 0)
	{
		std::cout << "Invalid age" << std::endl;
	}
	else 
	{
		if (age > 65)
		{
			points += 5000;
		}
		else if (age > 18)
		{
			points += 18 * 3 + (age - 18) * 5;
		}
		else
		{
			points += age * 3;
		}

		std::cout << points << std::endl;
	}

	return 0;
}

