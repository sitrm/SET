#include <iostream>
#include "set.h"
using namespace std;
int main()
{
    Set A(10,20);
    A.add(11);
    A.add(12);
    A.add(13);
    Set B(10,20);
    B.add(11);
    B.add(12);
    Set C=A-B;
    cout<<C<<endl;
    


    return 0;
}