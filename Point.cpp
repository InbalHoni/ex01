#include "Point.h"


Point::Point()
{
    defaultPoint();
}

Point::Point(int xNum, int yNum)
{
    set(xNum, yNum);
    _pointStr =  std::to_string(_xVal) + "," + std::to_string(_yVal);
}

Point::Point(const Point& other) : Point(other._xVal, other._yVal)
{

}


Point::~Point() // TODO:: fix this to calling the c'tor with 0,0 or just the current constellation, and fixing the string to ""
{
    defaultPoint();
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

void Point::defaultPoint()
{
    set(0,0);
    _pointStr = "";
}


int Point::getXVal() const
{
    return _xVal;
}
int Point::getYVal() const
{
    return _yVal;
}



