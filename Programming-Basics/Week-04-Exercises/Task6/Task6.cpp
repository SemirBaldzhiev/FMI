#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    int sum = 0;

    while (num != 0) 
    {
        sum += num;
        std::cin >> num;
    }

    std::cout << sum << std::endl;

    return 0;
}
