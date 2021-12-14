#include <iostream>


void concat(char *firstString, char *secondString)
{

    int firstStringLenght = 0;

    for (int i = 0; firstString[i] != '\0'; i++)
    {
        firstStringLenght++;
    }

    std::cout << firstStringLenght;

    for (int i = 0; secondString[i] != '\0'; i++)
    {
        firstString[firstStringLenght + i] = secondString[i];
    }
}


int main()
{
    char str1[512];
    char str2[256];

    std::cin.getline(str1, 512);
    std::cin.getline(str2, 256);

    concat(str1, str2);

    for (int i = 0; str1[i] != '\0'; i++)
    {
        std::cout << str1[i];
    }
}