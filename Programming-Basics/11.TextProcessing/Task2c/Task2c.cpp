#include <iostream>

void remove(char* str, char sym)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == sym)
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[i] = str[j];
            }
        }
    }
}

int main()
{
    char inputStr[256];
    char symbol;

    std::cin.getline(inputStr, 256);
    std::cin >> symbol;

    remove(inputStr, symbol);

    std::cout << inputStr << std::endl;
}