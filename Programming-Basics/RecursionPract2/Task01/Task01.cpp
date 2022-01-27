#include <iostream>

int len(char* str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	return count;
}

void nameDiamondHelper(char* str, int index)
{
	if (index == len(str))
	{
		return;
	}

	for (int i = 0; i <= index; i++)
	{
		std::cout << str[i];
	}

	std::cout << std::endl;

	nameDiamondHelper(str, index + 1);

	for (int i = 0; i < len(str) - index; i++)
	{
		std::cout << ' ';
	}

	for (int i = len(str) - index; i < len(str); i++)
	{
		std::cout << str[i];
	}

	std::cout << std::endl;
}

void nameDiamond(char* str)
{
	nameDiamondHelper(str, 0);
}

int main()
{
	char str[256] = "CHRIS";

	nameDiamond(str);

	return 0;
}