#include "Date.h"

Date::Date() : day(0), month(0), year(0) { }

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date(const Date& other)
{

}

Date& Date::operator=(const Date& other)
{
	// TODO: insert return statement here
}
