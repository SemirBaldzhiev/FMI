#include <iostream>

void getmax(long *pmax, size_t n)
{
    if (n == 0) {
        return;
    }
    int num;
    std::cin >> num;

    if (num > *pmax) {
        *pmax = num;
    }

    getmax(pmax, n - 1);
}

int main() 
{
    size_t n = 4;
    long max = -INT32_MAX;

    getmax(&max, n);
    std::cout << max << '\n';

    return 0;
}