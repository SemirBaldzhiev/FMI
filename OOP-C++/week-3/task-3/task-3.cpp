#include <iostream>
#include <fstream>

const unsigned int MAX_SIZE = 256;

bool copyContent(const char sourceFilePath[], const char newFilePath[]) {
    std::ifstream in;
    std::ofstream out;
    
    in.open(sourceFilePath);
    out.open(newFilePath);

    if (!in.is_open() || !out.is_open()) {
        std::cout << "Cannot open file!" << std::endl;
        return false;
    }


    while (!in.eof()) {
        char buffer[MAX_SIZE];
        in.getline(buffer, MAX_SIZE);
        out << buffer << std::endl;
    }

    in.close();
    out.close();

    return true;
}


int main()
{
   
    bool isSuccessful = copyContent("task-3.cpp", "copy.txt");

    return 0;
}
