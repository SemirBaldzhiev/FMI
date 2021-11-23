#include <iostream>

int symbolCount(char str[], char symbol)
{
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == symbol)
		{
			count++;
		}
	}

	return count;
}

int main()
{
    char str[100];
	char symbol;

	std::cin >> str >> symbol;

	std::cout << symbolCount(str, symbol);
}
