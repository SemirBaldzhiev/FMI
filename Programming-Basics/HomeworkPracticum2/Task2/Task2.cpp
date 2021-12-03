#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumber() 
{
	srand((unsigned int)time(NULL));

	int number = rand() % 9000 + 1000;

	return number;
}

bool isValid(int number)
{
	int arr[4];
	int count = 0;

	while (number)
	{
		int digit = number % 10;

		if (digit == 0)
		{
			return false;
		}

		arr[count] = digit;
		
		for (int i = 0; i < count; i++)
		{
			if (arr[i] == digit)
			{
				return false;
			}
		}

		count++;
		
		number /= 10;
	}
	return true;
}

int bullsCount(int inputNumArr[], int randNumArr[])
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (inputNumArr[i] == randNumArr[i])
		{
			count++;
		}
	}

	return count;
}

int cowsCount(int inputNumArr[], int randNumArr[])
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (inputNumArr[i] == randNumArr[j] && i != j)
			{
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int numberToGuess;
	int inputNumber;
	int divider = 1000;

	while (true)
	{
		numberToGuess = generateNumber();

		if (isValid(numberToGuess))
		{
			break;
		}
	}

	int randNumArr[4];

	for (int i = 0; i < 4; i++)
	{
		randNumArr[i] = numberToGuess / divider % 10;
		divider /= 10;
	}

	while (true)
	{
		divider = 1000;
		std::cout << "Enter four digit number without zeroes and repeating digits: ";
		std::cin >> inputNumber;

		if (inputNumber == numberToGuess)
		{
			break;
		}

		int numbers[4];
		for (int i = 0; i < 4; i++)
		{
			numbers[i] = inputNumber / divider % 10;
			divider /= 10;
		}

		int bullCount = bullsCount(numbers, randNumArr);
		int cowCount = cowsCount(numbers, randNumArr);

		std::cout << "Bulls: " << bullCount << " Cows: " << cowCount << std::endl;
	}

	std::cout << "Congratulations! You found the number : " << numberToGuess << std::endl;

	return 0;
}