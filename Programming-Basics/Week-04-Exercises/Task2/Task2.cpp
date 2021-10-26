#include <iostream>

int main()
{
    int n;

    std::cin >> n;

	int digitProduct = 1;
	int digitSum = 0;

	while (n != 0)
	{
		digitProduct *= n % 10;
		digitSum += n % 10;
		n /= 10;
	}

	if (digitProduct > 99 && digitProduct < 1000)
	{
		std::cout << "YES " << digitProduct - digitSum << std::endl;
	}
	else 
	{
		std::cout << "NO " << digitProduct << std::endl;
	}

	return 0;

}
