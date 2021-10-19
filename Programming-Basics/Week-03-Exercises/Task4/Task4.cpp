#include <iostream>
#include <cmath>

int main()
{
    int n;

    std::cin >> n;

    bool check = (n % 3 == 0) || (n % 5 == 0) || (n % 7 == 0) && (n % 2 == 0);

    std::cout << std::boolalpha << check <<std::endl;

    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;

    bool check2 = (b * b - 4 * a * c) >= 0;

    std::cout << std::boolalpha << check2 << std::endl;

    int x, y;

    std::cin >> x >> y;

    double r = sqrt(x * x + y * y);

    bool check3 = r > 8 || r < 2;

    std::cout << std::boolalpha << check3 << std::endl;

    return 0;
}
