#include <iostream>


int mult(int a, int b)
{
    if (a == 1)
    {
        return b;
    }
    else if (b == 1)
    {
        return a;
    }

    return a + mult(a, b - 1);
}


int main()
{
    int n, m;

    //std::cin >> n >> m;

    std::cout << mult(2, 9) << std::endl;

    return 0;
}