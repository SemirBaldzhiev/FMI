#include <iostream>

void lettersCount(char *str, int *countLetters)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        countLetters[(int)str[i]]++;
    }
}


int main()
{
    char inputStr[256];

    int coutLetters[127];

    std::cin.getline(inputStr, 256);

    for (int i = 0; i < 127; i++)
    {
        coutLetters[i] = 0;
    }

    lettersCount(inputStr, coutLetters);

    for (int i = 0; i < 127; i++)
    {
        if (coutLetters[i] != 0)
        {
            std::cout << (char)i << " = " << coutLetters[i] << std::endl;
        }
    }
}