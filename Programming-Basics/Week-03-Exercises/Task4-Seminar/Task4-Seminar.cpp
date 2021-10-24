#include <iostream>

int main()
{
    int year;

    std::cin >> year;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		std::cout << "There is a meeting! (Leap year)" << std::endl;
	}
	else 
	{
		std::cout << "There is NO meeting! (Non-Leap year)" << std::endl;
	}

	return 0;
}
