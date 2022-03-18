#include <iostream>
#include <fstream>

struct Point {
    int x;
    int y;
};

void writePointInFile(Point& point) {
    std::ofstream ofs;

    ofs.open("file.txt", std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Error!";
        return;
    }

    ofs.write(reinterpret_cast<const char*>(&point), sizeof(point));

    ofs.close();
}

void readPointFromFile(Point& point) {
    std::ifstream ifs;

    ifs.open("file.txt", std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Error!";
        return;
    }

    ifs.read(reinterpret_cast<char*>(&point), sizeof(point));

    ifs.close();
}

// voynski@g.fmi.uni-sofia.bg

void modifyString(char str[]) {

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' || str[i] <= 'z') {
            str[i] = str[i] + ('A' - 'a');
        }
    }

}

void writeString(char str[]) {
    std::ofstream ofs;

    ofs.open("file", std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Error!";
        return;
    }

    modifyString(str);

    ofs.write(str, sizeof(str));

    ofs.close();
}


int main()
{
    char str[32];

    std::cin >> str;

    modifyString(str);

    std::cout << str;
    return 0;
}
