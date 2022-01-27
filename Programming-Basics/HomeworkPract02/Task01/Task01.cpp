#include <iostream>

int len(char* str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    return length;
}

bool containsHelper(char ch, char* str)
{
    if (*str == '\0')
    {
        return (ch == *str - 1);
    }

    return (ch == *str) || containsHelper(ch, str + 1);
}

bool containsHelper2(char* str1, char* str2, int i)
{

    bool contains =  containsHelper(str1[i], str2);

    if (!contains)
    {
        return false;
    }

    if (i == len(str1) - 1)
    {
        return contains;
    }

    return containsHelper2(str1, str2, i + 1);
}

bool contains(char* str1, char* str2)
{
    return containsHelper2(str1, str2, 0);
}


int main()
{
    char firststr[256];
    char secondstr[256];

    std::cin.getline(firststr, 256);
    std::cin.getline(secondstr, 256);


    bool cont = contains(firststr, secondstr);

    if (cont)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;

    }

    return 0;
}