#include <iostream>

int valueOfRomanSymbol(char r)
{
    int value = 0;

    switch (r)
    {
        case 'I': value = 1; break;
        case 'V': value = 5; break;
        case 'X': value = 10; break;
        case 'L': value = 50; break;
        case 'C': value = 100; break;
        case 'D': value = 500; break;
        case 'M': value = 1000; break;
    }

    return value;
}

int romanToInteger(char* str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        int val1 = valueOfRomanSymbol(str[i]);

        if (str[i + 1] != '\0')
        {
            int val2 = valueOfRomanSymbol(str[i + 1]);

            if (val1 >= val2)
            {
                result += val1;
            }
            else
            {
                result += (val2 - val1);
                i++;
            }
        }
        else 
        {
            result += val1;
        }
    }

    return result;
}

bool isValidRomanNumber(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'I' 
            && str[i] != 'V' 
            && str[i] != 'X' 
            && str[i] != 'L' 
            && str[i] != 'C' 
            && str[i] != 'D' 
            && str[i] != 'M')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char romanNum[256];

    do
    {
        std::cout << "Enter roman number: ";
        std::cin >> romanNum;

    } while (!isValidRomanNumber(romanNum));
    

    std::cout << "Integer number is: " << romanToInteger(romanNum) << std::endl;

    return 0;
}