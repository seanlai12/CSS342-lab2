/**
 @file SortSetArray.cpp
 Contains the constructors for SortSetArray, and all the 
 overload operators.
 
 @author Sean Lai
 @author Sai Badey
 @section ASSIGNEMT Lab2
 @section DUE_DATE 26 Jan 2014
 */


#include "SortSetArray.h"
#ifndef SORTSETARRAY_CPP
#define SORTSETARRAY_CPP
#include <string.h>
#include <iostream>
#include <iomanip>
#include "SortSetArray.h"
using namespace std;

/**
    Constructor that creates an array for 832040 numbers (30th # in fibonaccis)
 */
SortSetArray::SortSetArray () {
    setArray = new int[832040];
    size = 832041;
}

/**
 Constructor that creates a SortSetArray with given value, arr = {a}.
 @param a First number in the array
 */
SortSetArray::SortSetArray (int a) {
    if(a>=0)
        this->insert(a);
}
/**
 Constructor that creates a SortSetArray with given value, arr = {a, b}.
 @param a first number in the array
 @param b second number in the array
 */
SortSetArray::SortSetArray (int a, int b) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
}
/**
 Constructor that creates a SortSetArray with given value, arr = {a, b, c}.
 @param a first number in the array
 @param b second number in the array
 @param c third number in the array
 */
SortSetArray::SortSetArray (int a, int b, int c) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
    if(c>=0)
        this->insert(c);
}
/**
 Constructor that creates a SortSetArray with given value, arr = {a, b, c, d}.
 @param a first number in the array
 @param b second number in the array
 @param c third number in the array
 @param d fourth number in the array
 */
SortSetArray::SortSetArray (int a, int b, int c, int d) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
    if(c>=0)
        this->insert(c);
    if(d>=0)
        this->insert(d);
}
/**
 Constructor that creates a SortSetArray with given value, arr = {a, b, c, d, e}.
 @param a first number in the array
 @param b second number in the array
 @param c third number in the array
 @param d fourth number in the array
 @param e fifth number in the array
 */
SortSetArray::SortSetArray (int a, int b, int c, int d, int e) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
    if(c>=0)
        this->insert(c);
    if(d>=0)
        this->insert(d);
    if(e>=0)
        this->insert(e);
}

/**
 Constructor that creates a copy array. Copy constructor
 @param other the target array want to be copied
 */
SortSetArray::SortSetArray (const SortSetArray &other) {
    setArray = new int[832040];
    size = 832041;
    for (int i=0; i < other.getSize(); i++) {
        this->setArray[i] = other.setArray[i];
   }
}

/**
 Destructor for SortSetArray. deletes the Array.
 */
SortSetArray::~SortSetArray () {
    delete [] setArray;
    setArray = NULL;
}

/**
 Operator overload for +. It will create a returning unionSet SortSetArray.
 The union will contain union of all numbers in the two arrays.
 @param bSet the target array that you want to have a union with.
 @retun unionSet that contains the union of the two arrays.
 */
SortSetArray SortSetArray::operator+(const SortSetArray& bSet)const {

    SortSetArray unionSet = *this;
    
    for (int i=0; i < bSet.getSize(); i++) {
        if (bSet.setArray[i] >= 0 || this->setArray[i] >= 0) {
            unionSet.insert(this->setArray[i]);
            unionSet.insert(bSet.setArray[i]);
        }
    }
    return unionSet;
}

/**
 Operator overload for *. It will create a returning intersection SortSetArray.
 The intersection will contain the numbers that appears in both the given arrays.
 @param bSet the target array that you want to have a intersection with.
 @retun intersectionSet that contains the intersection of the two arrays.
 */
SortSetArray SortSetArray::operator*(const SortSetArray& bSet)const {
    
    SortSetArray intersectionSet;
    
    for (int i=0; i < bSet.getSize(); i++) {
        if (bSet.setArray[i] >= 0 && bSet.setArray[i] == this->setArray[i]) {
            intersectionSet.insert(bSet.setArray[i]);
        }
    }
    return intersectionSet;
}

/**
 Operator overload for -. It will create a returning difference SortSetArray.
 The difference will contain numbers that removes first array to second array
 @param bSet the target array that you want to have the integers removed.
 @retun differenceSet that contains the difference of the two arrays.
 */
SortSetArray SortSetArray::operator-(const SortSetArray& bSet)const {
    SortSetArray differenceSet = *this;
    
    for (int i=0; i < bSet.getSize(); i++) {
        if (bSet.setArray[i] >= 0) {
            differenceSet.remove(bSet.setArray[i]);
        }
    }
    return differenceSet;
}

/**
 Operator overload for =. It will assign the inserted array to the given array
 @param bSet the target array that you want to have the content copied.
 @retun original array with the new content being same as bSet.
 */
