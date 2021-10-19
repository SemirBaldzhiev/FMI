#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    //22.01.2006

    int day = n + 22;

    if (day > 31)
    {
        std::cout << day - 31 << ".02.2006" << std::endl;
    }
    else 
    {
        std::cout << day << ".01.2006" << std::endl;
    }



}
