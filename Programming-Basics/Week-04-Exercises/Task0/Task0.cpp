#include <iostream>

int main()
{
    int n;
    double a;

    std::cin >> a >> n;

    double result = 1;

    for (int i = 0; i < n; i++)
    {
        result *= a;
    }

    std::cout << result << std::endl;

    return 0;
}
