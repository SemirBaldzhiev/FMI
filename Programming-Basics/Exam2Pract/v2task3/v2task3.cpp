#include <iostream>

void sequence(int n)
{
    if (n == 1)
    {
        std::cout << 1;
        return;
    }

    sequence(n - 1);

    std::cout << n;

    sequence(n - 1);
}

int main()
{
    int n;

    std::cin >> n;
    sequence(n);

    return 0;
}
