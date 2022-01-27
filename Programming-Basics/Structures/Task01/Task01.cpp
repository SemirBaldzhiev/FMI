#include <iostream>
#include <cstring>

struct Product
{
public:
    char description[33];
    int partNum;
    double cost;

    Product() {
        setDescription("");
        partNum = 1;
        cost = 52.33;//https://www.youtube.com/watch?v=DvKf0yk4_xE :)
    }

    Product(const char* _desc, const int _partNum, const double _cost)
    {
        setDescription(_desc);
        partNum = _partNum;
        cost = _cost;
    }

    void setDescription(const char desc[])
    {
        int length = strlen(desc);

        if (length > 32)
        {
            std::cout << "Array is too large" << std::endl;
            return;
        }

        for (int i = 0; desc[i] != '\0'; i++)
        {
            description[i] = desc[i];
        }

        description[length] = '\0';
    }

    void print()
    {
        std::cout << "Description: " << description << std::endl;
        std::cout << "Part num: " << partNum << std::endl;
        std::cout << "Price: " << cost << std::endl;
    }
};


int main()
{
    Product product1;
    Product product2;

    product1.setDescription("screwdriver");
    product1.partNum = 456;
    product1.cost = 5.50;

    std::cout << "Product1: " << std::endl;
    product1.print();

    product2.setDescription("hammer");
    product2.partNum = 324;
    product2.cost = 8.2;

    std::cout << "Product2: " << std::endl;
    product2.print();

    Product products[5];

    char desc[32];

    for (int i = 0; i < 5; i++)
    {
        std::cin >> desc;
        products[i].setDescription(desc);
        std::cin >> products[i].cost;
        std::cin >> products[i].partNum;
    }

    for (int i = 0; i < 5; i++)
    {
        products[i].print();
    }

    return 0;
}







