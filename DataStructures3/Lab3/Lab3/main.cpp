//
//  main.cpp
//  Lab3
//
//  Created by Jeffrey Kayzerman on 8/19/15.
//  Copyright (c) 2015 Jeffrey Kayzerman. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
void computeSquares( unsigned int * a, unsigned int * b, unsigned int n )
{
    unsigned int *p;

    for ( p=b; p<b+n; ++p )
        *p = pow( *(a + (p-b)), 2 );
}

void test(){
    double * p = new double;
    *p = 35.1;
    double * q = p;
    cout << *p << " " << *q << endl;
    p = new double;
    *p = 27.1;
    cout << *p << " " << *q << endl;
    *q = 12.5;
    cout << *p << " " << *q << endl;
    delete p;
    delete q;
}

// main function to call above defined function.
int main ()
{
    const unsigned int n = 10;
    unsigned int a[n] = { 10, 4, 2, 3, 5, 6, 7, 8, 9, 10 };
    unsigned int b[n];
    
    computeSquares( a, b, n );
    
    test();
    
    return 0;
}