#include <iostream>
#include "JsonApp.h"

int main() {
    // g++ exceptions/*.h json-structure/src/*.cpp *.cpp 

    try {
        JsonApp app;
        app.run();
    }
    catch(std::exception& e){
        std::cout << e.what() << "\n";
    }
    
    return 0;
}