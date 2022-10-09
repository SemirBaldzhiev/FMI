#include <iostream>

#define ARRAY_SIZE 5

void swapArrElems(int *arr1, int *arr2)
{
    for (int i = 0; i < ARRAY_SIZE; i++){
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

int main()
{
    int arr1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int arr2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
    swapArrElems(arr1, arr2);
    std::cout << "arr1: "; 
    for (int i = 0; i < ARRAY_SIZE; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << '\n';
    std::cout << "arr2: ";
    for (int i = 0; i < ARRAY_SIZE; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << '\n';
    return 0;
}