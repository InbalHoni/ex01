/**
 * Simple test for the PointSet implementation
 */
#include <iostream>
#include <string>
#include "PointSet.h"

#define NUM_ARRAYS 3
#define EQ_RETURN_VAL 0

/*
int main()
{
*/
/*   PointSet listsArr[NUM_ARRAYS];
    int res;
    res = listsArr[0].add(Point(6, 5));
    res+=listsArr[0].add(Point(7, 6));
    res+=listsArr[1].add(Point(7, 6));
    res+=listsArr[1].add(Point(6, 5));
    res+=listsArr[1].add(Point(8, 2));
    res+=listsArr[2].add(Point(9, -2));
    res+=listsArr[2].add(Point(10, -2));

    if (res != 7)
    {
        std::cout << "ERROR: Fail test add" << std::endl;
        return 1;
    }

    if (listsArr[0] == listsArr[1])
    {
        std::cout << "ERROR: Fail test comparing " << std::endl;
        return 1;
    }

    PointSet min = listsArr[0] - listsArr[1];
    if (min.size() != 0)
    {
        std::cout << "ERROR: Fail test Minus" << std::endl;
        std::cout <<	listsArr[0].toString();
        std::cout << "-" << std::endl;
        std::cout << 	listsArr[1].toString();
        std::cout << "=" << std::endl;
        std::cout << min.toString();
        std::cout << "-" << std::endl;
        return 1;
    }

    PointSet intersect = listsArr[0] & listsArr[2];
    if (intersect.size() != 0)
    {

        std::cout << "ERROR: Fail test Intersection" << std::endl;
        std::cout << listsArr[0].toString();
        std::cout << "&" << std::endl;
        std::cout << listsArr[2].toString();
        std::cout << "=" << std::endl;
        std::cout << intersect.toString();
        std::cout << "&" << std::endl;
        return 1;
    }

    std::cout << "Pass basic binary tests." << std::endl;*//*



*/
/*    PointSet* mySet = new PointSet(4);
    Point pnt1 = Point(1,2);
    Point pnt2 = Point(2,3);
    Point pnt3 = Point(4,5);
    mySet->add(pnt1);
    mySet->add(pnt2);
    mySet->add(pnt3);
    mySet->remove(pnt1);
    mySet->remove(pnt2);
    mySet->remove(pnt3);
    mySet->add(Point(1,1));*//*

*/
/*
    int i = 5;
    while(i)
    {
        char const* str("3,\n 5,6\n");
        int xNum, yNum;
        int success = std::sscanf(str,"%d,%d\n", &xNum,&yNum);
        std::cout<<xNum<<","<<yNum<<"\n";
        std::cout<<success<<"\n";
        i--;
    }
*//*

    PointSet* wow = new PointSet();
    Point** pntArr = new Point*[10];
    Point pointush = Point(1,2);
    *pntArr[0] = pointush;
    wow->refPnt = pointush;
    pntArr[1] = new Point(3,4);
    pntArr[2] = new Point(0,4);
    pntArr[3] = new Point(4,0);
    std::sort(pntArr, pntArr+4, )




    return 0;

}

*/
