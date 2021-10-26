#include <iostream>

int main()
{
    int number;

    std::cin >> number;
	bool isPrime = true;

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
	{
		std::cout << "Prime" << std::endl;
	}
	else 
	{
		std::cout << "Not Prime" << std::endl;
	}

	return 0;
}