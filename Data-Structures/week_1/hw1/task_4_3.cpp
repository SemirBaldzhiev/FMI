#include <iostream>

#define ARRAY_SIZE 4

bool duplicates(long *pointers[4]) 
{
    for (int i = 0; i < ARRAY_SIZE; i++){
        for (int j = 0; j < ARRAY_SIZE; j++){
            if (j != i && *pointers[i] == *pointers[j]){
                return true;
            }
        }
    }

    return false;
}

int main()
{
    long a1 = 12345;
    long a2 = 3213;
    long a3 = 423;
    long a4 = 12345;
    long *pointers[ARRAY_SIZE] = {&a1, &a2, &a3, &a4};

    bool res = duplicates(pointers);

    std::cout << std::boolalpha << res << '\n';
    return 0;
}

