#include <iostream>
#include <fstream>

struct Student {
	int fn;
	unsigned int countPassedExams;
	unsigned int countFailedExams;
	double avgExamsGrade;

};

void saveIndexOfStudentsWithGoodGrades(Student students[], int size) {

	std::ofstream ofs;

	ofs.open("studentsIndex.bin", std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (students[i].avgExamsGrade > 4) {
			ofs.write(reinterpret_cast<char*>(&i), sizeof(i));
		}
	}

	ofs.close();
}


int main()
{
	Student students[3];

	for (int i = 1; i <= 3; i++) {

		Student stud;

		stud.fn = i * 1000 + i * 12;
		stud.countPassedExams = 2 * i;
		stud.countFailedExams = i - 1;
		stud.avgExamsGrade = i * 2;

		students[i - 1] = stud;
	}

	saveIndexOfStudentsWithGoodGrades(students, 3);

	return 0;
}