#include <iostream>

int main()
{
    double price;

    std::cin >> price;

	int count1lv = 0;
	int count20 = 0;
	int count5 = 0;
	int count1 = 0;

	double currentSum = 0;

	price = round(price * 100.0) / 100.0;

	while (currentSum < price) //1 лв., 20 ст., 5 ст. и 1 ст
	{
		if (1 + currentSum <= price)
		{
			currentSum += 1;
			count1lv++;
		}
		else if (0.2 + currentSum <= price)
		{
			currentSum += 0.2;
			count20++;
		}
		else if (0.05 + currentSum <= price)
		{
			currentSum += 0.05;
			count5++;
		}
		else if (0.01 + currentSum <= price)
		{
			currentSum += 0.01;
			count1++;
		}

		std::cout << currentSum << std::endl;

	}

	std::cout << count1lv << " x 1 lv " << count20 << " x 20 st " << count5 << " x 5 st " << count1 << " x 1 st" << std::endl;
}
