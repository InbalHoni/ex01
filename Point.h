#ifndef EX01_POINT_H
#define EX01_POINT_H

#include <iostream>;
#include "PointSet.h"

class Point
{
public:
    Point();
    Point(const int xNum, const int yNum);
    ~Point();
    /*friend void set(Point& curPnt, const int xNum, const int yNum);*/ // check if this should be void, and check if this should be a friend function, and if this should be regarding "this" or regarding a point given as an argument
    friend std::string PointSet::toString();



private:
    int _xVal, _yVal;
    std::string toString() const; // should be for a "this" object or for a point sent to the function
    void set(const int xNum, const int yNum);
};
#endif //EX01_POINT_H
