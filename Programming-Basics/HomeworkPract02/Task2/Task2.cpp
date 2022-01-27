#include <iostream>


void decrypt(char* code, int n)
{
	if (*code == '\0')
	{
		return;
	}

	if ((int)(*code - n) < 65)
	{
		*code = (char)(65 + 65 - (int)(*code - n) + 24);
	}
	else 
	{
		*code = (char)(*code - (n % 26));
	}


	decrypt(code + 1, n);
}

int main()
{
	char code[256];
	int shiftCount;

	std::cin >> code;
	std::cin >> shiftCount;

	decrypt(code, shiftCount);

	std::cout << code << std::endl;

	return 0;
}