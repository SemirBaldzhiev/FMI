#include <iostream>

void replace(char* str, char firstSymbol, char secondSymbol)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == firstSymbol)
        {
            str[i] = secondSymbol;
        }
    }
}
int main()
{
    char inputStr[256];
    char firstSymbol, secondSymbol;

    std::cin.getline(inputStr, 256);

    std::cin >> firstSymbol >> secondSymbol;

    replace(inputStr, firstSymbol, secondSymbol);

    std::cout << inputStr;

}