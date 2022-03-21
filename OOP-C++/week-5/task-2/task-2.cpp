#include <iostream>
#include <cstring>


class String {

public:
    String() {
        size = 0;
        capacity = 8;
    }
    
    String(char* str) {
        strcpy(this->str, str);
    }

private:
    char* str;
    int size;
    int capacity;


};

int main()
{



    return 0;
}