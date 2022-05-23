#ifndef POINT_H
#define POINT_H

#include <fstream>;

template<typename Type>
class Point {
public:
	Point(const Type x, const Type y);

	friend std::istream& operator>>(std::istream& in, Type& elem);
	friend std::ostream& operator<<(std::ostream& out, const Type& elem);

	const Type getX() const;
	const Type getY() const;
private:
	Type x;
	Type y;
};

#include "Point.inl"

#endif // !POINT_H

