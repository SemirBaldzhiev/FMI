// TASK 4 SEMINAR
#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_SIZE = 128;

bool loadFile(std::fstream& file, const char fileName[]) {
	
	file.open(fileName);

	if (!file.is_open()) {
		return false;
	}

	return true;
}

void printStudentInfo(std::fstream& in, const char facNum[]) {
	
	while (!in.eof()) {

		char firstName[MAX_SIZE];
		char lastName[MAX_SIZE];
		char email[MAX_SIZE];
		char fn[MAX_SIZE];

		in.getline(firstName, MAX_SIZE, ',');
		in.getline(lastName, MAX_SIZE, ',');
		in.getline(email, MAX_SIZE, ',');
		in.getline(fn, MAX_SIZE);

		if (strcmp(fn, facNum) == 0) {
			std::cout << "Name: " << firstName << " " << lastName << ", " << "Email: " << email << ", " << "FN: " << fn << std::endl;
			break;
		}
	}

	in.seekg(std::ios::beg);
}

void editStudent(const char facNum[], const char newEmail[], std::fstream& file) {

	std::fstream temp;

	temp.open("temp.csv", std::ios::out);

	if (!temp.is_open()) {
		std::cout << "Error" << std::endl;
		return;
	}

	while (!file.eof()) {

		char firstName[MAX_SIZE];
		char lastName[MAX_SIZE];
		char email[MAX_SIZE];
		char fn[MAX_SIZE];


		file.getline(firstName, MAX_SIZE, ',');
		file.getline(lastName, MAX_SIZE, ',');
		file.getline(email, MAX_SIZE, ',');
		file.getline(fn, MAX_SIZE);



		if (strcmp(fn, facNum) == 0) {
			temp << firstName << "," << lastName << "," << newEmail << "," << fn << '\n';
		}
		else {
			temp << firstName << "," << lastName << "," << email << "," << fn << '\n';
		}
	}
	
	temp.close();

	file.seekg(std::ios::beg);

	temp.open("temp.csv", std::ios::in);

	if (!temp.is_open()) {
		std::cout << "Error\n";
		return;
	}

	while (!temp.eof()) {

		char firstName[MAX_SIZE];
		char lastName[MAX_SIZE];
		char email[MAX_SIZE];
		char fn[MAX_SIZE];

		temp.getline(firstName, MAX_SIZE, ',');
		temp.getline(lastName, MAX_SIZE, ',');
		temp.getline(email, MAX_SIZE, ',');
		temp.getline(fn, MAX_SIZE);

		if (strlen(firstName) == 0) {
			break;
		}

		file << firstName << "," << lastName << "," << email << "," << fn << '\n';
	}

	temp.close();

	file.seekg(std::ios::beg);

	remove("temp.csv");
}

void saveInAnotherFile(std::fstream& file, const char newFileName[]) {
	std::ofstream newFile;

	newFile.open(newFileName, std::ios::out);

	if (!newFile.is_open()) {
		std::cout << "Error\n";
		return;
	}

	file.seekg(std::ios::beg);

	while (!file.eof()) {
		char firstName[MAX_SIZE];
		char lastName[MAX_SIZE];
		char email[MAX_SIZE];
		char fn[MAX_SIZE];


		file.getline(firstName, MAX_SIZE, ',');
		file.getline(lastName, MAX_SIZE, ',');
		file.getline(email, MAX_SIZE, ',');
		file.getline(fn, MAX_SIZE);

		if (strlen(firstName) == 0) {
			break;
		}

		newFile << firstName << "," << lastName << "," << email << "," << fn << '\n';
	}

	newFile.close();
}

int main()
{
	std::fstream fileStream;

	std::cout << "Open file:\n";
	std::cout << ">";

	char fileName[32];

	std::cin >> fileName;

	bool isSuccess = loadFile(fileStream, fileName);

	if (isSuccess) {
		std::cout << "File successfully opened!\n";
	}

	char command[16];
	char facNum[16];
	char newEmail[32];

	do{
		std::cout << ">";
		std::cin >> command;
		
		if (strcmp(command, "print") == 0) {
			std::cin >> facNum;
			printStudentInfo(fileStream, facNum);
		}
		else if (strcmp(command, "edit") == 0) {
			std::cin >> facNum;
			std::cin >> newEmail;
			editStudent(facNum, newEmail, fileStream);
		}

	} while (strcmp(command, "save") != 0);

	char newFileName[32];

	std::cin >> newFileName;

	saveInAnotherFile(fileStream, newFileName);
	std::cout << "File " << fileName << " successfully saved!";
	
	fileStream.close();
	
	return 0;
}