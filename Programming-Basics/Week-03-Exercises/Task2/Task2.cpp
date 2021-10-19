#include <iostream>

int main()
{
    char letter;

    std::cin >> letter;

	if ((int)letter >= 97 && (int)letter <= 122)
	{
		std::cout << "The upper case character corresponding to " << letter << " is " << (char)(letter - 32) << std::endl;
	}
	else 
	{
		std::cout << "The lower case character corresponding to " << letter << " is " << (char)(letter + 32) << std::endl;
	}

	return 0;
}