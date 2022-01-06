#include <iostream>

void evaluate(const char* str, int countDigits, int countSmallLetters, int countCapitalLetters)
{
    if (*str == '\0')
    {
        std::cout << "Count small letters: " << countSmallLetters << std::endl;
        std::cout << "Count capital letters: " << countCapitalLetters << std::endl;
        std::cout << "Count digits: " << countDigits<< std::endl;

        return;
    }

    if (*str >= 'a' && *str <= 'z')
    {
        countSmallLetters++;
    }
    else if (*str >= 'A' && *str <= 'Z')
    {
        countCapitalLetters++;
    }
    else if (*str >= '0' && *str <= '9')
    {
        countDigits++;
    }

    evaluate(str + 1, countDigits, countSmallLetters, countCapitalLetters);
}

void evaluate(const char* str)
{
    evaluate(str, 0, 0, 0);
}

int main()
{
    char str[64];

    std::cin.getline(str, 64);

    evaluate(str);

    return 0;
}