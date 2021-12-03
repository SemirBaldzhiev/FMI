#include <iostream>
#include <cmath>

int main()
{
    int a;
    int b;

    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        bool found = false;

        for (int j = 1; j <= sqrt(i); j++)
        {
            for (int k = 1; k <= sqrt(i); k++)
            {
                if (j * j + k * k == i)
                {
                    std::cout << i << std::endl;    
                    found = true;
                    break;
                }
            }

            if (found)
            {
                break;
            }
        }
    }

    return 0;
}