#include <iostream>
#include <cmath>

int main()
{
    int x;
    int y;

    int c1;
    int c2;
    int r;

    std::cin >> x >> y >> c1 >> c2 >> r;

    int firstSide = abs(x - c1);
    int secondSide = abs(y - c2);

    int distance = sqrt(firstSide) + sqrt(secondSide);

    if (distance == r)
    {
        std::cout << "Point with coordinates " << "(" << x << ", " << y << ")" << " is on circle\n";
    }
    else
    {
        std::cout << "Not on circle\n";
    }

}
