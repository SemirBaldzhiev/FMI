#include <iostream>
#include <cmath>

int main()
{
    int n;

    std::cin >> n;
	int prev = 1;

	for (int i = 0; i < n; i++)
	{
		int num;

		std::cin >> num;

		//std::cout << std::pow(num, prev) << " ";
		int result = num;

		for (int j = 1; j < prev; j++)
		{
			result *= num;
		}

		std::cout << result << " ";

		prev = num;
	}

	return 0;
}
