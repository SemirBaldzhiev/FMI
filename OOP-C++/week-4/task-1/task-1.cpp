#include <iostream>
#include <fstream>
#include <cstring>


struct JobAd {
    char firmName[25];
    int programmersCount;
    int vacationDaysCount;
    long long int salary;
};


void readRequests(int n) {

    std::ofstream ofs;

    ofs.open("requests.bin", std::ios::app | std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Error!";
        return;
    }

    for (int i = 0; i < n; i++) {
        
        JobAd ad;

        std::cout << "Firm Name: ";
        std::cin >> ad.firmName;

        std::cout << "Count Programmers: ";
        std::cin >> ad.programmersCount;

        std::cout << "Vacation Days Count: ";
        std::cin >> ad.vacationDaysCount;

        std::cout << "Salary: ";
        std::cin >> ad.salary;

        ofs.write((char*)&ad, sizeof(ad));
    }

    ofs.close();
}

void filterOffers(const char* filePath, long long int minSalary) {
    
    std::ifstream ifs;

    ifs.open(filePath, std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Error";
        return;
    }

    while (!ifs.eof()) {
        JobAd ad;
        ifs.read((char*)&ad, sizeof(ad));

        if (ad.salary >= minSalary) {
            std::cout << "Firm name: " << ad.firmName << std::endl;
            std::cout << "Count programmers: " << ad.programmersCount << std::endl;
            std::cout << "Vacation Days Count: " << ad.vacationDaysCount << std::endl;
            std::cout << "Salary: " << ad.salary << std::endl;
        }
    }

    ifs.close();
}

int main()
{
    int n;
    std::cin >> n;

    readRequests(n);

    filterOffers("requests.bin", 1234);

    return 0;
}
