//
//  lab2test.cpp
//  lab02
//
//  Created by Sean on 1/26/14.
//  Copyright (c) 2014 Sean. All rights reserved.
//

#include <string.h>
#include <iostream>
#include <iomanip>
#include "SortSetArray.h"
#include "SortSetList.h"
#include <stdlib.h>
#include <sys/time.h>
#include <ctime>
using namespace std;

int main( int argc, char* argv[] ) {
SortSetArray constructorArrayTest1;
SortSetArray constructorArrayTest2(1);
SortSetArray constructorArrayTest3(1,2);
SortSetArray constructorArrayTest4(1,2,3);
SortSetArray constructorArrayTest5(1,2,3,4);
SortSetArray constructorArrayTest6(1,2,3,4,5);
SortSetArray constructorArrayTest7(constructorArrayTest6);

cout << constructorArrayTest1;
cout << constructorArrayTest2;
cout << constructorArrayTest3;
cout << constructorArrayTest4;
cout << constructorArrayTest5;
cout << constructorArrayTest6;
cout << constructorArrayTest7;



}