#include "Point.h"


Point::Point()
{

}

Point::Point(const int xNum, const int yNum)
{
    set(xNum, yNum);
}

Point::~Point()
{
    _xVal = NULL;
    _yVal = NULL;
}
std::string Point::toString() const
{
    return _pointStr;
}


void Point::set(const int xNum, const int yNum)
{
    _xVal = xNum;
    _yVal = yNum;
}

bool Point::operator==(Point& other) const
{
    // If string compare ==0, then strings are equal, hence points are equal.
     return _pointStr.compare(other._pointStr) == EQ_POINTS;
}

/*

void Point::set(Point& curPnt, const int xNum, const int yNum)
{
    curPnt._xVal = xNum;
    curPnt._yVal = yNum;
}*/
