#include <iostream>
#include <string.h>

struct Student {
    double grades[16];
    int countGrades;
    char name[16];
    char egn[11];
    char fn[11];
    Subject favSubject;
};

enum Subject {
    UNKNOWN = -1,
    OOP,
    ALGEBRA,
    GEOMETRY,
    DATA_STRUCTS,
    SUBJECTS_COUNT
};

struct Classroom {
    Student students[20];
    int studentsCount;
};


void initialize(Student &s);
void print(Student &s);
void printAverageMarks(Student* students, size_t count);
double getAvgGrade(Student &s);
Student& getBestStudent(Student* students, size_t count);
Subject getHardestSubject(const Classroom& classroom);
void printSubject(Subject);

int main() {

    Student st;

    initialize(st);
    print(st);

    return 0;
}


void initialize(Student &s) {

    std::cout << "Enter student name: ";
    std::cin.getline(s.name, 16);

    std::cout << "Enter student EGN: ";
    std::cin.getline(s.egn, 11);

    std::cout << "Enter student faculty number: ";
    std::cin.getline(s.fn, 11);
 
    std::cout << "Enter grades count in range 1-16: ";
    std::cin >> s.countGrades;

    for (int i = 0; i < s.countGrades; ++i) {
        std::cout << "Eneter grade " << i+1 << ": ";
        std::cin >> s.grades[i]; 
    }

    std::cout << "Enter favourite subject: ";
    char favSub[32];
    std::cin.getline(favSub, 32);

    s.favSubject = Subject::UNKNOWN;

    while (s.favSubject == Subject::UNKNOWN) {
        if (strcmp(favSub, "OOP") == 0) {
            
        } 
    }

    
}

void print(Student &s) {
    std::cout << "================Student Info================\n";
    std::cout << "Name: " << s.name << '\n';
    std::cout << "EGN: " << s.egn << '\n';
    std::cout << "FN: " << s.fn << '\n';
    std::cout << "grades: ";
    
    for (int i = 0; i < s.countGrades; ++i) {
        std::cout << s.grades[i];
        if (i != s.countGrades - 1) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';
    std::cout << "============================================\n";
}

void printAverageMarks(Student* students, size_t count) {

    double avgGrade = 0;
    for (int i = 0; i < count; ++i) {
        avgGrade = getAvgGrade(students[i]) / students[i].countGrades;
        std::cout << students[i].name << " has average grade: " << avgGrade << '\n'; 
    }
}

double getAvgGrade(Student &s) {

    double sum = 0;
    for (int i = 0; i < s.countGrades; ++i) {
        sum += s.grades[i];
    }

    return sum / s.countGrades;
}

Student& getBestStudent(Student* students, size_t count) {

    double maxAvgGrade = __DBL_MIN__;
    size_t bestStudentIdx = -1;
    for (int i = 0; i < count; ++i) {
        double currAvgGrade = getAvgGrade(students[i]);

        if (currAvgGrade > maxAvgGrade) {
            maxAvgGrade = currAvgGrade;
            bestStudentIdx = i;
        }
    }

    return students[bestStudentIdx];
}


void printSubject(Subject subject) {

    switch (subject)
    {
        case Subject::ALGEBRA:
            std::cout << "Subject is Algebra\n";
            break;
        case Subject::DATA_STRUCTS:
            std::cout << "Subject is Data structures\n";
            break;
        case Subject::GEOMETRY:
            std::cout << "Subject is Geometry\n";
            break;
        case Subject::OOP:
            std::cout << "Subject is OOP\n";
            break;
        default:
            std::cout << "Such subject does not exist!\n";
            break;
    }

}


