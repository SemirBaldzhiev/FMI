#ifndef DATE_H
#define DATE_H

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(const int day, const int month, const int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
};

#endif // !DATE_H

