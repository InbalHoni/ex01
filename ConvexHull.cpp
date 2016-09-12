#include "Point.h"
#include "PointSet.h"
#include "iostream"
#define MIN_CONV_SIZE 3


int main()
{
    PointSet setInQuestion = PointSet();
    PointSet *retConvex;
    Point *pntInsert;
    while (!(std::cin.eof()))
    {
        int xNum, yNum;
        std::scanf("%d,%d\n", &xNum, &yNum);
        pntInsert = new Point(xNum, yNum);
        setInQuestion.add(*pntInsert);
    }

    if (setInQuestion.size() < MIN_CONV_SIZE)
    {
        *retConvex = setInQuestion;
    } else
    {
        retConvex = setInQuestion.convexSearch();
    }

    retConvex->sortForPrint();
    std::cout<<"result\n";
    retConvex->toString();
    delete retConvex;
    return 0;
}




