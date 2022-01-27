#include <iostream>
#include <cmath>

int countDigits(int num)
{
    int count = 0;

    while (num)
    {
        count++;
        num /= 10;
    }

    return count;
}

void fillStr(int num, char* numAsStr, int i)
{
    if (i == 0)
    {
        return;
    }

    numAsStr[i] = (num % 10) + '0';

    fillStr(num / 10, numAsStr, i - 1);
}

char* toStr(int num)
{
    int count = countDigits(num);
    char* str = new char[count + 1];

    fillStr(num, str, count - 1);

    str[count] = '\0';

    return str;
}
int main()
{
    int n = 1234;

    std::cout << toStr(n) << std::endl;

    return 0;
}