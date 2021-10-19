#include <iostream>

int main()
{
    int number;

    std::cin >> number;

    int firstDigit = number % 10;
    number = number / 10;
    int secondDogit = number % 10;
    number /= 10;
    int thirdDigit = number;

    bool isEqual = firstDigit == secondDogit || secondDogit == thirdDigit || firstDigit == thirdDigit;

    std::cout << std::boolalpha << isEqual << std::endl;

    return 0;
}
