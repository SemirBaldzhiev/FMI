#include <iostream>

int main()
{
    double x;
    double y;

    std::cin >> x >> y;

    int radius = 2;

    double distance = sqrt(x * x + y * y);

    bool isInFigure = (x > 0 && (distance <= 1 || distance >= radius)) || (x <= 0 && distance <= radius);
    
    if (isInFigure)
    {
        std::cout << "in figure";
    }
    else 
    {
        std::cout << "out of figure";
    }

    return 0;
}