
#ifndef SORTSETLIST_H
#define SORTSETLIST_H

#include <iostream>
#include <fstream>
using namespace std;


    class SortSetList {
        friend ostream &operator<<(ostream&, const SortSetList&);
        friend istream &operator>>(istream& input, SortSetList set);
        
    public:
        SortSetList();
        SortSetList (int a);
        SortSetList (int a, int b);
        SortSetList (int a, int b, int c);
        SortSetList (int a, int b, int c, int d);
        SortSetList (int a, int b, int c, int d, int e);
        ~SortSetList();        
        SortSetList (const SortSetList &other);
        bool insert(int target);
        bool isEmpty() const;
        bool remove(int target);
        SortSetList operator+(const SortSetList& target)const;
        SortSetList operator*(const SortSetList& bSet)const;
        SortSetList operator-(const SortSetList& bSet)const;
        SortSetList operator=(const SortSetList& other);
        SortSetList operator+=(const SortSetList& bSet);
        SortSetList operator-=(const SortSetList& bSet);
        SortSetList operator*=(const SortSetList& bSet);
        bool operator==(const SortSetList& bSet)const;
        bool operator!=(const SortSetList& bSet)const;
        bool isInSet(int target)const;
        
    private:
        struct Node {
            int data;
            Node* next;
        };
        
        Node* head;                                 // pointer to first node in list
    };

#include "SortSetList.cpp"
#endif


