#ifndef DATE_H
#define DATE_H

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);
	Date& operator=(const Date& other);
};

#endif // !DATE_H
