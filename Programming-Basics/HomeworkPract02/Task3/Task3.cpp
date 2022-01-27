#include <iostream>

bool isValidPosition(int n, int m, int row, int col)
{
    return (row >= 0 && row < n) && (col >= 0 && col < m);
}

bool checkNeighborCells(char** matrix, int row, int col, int n, int m)
{
    int count = 0;

    bool isValidLeft = isValidPosition(n, m, row, col - 1);
    bool isValidRight = isValidPosition(n, m, row, col + 1);
    bool isValidUp = isValidPosition(n, m, row - 1, col);
    bool isValidDown = isValidPosition(n, m, row + 1, col);

    if (isValidDown)
    {
        if (matrix[row + 1][col] == '4')
        {
            count++;
        }
    }
    if (isValidUp)
    {
        if (matrix[row - 1][col] == '4')
        {
            count++;
        }
    }

    if (isValidRight)
    {
        if (matrix[row][col + 1] == '4')
        {
            count++;
        }
    }
    if (isValidLeft)
    {
        if (matrix[row][col - 1] == '4')
        {
            count++;
        }
    }

    if (isValidDown && isValidRight)
    {
        if (matrix[row + 1][col + 1] == '4')
        {
            count++;
        }
    }

    if (isValidDown && isValidLeft)
    {
        if (matrix[row + 1][col - 1] == '4')
        {
            count++;
        }
    }

    if (isValidUp && isValidLeft)
    {
        if (matrix[row - 1][col - 1] == '4')
        {
            count++;
        }
    }
    if (isValidUp && isValidRight)
    {
        if (matrix[row - 1][col + 1] == '4')
        {
            count++;
        }
    }

    if (count >= 3)
    {
        return true;
    }

    return false;
}

int changeMatrix(char** matrix, int currentRow, int currentCol, int m, int n)
{
    if (currentCol >= m)
        return 0;

    if (currentRow >= n)
        return 1;

    if (matrix[currentRow][currentCol] >= '1' && matrix[currentRow][currentCol] <= '3')
    {
        matrix[currentRow][currentCol] = (char)(matrix[currentRow][currentCol] + 1);
    }
    else if (matrix[currentRow][currentCol] == '4')
    {
        bool haveNeighborsWith4 = checkNeighborCells(matrix, currentRow, currentCol, n, m);

        if (haveNeighborsWith4)
        {
            matrix[currentRow][currentCol] = (char)(matrix[currentRow][currentCol] - 1);
        }
    }

    if (changeMatrix(matrix, currentRow, currentCol + 1, m, n) == 1)
        return 1;

    return changeMatrix(matrix, currentRow + 1, 0, m, n);
}

void changeForest(char** matrix, int years, int m, int n)
{
    if (years == 0)
    {
        return;
    }

    changeMatrix(matrix, 0, 0, m, n);

    changeForest(matrix, years - 10, m, n);
}

void printMatrix(char** matrix, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;

    }
}

int main()
{
    int m;
    std::cout << "m = ";
    std::cin >> m;

    int n;
    std::cout << "n = ";
    std::cin >> n;

    char** matrix = new char* [n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new char[m];
    }

    std::cout << "Forest:" << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int years;
    std::cout << "Years = ";
    std::cin >> years;

    changeForest(matrix, years, m, n);
    printMatrix(matrix, m, n);

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}