#include <iostream>

bool isPalindrome(char *str) 
{
	int length = 0;
	bool isPalindrome = true;

	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;
	}

	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			isPalindrome = false;
			break;
		}
	}

	return isPalindrome;
}

int main()
{
    char inputStr[256];

    std::cin.getline(inputStr, 256); 	//itopinonavevanonipoti

	std::cout << std::boolalpha << isPalindrome(inputStr) << std::endl;
}
