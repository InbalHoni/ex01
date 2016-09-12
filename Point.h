#ifndef EX01_POINT_H
#define EX01_POINT_H

#include <iostream>
#include <string>
#define EQ_POINTS 0

class Point
{
public:
    Point();
    Point( int xNum, int yNum); //TODO:: changed const before ints here!
    Point(const Point& other);
    ~Point();
    std::string toString() const; // should be for a "this" object or for a point sent to the function
    void set(const int xNum, const int yNum);
    bool operator==(Point& other) const; // should be private?
    int getXVal() const;
    int getYVal() const;



private:
    int _xVal, _yVal;
    std::string _pointStr;

    void defaultPoint();
};
#endif //EX01_POINT_H
