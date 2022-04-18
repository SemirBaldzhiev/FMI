#ifndef REMINDER_H
#define REMINDER_H

#include "Date.h"

class Reminder{
private:
	Date date;
	char* title;
	char* note;
	unsigned int priority;

public:
	Reminder();
	Reminder(const Reminder& other);
	Reminder& operator=(const Reminder& other);
	~Reminder();

	const char* getTitle() const;
	const char* getNote() const;
	unsigned int getPriority() const;
	const Date& getDate() const;

private:
	void copy();
	void clear();
};

#endif // !REMINDER_H
