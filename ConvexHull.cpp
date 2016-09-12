#include "Point.h"
#include "PointSet.h"
#define MIN_CONV_SIZE 3


int main()
{
    PointSet setInQuestion = PointSet();
    PointSet* retConvex;
    Point pntInsert;
    int xNum, yNum;
    char comma;
    /*int i = 0;
    while (i<5)*/
    while (std::cin >> xNum >> comma >> yNum)
    {

        std::scanf("%d,%d\n", &xNum, &yNum);
        pntInsert = Point(xNum, yNum);
        setInQuestion.add(pntInsert);
//        i++;
    }

    if (setInQuestion.size() < MIN_CONV_SIZE)
    {
        *retConvex = setInQuestion;
    } else
    {
        retConvex = setInQuestion.convexSearch();
    }

    retConvex->sortForPrint();
    std::cout<<"result\n"<<retConvex->toString();
    delete retConvex;
    return 0;
}




