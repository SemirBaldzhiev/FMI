#include <iostream>

int main()
{
    int n;
    int m;
    
    int x;

    int matrix[32][32];

    std::cin >> n >> m >> x;

    int row = 0;
    int col = 0;

    bool found = false;
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];

            if (matrix[i][j] == x && !found)
            {
                row = i;
                col = j;
                found = true;
            }
        }
    }

    (found) ? (std::cout << '[' << row << ", " << col << "] = " << matrix[row][col] * 10 << std::endl) 
        : (std::cout << x << " doesn't exist in the matrix\n");

    return 0;
}