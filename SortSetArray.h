/**
 @file SortSetArray.h
 Contains the prototypes for SortSetArray.cpp
 Also contains the private variables.
 
 @author Sean Lai
 @author Sai Badey
 @section ASSIGNEMT Lab2
 @section DUE_DATE 26 Jan 2014
 */

#ifndef SORTSETARRAY_H
#define SORTSETARRAY_H

#include <iostream>
using namespace std;

class SortSetArray {
    // Output and Input overloading
    friend ostream& operator<<(ostream&, const SortSetArray set);
    friend istream& operator>>(istream&, SortSetArray set);
public:
    // Prototypes for the constructors. including the copy constuctor and destructor
    SortSetArray ();
    SortSetArray (int a);
    SortSetArray (int a, int b);
    SortSetArray (int a, int b, int c);
    SortSetArray (int a, int b, int c, int d);
    SortSetArray (int a, int b, int c, int d, int e);
    SortSetArray (const SortSetArray &other); // Copy constructor
    ~SortSetArray (); // Destructor
    
    int* setArray;// Creates the array
    // Below contains each of the overload for operators.
    SortSetArray operator+(const SortSetArray& target)const;
    SortSetArray operator*(const SortSetArray& target)const;
    SortSetArray operator-(const SortSetArray& target)const;
    SortSetArray operator=(const SortSetArray& target);
    SortSetArray operator+=(const SortSetArray& bSet);
    SortSetArray operator-=(const SortSetArray& bSet);
    SortSetArray operator*=(const SortSetArray& bSet);
    bool operator==(const SortSetArray& bSet)const;
    bool operator!=(const SortSetArray& bSet)const;
    // Prototypes for rest of the functions.
    bool insert(int target);
    void sortArray(int* setArray);
    int getSize()const;
    bool remove(int target);
    bool isInSet(int target)const;
    
private:
    // Size of the array
    int size;
};

#include "SortSetArray.cpp"
#endif

