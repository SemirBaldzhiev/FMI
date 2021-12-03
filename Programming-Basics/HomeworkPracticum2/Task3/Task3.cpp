#include <iostream>

int removeZeroes(int number)
{
    int newNumber = 0;

    while (number != 0)
    {
        if (number % 10 != 0)
        {
            newNumber *= 10;
            newNumber += number % 10;
        }

        number /= 10;
    }

    return newNumber;
}

bool isMagicDate(int date, int weight)
{
    int numbers[10];

    int dateWithoutZeroes = removeZeroes(date);

    int count = 0;

    while (dateWithoutZeroes != 0)
    {
        numbers[count] = dateWithoutZeroes % 10;
        dateWithoutZeroes /= 10;
        count++;
    }

    int sumWeight = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            sumWeight += (numbers[i] * numbers[j]);
        }
    }

    if (sumWeight == weight)
    {
        return true;
    }

    return false;
}

bool isLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }

    return false;
}

int daysOfMonth(int month, int year)
{

    int days = 0;

    if (month == 2)
    {
        if (isLeapYear(year))
        {
            days =  29;
        }
        else
        {
            days = 28;
        }
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        days = 31;
    }
    else
    {
        days = 30;
    }
    
    return days;
}

int main()
{
    int startYear;
    int endYear;

    int weight;
    bool found = false;

    std::cin >> startYear >> endYear >> weight;

    for (int year = startYear; year <= endYear; year++)
    {
        for (int month = 1; month <= 12; month++)
        {
            int days = daysOfMonth(month, year);

            for (int day = 1; day <= days; day++)
            {

                int date = day * 1000000 + month * 10000 + year;

                if (isMagicDate(date, weight))
                {
                    found = true;

                    if (day < 10)
                    {
                        std::cout << '0' << day << '-';
                    }
                    else 
                    {
                        std::cout << day << '-';

                    }
                    
                    if (month < 10)
                    {
                        std::cout << '0' << month << '-';
                    }
                    else
                    {
                        std::cout << month << '-';

                    }
                    std::cout << year << std::endl;
                }

            }
        }
    }

    if (!found)
    {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}