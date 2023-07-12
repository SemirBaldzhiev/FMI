#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

int main() {
    
    std::ifstream ifs("test.txt");

    std::string name;
    std::string null;

    ifs >> name;
    ifs >> null;

    std::cout << "Name: " << name << '\n' << null << '\n';

    return 0;
}