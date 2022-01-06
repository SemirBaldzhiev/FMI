#include <iostream>


int len(char* str)
{
	int length = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}

bool areEqual(char* str1, char* str2, int index)
{
	if (index == len(str1) - 1)
	{
		return (str1[index] == str2[index]);
	}

	return (str1[index] == str2[index]) && areEqual(str1, str2, index + 1);
}


bool areEqual(char* str1, char* str2)
{
	if (len(str1) != len(str2))
	{
		return false;
	}

	return areEqual(str1, str2, 0);
}


int main()
{

	char str1[] = "abfg";
	char str2[] = "abfg";

	std::cout << std::boolalpha << areEqual(str1, str2) << std::endl;

    return 0;
}