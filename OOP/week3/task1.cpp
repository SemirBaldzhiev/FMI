#include <iostream>
#include <fstream>

int copyTo(const char *source, const char *destination);

int main() {

    char sourceFile[256];
    char destinationFile[256];

    std::cin >> sourceFile;
    std::cin >> destinationFile;

    int res = copyTo(sourceFile, destinationFile);

    if (res) {
        std::cout << "Cannot copy content form " << sourceFile << " to " << destinationFile << "!\n";
    }

    return 0;
}

int copyTo(const char *source, const char *destination) {


    std::ifstream ifs(source);
    
    if (!ifs.is_open()) {
        std::cout << "Error opening file " << source <<  "for reading!" << '\n';
        return -1;
    }

    std::ofstream ofs(destination);

    if (!ofs.is_open()) {
        std::cout << "Error opening file " << destination <<  "for writing!" << '\n';
        ifs.close();
        return -1;
    }

    char buffer[256];
    while (ifs.getline(buffer, 256)) {
        ofs << buffer << '\n';
    }

    return 0;
}