#include <iostream>


int digitsCount(int num)
{
    int count = 1;

    while (num >= 10)
    {
        num /= 10;
        count *= 10;
    }

    return count;
}


int reverseNumHelper(int num, int i)
{
    
    if (num < 10)
    {
        return num * i;
    }

    return (num % 10) * i + reverseNumHelper(num / 10, i / 10);
}

int reverseNum(int num)
{
    int count = digitsCount(num);

    return reverseNumHelper(num, count);
}

int main()
{
    int number;

    std::cin >> number;

    std::cout << reverseNum(number) << std::endl;

    return 0;
}