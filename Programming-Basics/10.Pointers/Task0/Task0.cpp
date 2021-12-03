#include <iostream>

void swap(int *firstNum, int *secondNum)
{
    int temp = *firstNum;
    *firstNum = *secondNum;
    *secondNum = temp;
}

int main()
{
    int a, b;
    std::cout << "Enter a: ";

    std::cin >> a;

    std::cout << "Enter b: ";

    std::cin >> b;

    swap(&a, &b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}
