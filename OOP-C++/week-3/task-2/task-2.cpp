#include <iostream>
#include <fstream>

const unsigned int MAX_SIZE = 256;

int main()
{
    std::ifstream in;

    in.open("task-2.cpp");

    if (!in.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return -1;
    }
        

    while (!in.eof()) {
        char buffer[MAX_SIZE];
        in.getline(buffer, MAX_SIZE);
        std::cout << buffer << std::endl;
    }

    in.close();

    return 0;
}