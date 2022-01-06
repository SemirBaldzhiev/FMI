#include <iostream>



int recStrlen(const char* str, int i)
{
	if (str[i] == '\0')
	{
		return i;
	}

	recStrlen(str, i + 1);
}


int recStrlen(const char* str)
{
	return recStrlen(str, 0);
}

int main()
{

	const char* str = "abcdfg";

	std::cout << recStrlen(str) << std::endl;
    return 0;
}