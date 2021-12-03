#include <iostream>

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << ' ';
	}
}

void printReverse(int arr[], int size)
{
	/*for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + size - 1 - i) << ' ';
	}*/

	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << *(arr + i) << ' ';
	}
}

int main()
{
	int arr[32];

	int size;

	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	print(arr, size);
	std::cout << std::endl;
	printReverse(arr, size);
	
	return 0;
}