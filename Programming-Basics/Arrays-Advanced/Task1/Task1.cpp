#include <iostream>

int main()
{
    int n;
    int m;

    int matrix[32][32];

    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] + 10 << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}