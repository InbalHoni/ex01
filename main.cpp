#include <iostream>
#include "Point.h"
using namespace std;

int main() {
 /*   cout << "Hello, World!" << endl;
    Point pnt1 = Point(1,2);
    Point pnt2 = Point(3,4);*/
    int arr1[5] = {1, 2, 3, 4, 5 };
    int arr2[5] = {2, 5, 1, 4, 6 };
    int match = 0;
    for (int i = 0; i < 5; i++) // do according to _currFilled, or according to arrSize?
    {
        for(int j=0; j < 5; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i];
                match +=1;
            }
        }

    }
    if  (match ==5)
    {
        cout<< "dun in the sun";
    } else {
        cout<< "basush";
    }
    return 0;
}