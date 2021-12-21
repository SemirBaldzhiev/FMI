#include <iostream>

int getLen(char* string)
{
    int len = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        len++;
    }

    return len;
}

char* concat(char* firstStr, char* secondStr) //asdsad   asdf 
{
    int firstStrLen = getLen(firstStr);
    int secondStrLen = getLen(secondStr);

    char* newStr = new char[firstStrLen + secondStrLen + 1];

    for (int i = 0; i < firstStrLen; i++)
    {
        newStr[i] = firstStr[i];
    }

    for (int i = 0; i < secondStrLen; i++)
    {
        newStr[firstStrLen + i] = secondStr[i];
    }

    newStr[firstStrLen + secondStrLen] = '\0';

    return newStr;
}

int main()
{
    char firstString[64];
    char secondString[64];

    std::cin.getline(firstString, 64);
    std::cin.getline(secondString, 64);

    char* concatString = concat(firstString, secondString);

    for (int i = 0; concatString[i] != '\0'; i++)
    {
        std::cout << concatString[i];
    }

    delete[] concatString;

    return 0;
}
