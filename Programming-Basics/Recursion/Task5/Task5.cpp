#include <iostream>

void swapcase(char* str)
{

    if (*str == '\0')
    {
        return;
    }

    if (*str >= 'a' && *str <= 'z')
    {
        *str = *str - ('a' - 'A');
    }
    else if (*str >= 'A' && *str <= 'Z')
    {
        *str = *str + ('a' - 'A');
    }

    swapcase(str+1);
}

int main()
{
    char str[] = "aBcDfG123";
    swapcase(str);

    std::cout << str << std::endl;
    return 0;
}