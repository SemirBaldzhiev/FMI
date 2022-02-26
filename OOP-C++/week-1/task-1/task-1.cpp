#include <iostream>

const int GRADES_COUNT = 4;

struct Student {
    char name[24];
    char egn[10];
    int facultyNumber;
    double grades[GRADES_COUNT];
};
    
void initialize(Student& s) {
    
    std::cout << "Enter name: ";
    std::cin >> s.name;
    std::cout << "Enter EGN: ";
    std::cin >> s.egn;
    std::cout << "Enter FN: ";
    std::cin >> s.facultyNumber;
    
    std::cout << "Enter grades: ";

    for (int i = 0; i < GRADES_COUNT; i++) {
        std::cin >> s.grades[i];
    }
}

void print(const Student& s) {
    std::cout << "Name: " << s.name << std::endl;;
    std::cout << "EGN: " << s.egn << std::endl;
    std::cout << "FN: " << s.facultyNumber << std::endl;
    std::cout << "grades: ";

    for (int i = 0; i < GRADES_COUNT; i++) {
        std::cout << s.grades[i] << " ";
    }
}

double avgGrade(double grades[]) {
    double sum = 0;

    for (int i = 0; i < GRADES_COUNT; i++) {
        sum += grades[i];
    }

    return sum / GRADES_COUNT;
}

void printAverageMarks(Student* students, size_t count) {

    for (int i = 0; i < count; i++) {
        double averageGrade = avgGrade(students[i].grades);

        std::cout << "Student " << students[i].name << ": " << averageGrade << std::endl;
    }
}

Student& getBestStudent(Student* students, size_t count) {

    double bestGrade = 0;
    int index = 0;

    for (int i = 0; i < count; i++) {
        double averageGrade = avgGrade(students[i].grades);

        if (averageGrade > bestGrade) {
            bestGrade = averageGrade;
            index = i;
        }
    }

    return students[index];
}


int main()
{
    Student arr[3];

    for (int i = 0; i < 3; i++) {
        initialize(arr[i]);
    }

    //print(arr[1]);
    //printAverageMarks(arr, 3);
    print(getBestStudent(arr, 3));

    return 0;
}