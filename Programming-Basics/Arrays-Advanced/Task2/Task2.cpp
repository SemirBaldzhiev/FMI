#include <iostream>

int main()
{
    int n;
    int m;

    int matrix[32][32];

    std::cin >> n >> m;

    int min;
    int max;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    
    max = matrix[0][0];
    min = matrix[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
            else if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;

    return 0;
}