SortSetArray SortSetArray::operator=(const SortSetArray& bSet) {
    for (int i=0; i < bSet.getSize(); i++) {
        this->setArray[i] = bSet.setArray[i];
    }
    return *this;
}

/**
 Operator overload for +=. It will assign the union array to given array
 @param bSet the target array that you want to have the content combined
 @retun original array with the new content union with the bSet
 */
SortSetArray SortSetArray::operator+=(const SortSetArray& bSet) {
    
    for (int i=0; i < bSet.getSize(); i++) {
        if (bSet.setArray[i] >= 0) {
            this->insert(bSet.setArray[i]);
        }
    }
    return *this;
}

/**
 Operator overload for -=. It will assign the union array to given array
 @param bSet the target array that you want to have the content combined
 @retun original array with the new content union with the bSet
 */
SortSetArray SortSetArray::operator-=(const SortSetArray& bSet) {
    
    for (int i=0; i < bSet.getSize(); i++) {
        if (bSet.setArray[i] >= 0) {
            this->remove(bSet.setArray[i]);
        }
    }
    return *this;
}

/**
 Operator overload for *=. It will assign the intersected array to given array
 @param bSet the target array that you want to have the content checked for 
 intersection
 @retun original array with the new content intersecting with the bSet
 */
SortSetArray SortSetArray::operator*=(const SortSetArray& bSet) {
    
    for (int i=0; i < this->getSize(); i++) {
        if (!(this->setArray[i] >= 0 && bSet.setArray[i] >= 0)) {
            this->remove(i);
        }
        
    }
    return *this;
}

/**
 Operator overload for ==. give a boolean for whether the two SortSetArray is equal
 @param bSet the target array that you want to have the content checked
 @retun true if equal, false if not
 */
bool SortSetArray::operator==(const SortSetArray& bSet)const {
    
    for (int i=0;i < bSet.getSize(); i++) {
        if(this->setArray[i] != bSet.setArray[i]) {
            return false;
        }
    }
    return true;
}

/**
 Operator overload for !=. give a boolean for whether the two SortSetArray is not equal
 @param bSet the target array that you want to have the content checked
 @retun false if equal, true if not
 */
bool SortSetArray::operator!=(const SortSetArray& bSet)const {
    
    for (int i=0;i < bSet.getSize(); i++) {
        if(this->setArray[i] != bSet.setArray[i]) {
            return false;
        }
    }
    return true;
}

/**
 Inserting function for SortSetArray. It will insert the number into the array.
 It will simply check if the number at the index if a negative number, if so, changes it
 to the positive number equaling the index.
 @param target integer that you want to be inserted
 @retun true if something inserted, false if not.
 */
bool SortSetArray::insert(int target) {
    if (target < 0) {
        return false;
    }
    if(setArray[target] < 0){
        if (target == 0) {
            setArray[target] = 0;
        } else {
            setArray[target] *= -1;
            return true;
        }
    }
    return false;
    
}

/**
 Removing function for SortSetArray. It will remove the number from the array.
 It will simply check if the number at the index if a positive number, if so, changes it
 to the negative number equaling the index.
 @param target integer that you want to be removed
 @retun true if something removed, false if not.
 */
bool SortSetArray::remove(int target) {
    if(setArray[target] >= 0){
        if (target == 0) {
            setArray[target] = -1;
        } else {
            setArray[target] *= -1;
            return true;
        }
    }
    return false;
}

/**
 Returns the size of a SetArray
 @retun size Size of the setArray
 */
int SortSetArray::getSize()const {
    return size;
}

/**
 Checks if the target interger is contained in the SortedSetArray
 @param target integer that you want to check
 @retun true if target is contained in the array, false if not.
 */
bool SortSetArray::isInSet(int target)const {
    for (int i=0; i<this->getSize(); i++) {
        if (this->setArray[target] >= 0) {
            return true;
        }
    }
    return false;
}

/**
 Operator overload for <<. Prints out the contents of the array.
 It will only print the content that's positive, which means it's a value.
 Seperated by space, all between brackets.
 @param output the output ostream
 @param set the SortArraySet that you want to print out in the console.
 @retun output the output
 */
ostream& operator<<(ostream &output, const SortSetArray set) { 
    output << "{";
    for (int i=0; i < set.getSize(); i++) {
        if (set.setArray[i] >= 0) {
        output << " " << set.setArray[i];
        }
    }
    output << "}";
    return output;
}

/**
 Operator overload for >>. Allows the user to input contents into the SortSetArray
 The function will keep inserting new values as long if it's not negative intergers.
 Entering -1 will break the function.
 @param input the istream input
 @param set the SortArraySet that you want to insert integers in
 @retun input the input
 */
istream& operator>>(istream &input, SortSetArray set) {
    bool exit = false;
    int target;
    while (!exit) {
        input >> target;
        if (target == -1) {
            exit = true;
        }
        else if (target >= 0){
            set.insert(target);
        }
    }

    return input;
}
#endif
