#ifndef EX01_POINTSET_H
#define EX01_POINTSET_H

#include <string>
#include "Point.h"
#define DEFAULT_SET_SIZE 16

class PointSet
{

public:
    PointSet();
    PointSet(int capacity);
    ~PointSet();


    bool add(const Point& newPoint);
    bool remove(const Point& newPoint);
    int size();



    bool operator!=(const PointSet& setA, const PointSet& setB);
    bool operator==(const PointSet& setA, const PointSet& setB);
    PointSet& operator-(const PointSet& setA, const PointSet& setB);
    PointSet& operator&(const PointSet& setA, const PointSet& setB);

    // TODO!!! - assignments operators and related ctors

private:
    Point* _points;
    int _arrSize;   // Is this a necassery fieled??
    int _curLocation;
    std::string toString(); // why overriden? :(
};

#endif //EX01_POINTSET_H