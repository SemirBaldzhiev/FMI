#include <iostream>

int main()
{
    int n;

    std::cin >> n;

    int arr[10];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    double avg = sum / n;

    std::cout << avg;

    return 0;
}
