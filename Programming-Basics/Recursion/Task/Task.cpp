#include <iostream>

int sumOfDigits(int num)
{
	if (num == 0)
	{
		return num;
	}

	return num % 10 + sumOfDigits(num / 10);
}




int main()
{
	int number;

	std::cin >> number;

	std::cout << sumOfDigits(number) << std::endl;

	return 0;
}