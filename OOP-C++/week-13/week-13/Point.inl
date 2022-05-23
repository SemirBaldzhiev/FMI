#ifndef POINT_INL
#define POINT_INL

#include <fstream>
#include "Point.h"

template<typename Type>
Point<Type>::Point(const Type x, const Type y) {
	this->x = x;
	this->y = y;
}

template<typename Type>
std::istream& operator>>(std::istream& in, Type& elem) {
	in >> elem;
	return in;
}


template<typename Type>
std::ostream& operator<<(std::ostream& out, const Type& elem) {
	out << elem;
	return out;
}

template<typename Type>
const Type Point<Type>::getX() const {
	return x;
}

template<typename Type>
const Type Point<Type>::getY() const {
	return y;
}

#endif // !POINT_INL
