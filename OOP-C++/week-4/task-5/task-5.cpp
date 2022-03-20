#include <iostream>
#include <fstream>
#include <cstring>


char* readStringFromBinFile() {

    std::ifstream ifs;

    ifs.open("string.bin", std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Error!" << std::endl;
        return nullptr;
    }

    int strLen;

    ifs.read(reinterpret_cast<char*>(&strLen), sizeof(strLen));

    char* str = new char[strLen];

    ifs.read(str, strLen);

    ifs.close();

    return str;
}

void writeStringInBinFile(const char str[]) {
    std::ofstream ofs;

    ofs.open("string.bin", std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Error!";
        return;
    }

    int len = strlen(str) + 1;

    ofs.write(reinterpret_cast<char*>(&len), sizeof(len));
    ofs.write(str, len);

    ofs.close();
}

void saveIndexOfNumberInBinFile() {

    std::ofstream ofs;

    ofs.open("numsIndex.bin", std::ios::binary);

    if (!ofs.is_open()) {
        std::cout << "Error!" << std::endl;
    }

    char* str = readStringFromBinFile();

    int len = strlen(str);

    int indexes[64];
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            indexes[count] = i;
            count++;
        }
    }

    ofs.write(reinterpret_cast<char*>(&count), sizeof(count));
    ofs.write(reinterpret_cast<char*>(&indexes), sizeof(indexes));

    ofs.close();

    delete[] str;
}

void printLastNumIndex() {

    std::ifstream ifs;

    ifs.open("numsIndex.bin", std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Error!" << std::endl;
        return;
    }

    int count;
    ifs.read(reinterpret_cast<char*>(&count), sizeof(count));

    ifs.seekg(count * 4, std::ios::beg);
   
    int lastIndex;

    ifs.read(reinterpret_cast<char*>(&lastIndex),sizeof(lastIndex));

    ifs.close();

    std::cout << "Last number index: " << lastIndex << std::endl;
}

int main()
{
    writeStringInBinFile("abc12ns3n4gh5a72asds5");
    saveIndexOfNumberInBinFile();
    printLastNumIndex();
}