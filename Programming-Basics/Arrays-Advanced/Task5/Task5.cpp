#include <iostream>

void printSumOfRows(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }

        std::cout << "Row " << i << " Sum: " << sum << std::endl;
        sum = 0;
    }
}

void printSumOfColumns(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += matrix[j][i];
        }

        std::cout << "Column " << i << " Sum: " << sum << std::endl;
        sum = 0;
    }
}

void printSumDiagonal(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }

    std::cout << "Diagonal sum: " << sum << std::endl;
}

void printSumUnderDiagonal(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += matrix[i][j];
        }
    }

    std::cout << "Under diagonal sum: " << sum << std::endl;
}

void printSumAboveDiagonal(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += matrix[i][j];
        }
    }

    std::cout << "Above diagonal sum: " << sum << std::endl;
}

void printSumSecondaryDiagonal(int matrix[][32], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][n - 1 - i];
    }

    std::cout << "Secondary diagonal sum: " << sum << std::endl;
}

int main()
{
    int n;
    int matrix[32][32];

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    printSumOfRows(matrix, n);
    printSumOfColumns(matrix, n);
    printSumDiagonal(matrix, n);
    printSumUnderDiagonal(matrix, n);
    printSumAboveDiagonal(matrix, n);
    printSumSecondaryDiagonal(matrix, n);

    return 0;
}
