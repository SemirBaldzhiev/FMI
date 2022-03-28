#include <iostream>
#include "String.h"



int main()
{
    String str;

    str = "asd";

    String str2;

    str2 = "dasdsa";

    std::cout << (str == str2) << std::endl;


    return 0;
}