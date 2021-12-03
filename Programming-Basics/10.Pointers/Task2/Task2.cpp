#include <iostream>

int sumElements(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void redirectPtr(int* first, int* second, int size, int* &ptr)
{
    int firstSum = sumElements(first, size);
    int secondSum = sumElements(second, size);

    std::cout << firstSum << std::endl;
    std::cout << secondSum << std::endl;


    if (firstSum < secondSum)
    {
        ptr = first;
    }
    else 
    {
        ptr = second;
    }
}

int main()
{
    int firstArr[32];
    int secondArr[32];

    int size;

    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        std::cin >> firstArr[i];
    }

    for (int i = 0; i < size; i++)
    {
        std::cin >> secondArr[i];
    }

    int* arrPtr = nullptr;

    redirectPtr(firstArr, secondArr, size, arrPtr);


    std::cout << firstArr << std::endl;
    std::cout << secondArr << std::endl;

    std::cout << std::endl;

    std::cout << arrPtr << std::endl;

    return 0;
}
