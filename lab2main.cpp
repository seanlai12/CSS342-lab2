/**
 @file lab2main.cpp
 This is the lab2main source file that creates SortSetArray and SortSetLists,
 it will fill them with Fibonacci or prime numbers and tests each overloaded 
 operator functions. Will calculate the time difference between Array and LinkedLists.
 
 @author Sean Lai
 @author Sai Badey
 @section ASSIGNEMT Lab2
 @section DUE_DATE 26 Jan 2014
 */

#include <string.h>
#include <iostream>
#include <iomanip>
#include "SortSetArray.h"
#include "SortSetList.h"
#include <stdlib.h>
#include <sys/time.h>
#include <ctime>
using namespace std;

// Prototypes for functions
void getFibonacciArray(SortSetArray *sFibonaccis);
void getPrimeArray(SortSetArray *sPrimes);
void getFibonacciList(SortSetList *sFibonacci);
void getPrimeList(SortSetList *sPrimes);

// Main function
int main( int argc, char* argv[] ) {
    clock_t clockTimeStart, clockTimeEnd;
    
    // Creates all the Arrays and Lists for both Fibonacci and Primes
    SortSetArray sFibonacciArr;
    SortSetArray sPrimeArr;
    SortSetList sFibonacciList;
    SortSetList sPrimeList;
    getFibonacciArray(&sFibonacciArr);
    getPrimeArray(&sPrimeArr);
    getFibonacciList(&sFibonacciList);
    getPrimeList(&sPrimeList);
    
    clock_t ticks;
    
    // Calculates time to run each instances below.
    // For +, -, *, +=, -=, *=, ==, != and compares Array vs LinkedList
    clockTimeStart = clock();
    sFibonacciArr + sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr + sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList + sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList + sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciArr - sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr - sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList - sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList - sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciArr * sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr * sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList * sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList * sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciArr += sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr += sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList += sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList += sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciArr -= sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr -= sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList -= sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList -= sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciArr *= sPrimeArr;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr *= sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList *= sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList *= sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    if (sFibonacciArr == sPrimeArr){
        
    }
    
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr == sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    if (sFibonacciList == sPrimeList){
        
    }
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList == sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    sFibonacciList *= sPrimeList;
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList *= sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    if (sFibonacciArr != sPrimeArr){
        
    }
    
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciArr != sPrimeArr " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    clockTimeStart = clock();
    if (sFibonacciList != sPrimeList){
        
    }
    clockTimeEnd = clock();
    ticks = clockTimeEnd - clockTimeStart;
    cout << "sFibonacciList != sPrimeList: " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
}

/**
 Fill the inserted SortSetArray with Fibonacci numbers to the index of getSize()
 
 @param[*sFibonaccis] The SortSetArray that you want to fill Fibonacci numbers with
 @return void
 */
void getFibonacciArray(SortSetArray *sFibonaccis){
    for (int i=0; i<= sFibonaccis->getSize(); i++) {
        sFibonaccis->setArray[i] = -i;
    }
    int f0 = 0;
    int f1 = 1;
    sFibonaccis->setArray[1] *= -1;
    for (int i=2; i <= 31; i++) {
        f1 = f1 + f0;
        f0 = f1 - f0;
        sFibonaccis->insert(f0);
    }
}

/**
 Fill the inserted SortSetArray with Prime numbers to the index of getSize()
 It uses the sieve of eratosthenes algorithm
 
 @param[*sFibonaccis] The SortSetArray that you want to fill Fibonacci numbers with
 @return void
 */
void getPrimeArray(SortSetArray *sPrimes) {
    
    for (int i=0; i<= sPrimes->getSize(); i++) {
        sPrimes->setArray[i] = i;
    }
	for(int i = 2; i < sPrimes->getSize()-1; i++)
	{
		for(int j = 2; (j*i) < sPrimes->getSize(); j++)
		{
            sPrimes->setArray[j*i] = -j*i;
        }
        
    }
    sPrimes->remove(0);
    sPrimes->remove(1);
}

/**
 Fill the inserted SortSetList with Fibonacci numbers to the index of getSize()
 
 @param[*sFibonaccis] The SortSetList that you want to fill Fibonacci numbers with
 @return void
 */
void getFibonacciList(SortSetList *sFibonaccis) {

    int f0 = 0;
    int f1 = 1;
    for (int i=2; i <= 31; i++) {
        f1 += f0;
        f0 = f1 - f0;
        sFibonaccis->insert(f0);
    }
    sFibonaccis->remove(1);
}

/**
 Fill the inserted SortSetList with Prime numbers to the index of getSize()
 It uses the sieve of eratosthenes algorithm
 
 @param[*sFibonaccis] The SortSetList that you want to fill Fibonacci numbers with
 @return void
 */
void getPrimeList(SortSetList *sPrimes) {
    int* insertArray = new int[834020];
    // Creates an array and fill them using the sieve of eratosthenes algorithm,
    // then creates a linked list using those numbers
    for (int i=0; i<= 834020; i++) {
        insertArray[i] = i;
    }
	for(int i = 2; i < 834020; i++)
	{
		for(int j = 2; (j*i) < 834020; j++)
		{
            insertArray[j*i] = -j*i;
        }
        
    }
    for (int i=0; i < 834020; i++) {
        if(insertArray[i] >= 0) {
            sPrimes->insert(insertArray[i]);
        }
    }
    sPrimes->remove(0);
    sPrimes->remove(1);
    
}


