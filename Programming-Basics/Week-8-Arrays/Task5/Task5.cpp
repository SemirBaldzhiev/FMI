#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int length = 1;
    int maxLength = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            length++;
        }
        else 
        {
            length = 1;
        }

        if (length > maxLength)
        {
            maxLength = length;
        }
    }

    std::cout << maxLength;

    return 0;
}