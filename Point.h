#ifndef EX01_POINT_H
#define EX01_POINT_H

#include <iostream>
#include <string>
#define EQ_POINTS 0

class Point
{
public:
    Point();
    Point(const int xNum, const int yNum);
    ~Point();
    /*friend void set(Point& curPnt, const int xNum, const int yNum);*/ // check if this should be void, and check if this should be a friend function, and if this should be regarding "this" or regarding a point given as an argument
    std::string toString() const; // should be for a "this" object or for a point sent to the function
    void set(const int xNum, const int yNum);
    bool operator==(Point& other) const; // should be private?


private:
    int _xVal, _yVal;
    std::string _pointStr = std::to_string(_xVal) + "," + std::to_string(_yVal);


    /*bool operator==(Point& other);*/ // should be public with two different points, or is this with other point sufficent? and if public is it not bad in terms of encapsulation?
};
#endif //EX01_POINT_H
