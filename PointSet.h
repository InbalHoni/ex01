#ifndef EX01_POINTSET_H
#define EX01_POINTSET_H

#include <string>
#include "Point.h"
#define DEFAULT_SET_SIZE 16
#define SUBTRECT_GROUP 1
#define INTERSECT_GROUP 2
#define ENLARGMENT_FACTOR 2

class PointSet
{

public:
    PointSet();
    PointSet(int capacity);
    PointSet(const PointSet& Original);
    ~PointSet();

    std::string toString();
    bool add(const Point* newPoint);
    bool remove(const Point* newPoint);
    int size();



    bool operator!=(const PointSet& other) const;
    bool operator==(const PointSet& other) const;
    PointSet operator-(const PointSet& other) const;
    PointSet operator&(const PointSet& other) const;
    PointSet operator=(const PointSet& other);

    // TODO!!! - assignments operators and related ctors

private:
    Point** _points;
    int _arrSize;   // Is this a necassery fieled??
    int _curFilled;
    bool isPointInGroup(const Point* curPnt) const;
    PointSet subtractOrIntersect(int flag, const PointSet& other) const;
    void enlargeSet();

};

#endif //EX01_POINTSET_H