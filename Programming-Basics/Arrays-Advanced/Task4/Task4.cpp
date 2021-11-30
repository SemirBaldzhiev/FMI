#include <iostream>

void printSumMatrix(int matrixA[][32], int matrixB[][32], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrixA[i][j] + matrixB[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}

void printNegativeMatrix(int matrix[][32], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] * (-1) << ' ';
        }

        std::cout << std::endl;
    }
}

void print2APlus3BMatrix(int firstMatrix[][32] , int secondMatrix[][32], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << 2 * firstMatrix[i][j] + 3 * secondMatrix[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}
int main()
{
    int n;

    std::cin >> n;

    int matrixA[32][32];
    int matrixB[32][32];
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrixA[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrixB[i][j];
        }
    }

    printSumMatrix(matrixA, matrixB, n);
    printNegativeMatrix(matrixA, n);
    print2APlus3BMatrix(matrixA, matrixB, n);
    
    return 0;
}