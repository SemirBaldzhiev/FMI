#include <iostream>

template<typename Type>
unsigned indexMax(Type* arr, int size) {
    Type max = arr[0];
    unsigned index = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    return index;
}
template<typename Type>
unsigned indexMin(Type* arr, int size) {
    Type min = arr[0];
    unsigned index = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }

    return index;
}

template<typename Type>
void swap(Type& elem1, Type& elem2) {
    Type temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

template<typename Type>
Type* swapMaxMin(Type* arr, int size) {

    Type* newArr = new Type[size];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    unsigned maxIndex = indexMax(arr, size);
    unsigned minIndex = indexMin(arr, size);

    swap(newArr[maxIndex], newArr[minIndex]);

    return newArr;
}

int main()
{
    int size = 5;
    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = i+1;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    int* newArr = swapMaxMin(arr, size);
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    for (int i = 0; i < size; ++i) {
        std::cout  << newArr[i] << " ";
    }

    delete[] arr;
    delete[] newArr;
    return 0;
}