#include <string>
#include <sstream>
#include "PointSet.h"


PointSet::PointSet():PointSet(DEFAULT_SET_SIZE)
{

}

PointSet::PointSet(int capacity) // maybe add an option to add a list of points to this c'tor?
{
    _points = new Point*[capacity];
    std::fill_n(_points, capacity, nullptr);
    _arrSize = capacity;
    _curFilled = 0;
}
/**
 * copy constructor
 * @param Original
 * @return
 */
PointSet::PointSet(const PointSet& original) : PointSet(original._arrSize)
{

}


PointSet::~PointSet()
{
    for (int i=0; i < _curFilled; i++)
    {
        delete(_points[i]);
        //_points[i] =nullptr;
    }
    delete[] _points;
    //_points = nullptr; // should add this or not?
    _arrSize = 0;
    _curFilled = 0;
}


std::string PointSet::toString()
{
    std::stringstream pointsStr;
    for(int j=0; j < _curFilled; j++)
    {
        pointsStr << _points[j]->toString();
        if (j != _curFilled - 1)
        {
            pointsStr<< ",";
        }
    }
    return pointsStr.str();
}


bool PointSet::add(Point* newPoint)
{
    if(!isPointInGroup(newPoint))
    {
        if (_arrSize - _curFilled == 0)
        {
            enlargeSet();
        }
        _curFilled++;
        _points[_curFilled] = newPoint;
        return true;
    }
    return false;
}

bool PointSet::remove(const Point* newPoint)
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

PointSet PointSet::operator=(const PointSet& other)
{

}

bool PointSet::isPointInGroup(const Point* curPnt) const
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

PointSet PointSet::subtractOrIntersect(int flag, const PointSet& other) const
{
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

void PointSet::enlargeSet()
{
    _arrSize = _arrSize*ENLARGMENT_FACTOR;
    Point** enlargedArr = new Point*[_arrSize];
    std::fill_n(_points, _arrSize, nullptr);
    std::swap_ranges(_points[0], _points[_curFilled], enlargedArr[0]);
    delete[] _points;
    _points = enlargedArr;
}


