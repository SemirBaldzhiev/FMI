#include <iostream>

bool haveOnlyLetters(char *str) 
{
    bool result = true;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 'a' || str[i] > 'z')
        {
            result = false;
            break;
        }
    }

    return result;
}

int main()
{
    char inputStr[256];

    std::cin.getline(inputStr, 256);

    std::cout << std::boolalpha << haveOnlyLetters(inputStr) << std::endl;
}