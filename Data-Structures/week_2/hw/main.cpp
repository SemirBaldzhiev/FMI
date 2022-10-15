#include <iostream>
#include "LList.h"

int main() {

    LList<int> l1;

    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(6);
    l1.pushBack(6);
    l1.pushBack(6);

    std::cout << "first list size: " << l1.size() << '\n';
    std::cout << "count equals: " << l1.count(6) << '\n';


    LList<int> l2(1, 10);
    l2 += 11;
    l2 += 12;

    l2.append(l1);

    std::cout << "second list size: " << l2.size() << '\n';

    std::cout << "l2[0]: " << l2[0] << '\n';
    l2[0] = 100;
    std::cout << "l2[0]: " << l2[0] << '\n';

    l2 = l1;

    std::cout << "second list size: " << l2.size() << '\n';
    std::cout << "l2[0]: " << l2[0] << '\n';


    return 0;
}