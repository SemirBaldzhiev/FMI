#include <iostream>
enum Subject {
    UNKNOW = -1,
    ALGEBRA,
    DISKRETNI,
    DIS1,
    UP,
    SUBJECT_COUNT
};

struct Student {
    char name[24];
    char egn[10];
    int facultyNumber;
    double grades[SUBJECT_COUNT];
    Subject favorite;
};

struct Classroom {
    Student students[20];
    int studentsCount;
};

void printSubject(Subject subject) {
    switch (subject)
    {
    case UNKNOW:
        break;
    case ALGEBRA:
        break;
    case DISKRETNI:
        break;
    case DIS1:
        break;
    case UP:
        break;
    case SUBJECT_COUNT:
        break;
    default:
        break;
    }
}

int minIndexGrade(double grades[]) {

    int minIndex = 0;
    int minValue = grades[0];

    for (int i = 1; i < Subject::SUBJECT_COUNT; i++) {
        if (grades[i] < minValue) {
            minValue = grades[i];
            minIndex = i;
        }
    }

    return minIndex;
}

Subject getHardestSubject(const Classroom& classroom) {
    double gradesTotal[Subject::SUBJECT_COUNT];

    for (int i = 0; i < Subject::SUBJECT_COUNT; i++)
    {
        for (size_t j = 0; j < classroom.studentsCount; j++)
        {
            gradesTotal[i] += classroom.students[j].grades[i];
        }
    }

    int minGradeIndex = minIndexGrade(gradesTotal);

    return (Subject)minGradeIndex;
}
void printSubject(Subject);

void setFavoriteSub(Student& student) {
    int subject;
    std::cin >> subject;


    switch (subject) {
    case 0:
        student.favorite = Subject::ALGEBRA;
        break;
    case 1:
        student.favorite = Subject::DISKRETNI;
        break;
    case 2:
        student.favorite = Subject::DIS1;
        break;
    case 3:
        student.favorite = Subject::UP;
        break;
    default:
        std::cout << "No such subject";
        break;
    }
}

void initialize(Student& stud) {
    std::cin >> stud.name;
    std::cin >> stud.egn;
    std::cin >> stud.facultyNumber;

    for (int i = 0; i < 4; i++) {
        std::cin >> stud.grades[i];
    }

    setFavoriteSub(stud);
}

void print(const Student& s) {

    std::cout << "Name: " << s.name << '\n';
    std::cout << "EGN: " << s.egn << '\n';
    std::cout << "Faculty Number: " << s.facultyNumber << '\n';
    for (int i = 0; i < 4; i++) {

        std::cout << "Grades: " << s.grades[i] << '\n';
    }
}

void printAverageMarks(const Student* students, size_t count);

const Student& getBestStudent(const Student* students, size_t count);


int main() {

    Student arr[3];
    Classroom cr;

    for (int i = 0; i < 3; i++)
    {
        initialize(arr[i]);
        cr.students[i] = arr[i];
    }

    cr.studentsCount = 3;

    printAverageMarks(arr, 3);

    Student theBest = getBestStudent(arr, 3);

    getHardestSubject(cr);

    return 0;
}

void printAverageMarks(const Student* students, size_t count)
{
    int sum = 0;
    double average;
    for (int i = 0; i < count; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += students[i].grades[j];

        }
        average = sum / 4.0;
        std::cout << average << " " << std::endl;
    }
}

double average(const Student& student) {

    int sum = 0;
    for (int i = 0; i < 4; i++) {

        sum += student.grades[i];
    }

    return (sum / 4.0);

}

const Student& getBestStudent(const Student* students, size_t count) {

    double best = 0;
    int index;

    for (int i = 0; i < count; i++) {

        if (best < average(students[i])) {

            best = average(students[i]);
            index = i;
        }
    }

    return students[index];
}















