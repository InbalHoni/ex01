#include "Point.h"

Point::Point()
{
    Point(nullptr, nullptr);
    //bla
}

Point::Point(const int xNum, const int yNum)
{
    set(xNum, yNum);
}

Point::~Point()
{
    Point(); // Calling default c'tor in order to unassign the object's fields
}
std::string Point::toString() const
{
    return std::to_string(_xVal) + "," + std::to_string(_yVal);
}


void Point::set(const int xNum, const int yNum)
{
    _xVal = xNum;
    _yVal = yNum;
}


/*

void Point::set(Point& curPnt, const int xNum, const int yNum)
{
    curPnt._xVal = xNum;
    curPnt._yVal = yNum;
}*/
