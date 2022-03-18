#include <iostream>
#include <fstream>


void writeNumBinaryFile() {
  
    std::ofstream file;

    file.open("example.txt", std::ios::binary | std::ios::app);

    if (!file.is_open()) {
        std::cout << "Error!";
        return;
    }

    int n = 5;
    char symbol = 'c';

    file.write(reinterpret_cast<const char*>(&n), sizeof(n));
    file.write(reinterpret_cast<const char*>(&symbol), sizeof(symbol));

    file.close();
}


int main()
{



    return 0;
}
