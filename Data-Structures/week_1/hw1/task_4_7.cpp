#include <iostream>

void reverse(int n)
{
    int num;
    if (n == 0) {
        return;
    }

    std::cin >> num;
    reverse(n - 1);
    std::cout << num << '\n';
}

int main() 
{
    int n = 3;
    reverse(n);

    return 0;
}