#include <iostream>


int countDigits(int num)
{
    int count = 0;

    while (num != 0)
    {
        count++;
        num /= 10;
    }

    return count;
}   

char* dgitsAsChar(int number, int count)
{
    char* charArr = new char[count+1];

    for (int i = 0; i < count; i++)
    {
        charArr[i] = (char)(number % 10 + '0');
        number /= 10;
    }

    charArr[count] = '\0';

    return charArr;
}

int main()
{
    int number;

    std::cin >> number;

    int count = countDigits(number);

    char* string = dgitsAsChar(number, count);

    for (int i = 0; i < count; i++)
    {
        std::cout << string[i];
    }

    delete[] string;

    return 0;
}