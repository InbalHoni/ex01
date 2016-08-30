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
    std::string toString() const; // should be for a "this" object or for a point sent to the function
    void set(const int xNum, const int yNum);
    bool operator==(Point& other) const; // should be private?


private:
    int _xVal, _yVal;
    std::string _pointStr = std::to_string(_xVal) + "," + std::to_string(_yVal);
};
#endif //EX01_POINT_H
