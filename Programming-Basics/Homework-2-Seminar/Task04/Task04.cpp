#include <iostream>

bool compareArrays(int arr1[], int arr2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}

	return true;
}

bool areEqualSequences(int** matrix, int n)
{
	for (int i = 0; i < (n - 1) / 2 ; i++)
	{	
		int firstArr[64];
		int secondArr[64];
		int trirdArr[64];
		int fourthArr[64];

		int index = 0;

		for (int j = i + 1; j < n - i - 1; j++)
		{
			firstArr[index] = matrix[i][j];
			secondArr[index] = matrix[n - i - 1][j];
			trirdArr[index] = matrix[j][i];
			fourthArr[index] = matrix[j][n - i - 1];
			index++;
		}

		int size = n - (2 * (i + 1));

		bool isAllEuqal = compareArrays(firstArr, secondArr, size) 
						&& compareArrays(firstArr, trirdArr, size)
						&& compareArrays(firstArr, fourthArr, size);

		if (!isAllEuqal)
		{
			return false;
		}

	}

	return true;
}


int main()
{
	int n;

	std::cin >> n;

	int** matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	std::cout << std::boolalpha << areEqualSequences(matrix, n) << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

    return 0;
}