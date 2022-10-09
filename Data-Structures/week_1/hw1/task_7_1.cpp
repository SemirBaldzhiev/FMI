#include <iostream>
#include <cstring>

char* strduplicate(const char *str) 
{
    int strSize = strlen(str);
    char *retStr = new char[strSize + 1];

    for (int i = 0; i < strSize; i++) {
        retStr[i] = str[i];
    }

    retStr[strSize] = '\0';

    return retStr;
}

int main() 
{
    char str[] = "alabala"; 

    char *dupStr = strduplicate(str);
    std::cout << dupStr << '\n';
    delete[] dupStr;

    return 0;
}