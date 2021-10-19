#include <iostream>

int main()
{
    double budget;
    int nightsCount;
    double price;
    double percent;

    std::cin >> budget >> nightsCount >> price >> percent;

    if (nightsCount > 7)
    {
        price -= price * 0.05;
    }

    double totalPrice = nightsCount * price;
    totalPrice += budget * (percent / 100);

    if (totalPrice <= budget)
    {
        std::cout << "Ivanovi will be left with " << budget - totalPrice << " leva after vacation." << std::endl;
    }
    else 
    {
        std::cout << totalPrice - budget << " leva needed." << std::endl;
    }


    return 0;
}
