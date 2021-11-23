#include <iostream>

double sum(double arr[], int count)
{
	double sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	const int n = 5;

	double numbers[n];

    for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
	}

	double sumNums = sum(numbers, n);

	std::cout << sumNums;
}