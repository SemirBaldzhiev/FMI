#include <iostream>

struct StudentBook {
    char studentName[32];
    char fn[16];
    unsigned int countGrades;
    double grades[16];
};

void AddGrade(StudentBook& sb, double grade) {

    if (sb.countGrades < 16) {
        sb.grades[sb.countGrades] = grade;
        sb.countGrades++;
    }
}

void swap(double* a, double* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortGradesDesc(StudentBook& sb) {

    int count = sb.countGrades;

    for (int i = 0; i < count - 1; i++) {

        for (int j = 0; j < count - i - 1; j++) {
            if (sb.grades[i] > sb.grades[j]) {
                swap(&sb.grades[i], &sb.grades[j]);
            }
        }
    }
}

double avgGrades(const StudentBook& sb) {

    double sum = 0;
    int countCompletedExams = 0;

    for (int i = 0; i < sb.countGrades; i++) {
        if (sb.grades[i] >= 3.00) {
            sum += sb.grades[i];
            countCompletedExams++;
        }
    }

    return sum / countCompletedExams;
}

bool canContinueHigherCourse(const StudentBook& sb) {

    int notCompletedExams = 0;
    bool canContinue = true;

    for (int i = 0; i < sb.countGrades; i++)
    {
        if (sb.grades[i] >= 2.00 && sb.grades[i] < 3.00) {
            notCompletedExams++;
        }
    }

    if (notCompletedExams < 4){
        canContinue = true;
    }

    if (notCompletedExams > 4) {
        canContinue = false;
    }

    if (notCompletedExams == 4) {
        if (avgGrades(sb) >= 4.00) {
            canContinue = true;
        }
        else {
            canContinue = false;
        }
    }

    return canContinue;
}

bool canTakeScholarship(const StudentBook& sb) {
    
    for (int i = 0; i < sb.countGrades; i++) {
        if (sb.grades[i] >= 2.00 && sb.grades[i] < 3.00) {
            return false;
        }
    }
    
    if (avgGrades(sb) >= 5.00) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    return 0;
}
