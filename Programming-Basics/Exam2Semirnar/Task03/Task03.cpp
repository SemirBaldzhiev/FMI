#include <iostream>

int len(char* str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

char* concat(char str1[], char str2[], int k)
{
    char resultStr[30];

    int length = len(str1);

    for (int i = 0; i < length - k; i++)
    {
        resultStr[i] = str1[i];
    }

    for (int i = 0; i < k; i++)
    {
        resultStr[length - k + i] = str2[i];
    }

    resultStr[length] = '\0';

    return resultStr;
}

int main()
{
    int k;

    std::cin >> k;

    char* firstStr = new char[15];
    char* secondStr = new char[15];


    std::cin >> firstStr;
    std::cin >> secondStr;

    char* str = concat(firstStr, secondStr, k);

    int lenStr = len(str);

    for (int i = 0; i < len(str); i++)
    {
        std::cout << str[i];
    }
    return 0;
}