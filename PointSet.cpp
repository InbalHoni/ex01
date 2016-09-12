#include <tgmath.h>
#include "PointSet.h"



Point PointSet::refPnt = Point();

PointSet::PointSet():PointSet(DEFAULT_SET_SIZE)
{

}

PointSet::PointSet(int capacity)
{
    _points = new Point*[capacity];
    _arrSize = capacity;
    fillArray(_points);
}
/**
 * copy constructor
 * @param Original
 * @return
 */
PointSet::PointSet(const PointSet& original) : PointSet(original._arrSize)
{
    *this = original;
}


PointSet::~PointSet()
{
    for (int i = 0; i < size(); i++)
    {
        delete(_points[i]);
    }
    delete[] _points;
    _arrSize = 0;
    _curFilled = 0;
}



std::string PointSet::toString()
{
    std::stringstream pointsStr;
    for(int j = 0 ; j < size(); j++)
    {
        pointsStr << _points[j]->toString()<<"\n";
    }
    return pointsStr.str();
}


bool PointSet::add(Point const &newPoint)
{
    if(isPointInSet(newPoint) == NOT_IN_SET)
    {
        if (_arrSize - _curFilled == 0)
        {
            enlargeSet();
        }
        *_points[_curFilled] = newPoint;
        _curFilled++;
        return true;
    }
    return false;
}

bool PointSet::remove(Point const &pointToRemove)
{
    int location = isPointInSet(pointToRemove);
    if ( location != NOT_IN_SET)
    {
        delete _points[location]; //TODO: should this be just a destructor?
        if( size() < (int)(MINIMIZE_FACTOR * _arrSize))
        {
            minimizeSet();
        }
        if (location != _curFilled - 1)
        {
            _points[location] = _points[_curFilled - 1]; // moving a point from the end to fill the gap
        }
        _curFilled--;

        return true;
    }
    return false;
}


int PointSet::size() const
{
    return _curFilled;
}



bool PointSet::operator!=(const PointSet& other) const
{
    return !(operator==(other));
}


bool PointSet::operator==(const PointSet& other) const
{
    // number of set members is different, obviously groups are not equal.
    if (this->size() != other.size())
    {
        return false;
    }
    int match = 0;
    for (int i = 0; i < size(); i++)
    {
       if (other.isPointInSet(*_points[i]))
       {
           match++;
       }
    }
    return match == _curFilled;
}
PointSet PointSet::operator-(const PointSet& other) const
{
    PointSet remainder = subtractOrIntersect(SUBTRACT_GROUP, other);
    return remainder;
}
PointSet PointSet::operator&(const PointSet& other) const
{
    PointSet intersection = subtractOrIntersect(INTERSECT_GROUP, other);
    return intersection;
}

PointSet& PointSet::operator=(const PointSet& other)
{
    if (this == &other)
    {
        return *this;
    } else
    {
        for(int i = 0; i < other.size(); i++)
        {
            delete _points[i];
            *_points[i] = *other._points[i];
        }
    }
    return *this;
}


int PointSet::isPointInSet(const Point& curPnt) const
{
    for(int j = 0; j < size() ; j++)
    {
        if (curPnt == *_points[j])
        {
            return j;
        }
    }
    return NOT_IN_SET;
}

PointSet PointSet::subtractOrIntersect(int flag, const PointSet& other) const
{
    PointSet returnedGroup = PointSet(size());
    for (int i = 0; i <size(); i++)
    {
        if (other.isPointInSet(*_points[i]) == NOT_IN_SET)
        {
            if (flag == SUBTRACT_GROUP)
            {
                returnedGroup.add(*_points[i]);
            }
        }
        else if (other.isPointInSet(*_points[i]) != NOT_IN_SET)
        {
            if (flag == INTERSECT_GROUP)
            {
                returnedGroup.add(*_points[i]);
            }
        }
    }
    return returnedGroup;
}

