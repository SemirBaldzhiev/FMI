#include <iostream>


int countOperations(int* arr, int n)
{
    int countSteps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                countSteps++;
            }
        }
    }
      
    return countSteps;
}

void worstSorted(int** arrays, int n, int lengths[])
{
    int maxCount = INT_MIN;
    int worstIndex = 0;
    int maxArrSize = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        int size = lengths[i];
        int operationsCount = countOperations(arrays[i], size);

        if (maxCount == operationsCount)
        {
            if (maxArrSize < size)
            {
                maxArrSize = size;
                worstIndex = i;
            }
        }

        if (operationsCount > maxCount)
        {
            maxCount = operationsCount;
            worstIndex = i;
            maxArrSize = size;
        }
    }

    std::cout << "Worst sorted - ";
    for (int i = 0; i < maxArrSize; i++)
    {
       std::cout << arrays[worstIndex][i] << " ";
    }
}

void bestSorted(int** arrays, int n, int lengths[])
{
    int minCount = INT32_MAX;
    int bestIndex = 0;
    int maxArrSize = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        int size = lengths[i];
        int operationsCount = countOperations(arrays[i], size);

        if (minCount == operationsCount)
        {
            if (maxArrSize < size)
            {
                maxArrSize = size;
                bestIndex = i;
            }
        }

        if (operationsCount < minCount)
        {
            minCount = operationsCount;
            bestIndex = i;
            maxArrSize = size;
        }
    }

    std::cout << "Best sorted - ";
    for (int i = 0; i < maxArrSize; i++)
    {
        std::cout << arrays[bestIndex][i] << " ";
    }
}

int main()
{
    int n;

    std::cout << "Enter arrays count: ";
    std::cin >> n;

    int* arrays[256];
    int lengths[256];

    for (int i = 0; i < n; i++)
    {
        int arrSize;

        std::cout << "Enter size of array (>= 3): ";
        std::cin >> arrSize;

        lengths[i] = arrSize;

        int* arr = new int[arrSize];

        for (int j = 0; j < arrSize; j++)
        {
            std::cin >> arr[j];
        }

        arrays[i] = arr;
    }

    bestSorted(arrays, n, lengths);
    std::cout << std::endl;
    worstSorted(arrays, n, lengths);


    for (int i = 0; i < n; i++)
    {
        delete[] arrays[i];
    }

    return 0;
}