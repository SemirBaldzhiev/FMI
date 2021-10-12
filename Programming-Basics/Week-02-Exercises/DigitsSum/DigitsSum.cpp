#include <iostream>

int main()
{
    int num;

    std::cin >> num;

    int firstDigit = num % 10;
    num /= 10;
    int secondDigit = num % 10;
    num /= 10;
    int thirdDigit = num % 10;

    std::cout << firstDigit + secondDigit + thirdDigit << std::endl;


}