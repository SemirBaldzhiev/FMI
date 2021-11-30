#include <iostream>

int main()
{
    int firstNum;
    int secondNum;
    int k;
     
    std::cin >> firstNum >> secondNum >> k;
 
    int count = 0;
    bool flag = true;

    for (int i = firstNum; i <= secondNum; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }

            if (count == k)
            {
                break;
            }
        }

        if (count != k)
        {
            flag = false;
            break;
        }

        count = 0;
    }

    if (flag)
    {
        std::cout << "Yes" << std::endl;
    }
    else 
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}