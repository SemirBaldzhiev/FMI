#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    int fib0 = 0;
    int fib1 = 1;

    int nextFib = 0;

    if (n == 0)
    {
        std::cout << 0 << std::endl;
    }
    else 
    {
        for (int i = 2; i <= n; i++)
        {
            nextFib = fib0 + fib1;
            fib0 = fib1;
            fib1 = nextFib;
        }

        std::cout << fib1 << std::endl;
    }

    return 0;
}