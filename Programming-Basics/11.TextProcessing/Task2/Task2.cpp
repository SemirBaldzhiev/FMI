#include <iostream>

int countSymbols(char *str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	return count;
}

int main()
{
    char inputStr[256];

	std::cin.getline(inputStr, 256);

	std::cout << countSymbols(inputStr) << std::endl;

}