void PointSet::enlargeSet()
{
    _arrSize = _arrSize*ENLARGMENT_FACTOR;
    Point** enlargedArr = new Point*[_arrSize];
    fillArray(enlargedArr);
    std::swap_ranges(_points, _points+_curFilled, enlargedArr);
    delete[] _points;
    _points = enlargedArr;
}

void PointSet::minimizeSet()
{
    _arrSize = (int)(_arrSize*MINIMIZE_FACTOR);
    Point** miniArr = new Point*[_arrSize];
    fillArray(miniArr);
    std::swap_ranges(_points, _points+_curFilled, miniArr);
    delete[] _points;
    _points = miniArr;
}

void PointSet::fillArray(Point** arrToFill)
{
    for (int i = 0;  i <_arrSize;i++)
    {
        _points[i] = nullptr;
    }
}

PointSet* PointSet::convexSearch()
{
    int numOfMembers = size();
    Point** retPnts = new Point*[numOfMembers + 1];
    std::copy(_points, _points+numOfMembers, retPnts+1); // leaving the first place empty.

    // Finding the point with minimum y-coor value in order to make it the reference point of the
    // convex hull
    for (int i = 2; i < numOfMembers+1; i++ )
    {
        if((retPnts[i]->getYVal() < retPnts[1]->getYVal()) || ((retPnts[i]->getYVal() ==
                retPnts[1]->getYVal()) && (retPnts[i]->getXVal() < retPnts[1]->getXVal())))
        {
            std::swap(retPnts[i], retPnts[1]);
        }
    }

    updateRef(*retPnts[1]);

    //sorting points in increasing angle in relation to our minimum y point
    std::sort(retPnts+1, retPnts+numOfMembers+1, angleComp);
    retPnts[0] = retPnts[numOfMembers];

    int M = 1;
    for (int i = 2; i < numOfMembers; i++)
    {
        while (ccw(*retPnts[M-1], *retPnts[M], *retPnts[i]) <= 0)
        {
            if (M > 1)
            {
                M--;
            }
            // all points are collinear, this is our breaking condition
            else if (i == numOfMembers)
            {
                break;
            } else
            {
                i++;
            }
        }
        M++;
        std::swap(retPnts[i], retPnts[M]);
    }
    // creating the convex hull to be returned and putting the relevant points in it.
    PointSet* retSet = new PointSet(M);
    delete[]  retSet->_points;
    retSet->_points = retPnts;
    /*for (int j = 0; j < M; j++)
    {
        retSet->add(*retPnts[j]);
    }

     //and some stuff to delete the points from the array we created, and delete the array itself.
    */
    return retSet;
}

int PointSet::ccw(Point const &pnt1, Point const &pnt2, Point const &pnt3)
{
    return (pnt2.getXVal() - pnt1.getXVal()) * (pnt3.getYVal() - pnt1.getYVal()) - (pnt2.getYVal()
            - pnt1.getYVal()) * (pnt3.getXVal() - pnt1.getXVal());
}


bool PointSet::angleComp(const Point* a,const Point* b)
{
    int direction = ccw(refPnt, *a, *b);
    // the points are not collinear, we can determine which has a bigger angle.
    if (direction != 0)
    {
        return direction > 0;
    }

    // points are collinear, we determine by distance
    bool ans = distance(refPnt, *a) < distance(refPnt, *b);

    return ans;


}

int PointSet::distance(Point const &a, Point const &b)
{
    return std::sqrt(std::pow(b.getXVal()-a.getXVal(), 2) + std::pow(b.getYVal() - a.getYVal(),2));
}

bool PointSet::forPrintComp(const Point* pnt1, const Point* pnt2)
{
    return  ((pnt1->getXVal() < pnt2->getXVal()) || ((pnt1->getXVal() == pnt2->getXVal()) &&
            (pnt1->getYVal() < pnt2->getYVal())));

}

void PointSet::sortForPrint()
{
    std::sort(_points, _points +size(), forPrintComp);
}

void PointSet::updateRef(Point &ref)
{
    refPnt = ref;
}







