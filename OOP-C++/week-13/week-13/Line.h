#ifndef LINE_H
#define LINE_H

#include "Point.h"

template<typename Type>
class Line {
private:
	Point<Type> p1;
	Point<Type> p2;

public:
	void calcLineExpr(Point<Type>& p1, Point<Type>& p2);
};


#endif
