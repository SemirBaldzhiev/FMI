#ifndef LINE_INL
#define LINE_INL

#include "Line.h"
#include "Point.h"


template<typename Type>
void Line<Type>::calcLineExpr(Point<Type>& p1, Point<Type>& p2) {
	Type xConst = p2.getY() - p1.getY();
	Type yConst = -(p2.getX() - p1.getY());

	Type freeConst = yConst * (-p1.getX()) - xConst * (-p1.getY());

	std::count << xConst << "x" << yConst << "y" << freeConst << std::endl;

}


#endif