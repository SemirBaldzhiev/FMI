#include <iostream>
#include <fstream>

const int STUDENTS_COUNT = 16;

struct Student {
	int fn;
	unsigned int countPassedExams;
	unsigned int countFailedExams;
	double avgExamsGrade;

};

void saveStudentsInBinFile(Student students[], int size) {

	std::ofstream ofs;

	ofs.open("studentsFile.bin", std::ios::binary);

	if (!ofs.is_open()) {
		std::cout << "Error" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++) {

		Student st;

		st.fn = students[i].fn;
		st.countPassedExams = students[i].countPassedExams;
		st.countFailedExams = students[i].countFailedExams;
		st.avgExamsGrade = students[i].avgExamsGrade;


		ofs.write(reinterpret_cast<char*>(&st), sizeof(st));
	}

	ofs.close();
}

void sortStudentsByGrades(Student students[], int size) {

	Student key;
	int j;

	for (int i = 1; i < size; i++) {
		
		key = students[i];
		j = i - 1;

		while (j >= 0 && students[j].avgExamsGrade < key.avgExamsGrade) {
			students[j + 1] = students[j];
			j--;
		}

		students[j + 1] = key;
	}
}

int* getStudentsFnByGrades() {

	std::ifstream ifs;

	ifs.open("studentsFile.bin", std::ios::binary);

	if (!ifs.is_open()) {
		std::cout << "Error!" << std::endl;
		return nullptr;
	}

	Student students[STUDENTS_COUNT];
	int size = 0;

	while (!ifs.eof()) {

		Student st;

		if (!ifs.read(reinterpret_cast<char*>(&st), sizeof(st))) {
			break;
		}

		students[size] = st;
		size++;
	}

	ifs.close();

	sortStudentsByGrades(students, size);

	int* facultyNumbers = new int[size];

	for (int i = 0; i < size; i++) {
		facultyNumbers[i] = students[i].fn;
	}

	return facultyNumbers;
}


int main()
{
	Student students[3];

	for (int i = 1; i <= 3; i++) {
		
		Student stud;

		stud.fn = i * 1000 + i * 12;
		stud.countPassedExams = 2*i;
		stud.countFailedExams = i - 1;
		stud.avgExamsGrade = i * 2;

		students[i - 1] = stud;
	}

	saveStudentsInBinFile(students, 3);

	int* fns = getStudentsFnByGrades();

	for (int i = 0; i < 3; i++) {
		std::cout << "Fn "<< i + 1 << ": " << fns[i] << std::endl;
	}

	delete[] fns;

	return 0;
}