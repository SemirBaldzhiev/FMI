#include <iostream>

void readRecursive(int* numbers, int size, int index)
{
	if (size == 0)
	{
		return;
	}

	int num;
	std::cin >> num;
	numbers[index] = num;

	readRecursive(numbers, size - 1, index + 1);
}

void read(int *numbers, int size)
{
	for (int i = 0; i < size; i++)
	{
		int num;
		std::cin >> num;
		numbers[i] = num;
	}
}

int main()
{
	int arr[256];
	int n;
	std::cin >> n;

	read(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}

}