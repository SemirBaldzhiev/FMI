#ifndef VEHICLE_H
#define VEHICLE_H


class Vehicle {


public:
	Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	~Vehicle();

protected:
	char* color;
	char* brand;
	int year;
	int countSeats;
	int maxSpeed;

private:
	void copy(const Vehicle& other);
	void clear();




};

#endif // !VEHICLE_H

