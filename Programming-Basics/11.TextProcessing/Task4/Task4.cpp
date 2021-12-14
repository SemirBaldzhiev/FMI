#include <iostream>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }

    return b;
}

int len(char* arr)
{
    int length = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

int longestPrefix(char *firstStr, char *secondStr)
{
    int firstStrLength = len(firstStr);
    int secondStrLength = len(secondStr);

    int minLength = 0;

    int minLen = min(firstStrLength, secondStrLength);

    int count = 0;

    for (int i = 0; i < minLen; i++)
    {
        if (firstStr[i] != secondStr[i])
        {
            break;
        }

        count++;
    }

    return count;

}

int main()
{
    char inputStr1[256];
    char inputStr2[256];

    std::cin.getline(inputStr1, 256);
    std::cin.getline(inputStr2, 256);

    std::cout << longestPrefix(inputStr1, inputStr2) << std::endl;
}
