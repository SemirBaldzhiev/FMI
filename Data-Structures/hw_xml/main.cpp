#include <iostream>
#include "App.h"

/**
  *            How to use
  * 
  * Run in terminal folowing commands:
  * make build - to compile all files and store them in './out' folder
  * make run - to run executable file
  * make clean - to remove all compile time files and executable
  * which are in './out' folder in your current directory
  * 
 */

int main() {

    App app;
    app.run();

    return 0;
}