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

int* createArray(int num, int count)
{
    int* arr = new int[count];

    for (int i = 0; i < count; i++)
    {
        arr[count - i - 1] = num % 10;
        num /= 10;
    }

    return arr;
}

int main()
{
    int number;

    std::cin >> number;

    int count = countDigits(number);

    int* arrayOfNums = createArray(number, count);

    for (int i = 0; i < count; i++)
    {
        std::cout << arrayOfNums[i] << " ";
    }

    delete[] arrayOfNums;

    return 0;
}