#include <iostream>

int main()
{
    int n;

    std::cin >> n;

	int maxNegative = INT32_MIN;

	for (int i = 1; i < n; i++)
	{
		int number;
		std::cin >> number;

		if (number > maxNegative && number < 0)
		{
			maxNegative = number;
		}
	}

	std::cout << maxNegative;

	return 0;
}