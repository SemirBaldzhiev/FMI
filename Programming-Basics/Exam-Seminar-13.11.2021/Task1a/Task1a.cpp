#include <iostream>

int main()
{
    int date;

    std::cin >> date; // 13112021 12021131  1122021

    int day = 0;
    int month = 0;
    int year = 0;

    int counter = 0;

    int reversedDate = 0;

    int digitCount = 0;

    while (date != 0)
    {
        reversedDate *= 10;
        reversedDate += date % 10;

        date /= 10;
        digitCount++;
    }

    while (reversedDate != 0)
    {
        if (digitCount == 8)
        {
            if (counter < 2)
            {
                day *= 10;
                day += reversedDate % 10;
            }
            else if (counter >= 2 && counter < 4)
            {
                month *= 10;
                month += reversedDate % 10;
            }
            else
            {
                year *= 10;
                year += reversedDate % 10;
            }
        }
        else 
        {
            if (counter < 1)
            {
                day *= 10;
                day += reversedDate % 10;
            }
            else if (counter >= 1 && counter < 3)
            {
                month *= 10;
                month += reversedDate % 10;
            }
            else
            {
                year *= 10;
                year += reversedDate % 10;
            }
        }
       

        reversedDate /= 10;
        counter++; 
    }

    bool isDayValid = (day > 0 && day <= 31 &&( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 11 || month == 12))
        || (day > 0 && day <= 30 && (month == 4 || month == 6 || month == 9 || month == 10)) || (day > 0 && day <= 28 && month == 2);
    
    bool isMonthValid = month > 0 && month <= 12;
    bool isValidYear = year >= 1900;

    if (isMonthValid && isDayValid && isValidYear)
    {
        std::cout << "Yes" << std::endl;
    }
    else 
    {
        std::cout << "No" << std::endl;
    }


    return 0;
}
