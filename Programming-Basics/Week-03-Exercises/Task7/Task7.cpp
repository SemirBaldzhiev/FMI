#include <iostream>

int main()
{
    double degreeF;
    char type;

    std::cin >> degreeF >> type;

    double degreeC = (degreeF - 32) * 5 / 9;
    double degreeK = degreeC + 273.15;
         

    if (type == 'k')
    {
        std::cout << "Kelvin: " << degreeK << std::endl;
    }
    else if (type == 'c') 
    {
        std::cout << "Celsium: " << degreeC << std::endl;
    }
    else if (type == 'a')
    {
        std::cout << "Celsium: " << degreeC << std::endl;
        std::cout << "Kelvin: " << degreeK << std::endl;
    }

    return 0;
}
