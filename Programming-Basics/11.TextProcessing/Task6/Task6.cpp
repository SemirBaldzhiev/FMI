#include <iostream>

bool containsDigits(char *str)
{
	bool contains = true;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			contains = false;
			break;
		}
	}

	return contains;
}

int len(char* arr)
{
	int length = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}

int convertToNum(char* str)
{
	int length = len(str);
	int num = 0;

	for (int i = 0; i < length; i++) //123
	{
		num *= 10;
		num += (int)(str[i] - '0');
	}

	return num;
}

int main()
{
    char inputStr[256];

    std::cin.getline(inputStr, 256);

	if (containsDigits(inputStr))
	{
		std::cout << convertToNum(inputStr) << std::endl;
	}
	else 
	{
		std::cout << -1 << std::endl; 
	}
}