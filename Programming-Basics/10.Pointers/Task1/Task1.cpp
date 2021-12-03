#include <iostream>

int* elementInArr(int array[], int element, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (element == array[i])
		{
			return array + i;
		}
	}

	return nullptr;
}

int main()
{
	int arr[256];
	int element;
	int size;

	std::cin >> size;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> arr[i];
	}

	std::cin >> element;

	std::cout << elementInArr(arr, element, size) << std::endl;

	return 0;
}