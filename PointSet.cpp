#include <string>
#include <sstream>
#include "PointSet.h"


PointSet::PointSet()
{
    PointSet(DEFAULT_SET_SIZE);
}

PointSet:: PointSet(int capacity) // maybe add an option to add a list of points to this c'tor?
{
    _points = new Point[capacity];
    _arrSize = capacity;
    _curFilled = 0;
}


PointSet::~PointSet()
{
    delete[] _points;
    //_points = nullptr;
    _arrSize = 0; // should this be here or is this extensive?
}


std::string PointSet::toString()
{
    std::stringstream pointsStr;
    for(int j=0; j < _curFilled; j++)
    {
        pointsStr << _points[j].toString();
        if (j != _curFilled - 1)
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
    return _curFilled;
}



bool PointSet::operator!=(const PointSet& other) const
{
    return !(operator==(other));
}


bool PointSet::operator==(const PointSet& other) const {
    // number of set members is different' obviously groups are not equal
    if (this->_curFilled != other._curFilled) {
        return false;
    }
    int match = 0;
    for (int i = 0; i < _curFilled; i++) // do according to _currFilled, or according to arrSize?
    {
       if (other.isPointInGroup(_points[i]))
       {
           match +=1;
       }
    }
    return match == _curFilled;
}
PointSet PointSet::operator-(const PointSet& other) const
{
    PointSet remainder = subtractOrIntersect(SUBTRECT_GROUP, other); // is there a way to allocate without new and then being able to return a reference and not a pointer?
    return remainder;
}
PointSet PointSet::operator&(const PointSet& other) const
{
    PointSet intersection = subtractOrIntersect(INTERSECT_GROUP, other);
    return intersection;
}

bool PointSet::isPointInGroup(Point& curPnt) const
{
    for(int j=0; j < _curFilled ; j++)
    {
        if (curPnt == _points[j])
        {
            return true;
        }
    }
    return false;
}

PointSet PointSet::subtractOrIntersect(int flag, const PointSet& other) const {
    PointSet returnedGroup = PointSet(_curFilled);
    for (int i=0; i < _curFilled; i++)
    {
        if (!other.isPointInGroup(_points[i]))
        {
            if (flag == SUBTRECT_GROUP)
            {
                returnedGroup.add(_points[i]);
            }
        }
        else if (other.isPointInGroup(_points[i]))
        {
            if (flag == INTERSECT_GROUP)
            {
                returnedGroup.add(_points[i]);
            }
        }
    }
    return returnedGroup;

}

