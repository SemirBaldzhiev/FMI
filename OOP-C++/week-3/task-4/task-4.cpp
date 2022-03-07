#include <iostream>
#include <fstream>
#include <cstring>


struct Student {
    char fn[16];
    char name[32];
    double avgGrades;

    void write(std::ostream& out) {
        out << fn << std::endl;
        out << name << std::endl;
        out << avgGrades << std::endl;
    }

    void read(std::istream& in) {
        in >> fn;
        in >> name;
        in >> avgGrades;
    }
};

void writeStudents(std::ostream& out, Student students[], int size) {
    for (int i = 0; i < size; i++) {
        students[i].write(out);
    }
}

void readStudents(std::istream& in, Student students[], int size) {
    for (int i = 0; i < size; i++) {
        students[i].read(in);
    }
}


int main()
{
    Student st;

    strcpy_s(st.name, "MyName");
    strcpy_s(st.fn, "8mi8978888");
    st.avgGrades = 4.6;

    Student st2;

    strcpy_s(st2.name, "MyName2");
    strcpy_s(st2.fn, "3mi89788882");
    st2.avgGrades = 4.8;

    Student arr[2] = { st, st2 };

    writeStudents(std::cout, arr, 2);

    std::ofstream out;

    out.open("students.txt");

    if (!out.is_open()) {
        std::cout << "Cannot open file!" << std::endl;
        return -1;
    }

    writeStudents(out, arr, 2);

    std::ifstream in;

    in.open("students.txt");

    if (!in.is_open()) {
        std::cout << "Cannot open file!" << std::endl;
        return -1;
    }

    readStudents(in, arr, 2);
    writeStudents(std::cout, arr, 2);

    in.close();
    out.close();
}