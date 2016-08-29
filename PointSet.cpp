#include <string>
#include <sstream>
#include "PointSet.h"
#include "Point.h"


PointSet::PointSet()
{
    PointSet(DEFAULT_SET_SIZE);
}

PointSet:: PointSet(int capacity) // maybe add an option to add a list of points to this c'tor?
{
    _points = new Point[capacity];
    _arrSize = capacity;
    _curLocation = 0;
}


PointSet::~PointSet()
{
    for (int i=0; i < _arrSize; i++)
    {
        delete(_points[i]);
    }

    delete _points;
}


std::string PointSet::toString()
{
    std::stringstream pointsStr;
    for(int j=0; j < _curLocation; j++)
    {
        pointsStr << _points[j].toString();
        if (j != _curLocation - 1)
        {
            pointsStr<< ",";
        }
    }
    return pointsStr.str();
}


bool PointSet::add(const Point& newPoint)
{

}

bool PointSet::remove(const Point& newPoint)
{

}


int PointSet::size()
{
    return _curLocation;
}



bool operator!=(const PointSet& setA, const PointSet& setB);
bool operator==(const PointSet& setA, const PointSet& setB);
PointSet& operator-(const PointSet& setA, const PointSet& setB);
PointSet& operator&(const PointSet& setA, const PointSet& setB);

