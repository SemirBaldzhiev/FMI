#include <iostream>
#include <cstring>

void setBit(uint32_t *mask, int bit)
{
    *mask |= (1 << bit);
}

int checkBit(uint32_t *mask, int bit){
    return !!(*mask & (1 << bit));
}

char* unionStr(const char *str1, const char *str2)
{
    size_t size1 = strlen(str1);
    size_t size2 = strlen(str2);

    char *retStr = new char[size1 + size2 + 1];
    
    uint32_t containsMask = 0;
    int bit = 0;
    int k = 0;

    for (int i = 0; i < size1; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z'){
            bit = 97 - str1[i];
        }
        else if (str1[i] >= 'A' && str1[i] <= 'Z') {
            bit = 65 - str1[i];
        }

        if (!checkBit(&containsMask, bit)){
            retStr[k++] = str1[i];
            setBit(&containsMask, bit);
        }
    }
    
    for (int i = 0; i < size2; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z'){
            bit = 97 - str2[i];
        }
        else if (str2[i] >= 'A' && str2[i] <= 'Z') {
            bit = 65 - str2[i];
        }

        if (!checkBit(&containsMask, bit)){
            retStr[k++] = str2[i];
            setBit(&containsMask, bit);
        }
    }

    retStr[k] = '\0';

    return retStr;
    
}

int main()
{

    char str1[] = "ala";
    char str2[] = "bala";
    char *res = unionStr(str1, str2);

    std::cout << res << '\n';
    delete[] res;

    return 0;
}