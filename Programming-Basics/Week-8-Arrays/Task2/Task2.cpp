#include <iostream>

int digitProduct(int num)
{
	int product = 1;

	if (num < 10)
	{
		return num;
	}

	while (num)
	{
		product *= (num % 10);
		num /= 10;
	}

	return product;
}

int main()
{
    const int n = 5;

    int arr[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (digitProduct(arr[i]) < 10)
		{
			count++;
		}
	}

	std::cout << count;

	return 0;
}