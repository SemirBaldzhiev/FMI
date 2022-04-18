#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(const int day, const int month, const int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}