#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 1;
    int b = 2;

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    swap(a, b);
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}