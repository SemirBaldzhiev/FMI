#include <iostream>

int main()
{
    char inputText[100];

    std::cin >> inputText;

	int i = 0;

	while (inputText[i] != '\0')
	{
		if (inputText[i] >= 'a' && inputText[i] <= 'z')
		{
			inputText[i] = (char)(inputText[i] + 'A' - 'a');
		}
		else if (inputText[i] >= 'A' && inputText[i] <= 'Z')
		{
			inputText[i] = (char)(inputText[i] + 'a' - 'A');
		}

		i++;
	}

	std::cout << inputText;

	return 0;
}