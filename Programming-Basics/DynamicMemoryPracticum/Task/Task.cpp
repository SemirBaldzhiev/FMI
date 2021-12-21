#include <iostream>



int* changeArray(int *arr, int n) 
{
    int* newArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            newArray[i] = arr[i] / 2;
        }
        else 
        {
            newArray[i] = arr[i] * 3;
        }

    }

    return newArray;
    
}

int main()
{
    int n = 5;

    int* numbers = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

   int *newArr = changeArray(numbers, n);

   for (int i = 0; i < n; i++)
   {
       std::cout << newArr[i] << " ";
   }
  
   delete[] numbers;
   delete[] newArr;

    return 0;
}