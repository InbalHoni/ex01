#ifndef EX01_POINTSET_H
#define EX01_POINTSET_H

#include <string>
#include <sstream>
#include <algorithm>
#include "Point.h"
#define DEFAULT_SET_SIZE 16
#define SUBTRACT_GROUP 1
#define INTERSECT_GROUP 2
#define ENLARGMENT_FACTOR 2
#define MINIMIZE_FACTOR 0.5
#define NOT_IN_SET -1

class PointSet
{

public:
    PointSet();
    PointSet(int capacity);
    PointSet(const PointSet& Original);
    ~PointSet();

    std::string toString();
    bool add(Point const &newPoint);
    bool remove(Point const &pointToRemove);
    int size() const;


    bool operator!=(const PointSet& other) const;
    bool operator==(const PointSet& other) const;
    PointSet operator-(const PointSet& other) const;
    PointSet operator&(const PointSet& other) const;
    PointSet& operator=(const PointSet& other);

    PointSet* convexSearch();
    bool static angleComp(const Point* a,const Point* b);
    bool static forPrintComp(const Point* pnt1, const Point* pnt2);
    void sortForPrint();

    static Point refPnt;




private:
    Point** _points;
    int _arrSize;
    int _curFilled = 0; // initial default size fora new PointSet.
    int isPointInSet(const Point& curPnt) const;
    PointSet subtractOrIntersect(int flag, const PointSet& other) const;
    void enlargeSet();
    void minimizeSet();
    void fillArray(Point** arrToFill);
    int static ccw(Point const &pnt1, Point const &pnt2, Point const &pnt3);
    int static distance(Point const &a, Point const &b);
    void static updateRef(Point& ref);

};

#endif //EX01_POINTSET_H