#include <iostream>

int digCount(int num)
{
    int cnt = 0;
    while (num){
        num /= 10;
        cnt++;
    }

    return cnt;
}

char* toStr(int num)
{
    int digCnt = digCount(num);

    char *numStr = new char[digCnt + 1];

    for (int i = digCnt - 1; i >= 0; i--) {
        numStr[i] = 48 + (num % 10);
        num /= 10;
    }

    numStr[digCnt] = '\0';
    return numStr;
}

int main()
{
    int n = 12345;

    char *strNum = toStr(n);
    std::cout << strNum << '\n';

    delete[] strNum;

    return 0;
}