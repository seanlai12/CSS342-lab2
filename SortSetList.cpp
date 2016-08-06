//
//  SortSetList.cpp
//  lab02
//
//  Created by Sean on 1/25/14.
//  Copyright (c) 2014 Sean. All rights reserved.
//

#include "SortSetList.h"

#ifndef SORTSETLIST_CPP
#define SORTSETLIST_CPP

#include <string.h>
#include <iostream>
#include <iomanip>



using namespace std;


SortSetList::SortSetList() {
    head = NULL;
}

SortSetList::SortSetList (const SortSetList &other) {
    if(other.head == NULL){
        this->head = NULL;
    }
    else {
    this->head = other.head;
    Node* current = other.head;
    while (current->next != NULL) {
        current = current->next;
        this->insert(current->data);
        
        }
    }
}
SortSetList::SortSetList (int a) {
    if(a>=0)
        this->insert(a);
}
SortSetList::SortSetList (int a, int b) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
}
SortSetList::SortSetList (int a, int b, int c) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
    if(c>=0)
        this->insert(c);
}
SortSetList::SortSetList (int a, int b, int c, int d) {
    if(a>=0)
        this->insert(a);
    if(b>=0)
        this->insert(b);
    if(c>=0)
        this->insert(c);
    if(d>=0)
        this->insert(d);
}
SortSetList::SortSetList (int a, int b, int c, int d, int e) {
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

SortSetList::~SortSetList() {
    Node* current = head;
    while( current != NULL ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}


SortSetList SortSetList::operator=(const SortSetList& other) {
    this->head = other.head;
    Node* current = other.head;
    while (current->next != NULL) {
        delete current;
        current = current->next;
        this->insert(current->data);
        
    }
    return *this;
}


bool SortSetList::isEmpty() const {
    return head == NULL;
}

//----------------------------------------------------------------------------
// insert
// insert an item into list; operator< of the NodeData class
// has the responsibility for the sorting criteria
bool SortSetList::insert(int target) {
    Node* ptr= new Node;
    if (ptr == NULL) return false;                 // out of memory, bail
    ptr->data = target;                       // link the node to data
    
    // if the list is empty or if the node should be inserted before
    // the first node of the list
    if (isEmpty() || ptr->data < head->data) {
        ptr->next = head;
        head = ptr;
        return true;
    }
    
    // then check the rest of the list until we find where it belongs
    else {
        Node* current = head->next;          // to walk list
        Node* previous = head;               // to walk list, lags behind
        
        // walk until end of the list or found position to insert
        while (current != NULL && current->data <= ptr->data) {
            if(current->data == ptr->data){
                return false;
            }
            previous = current;                  // walk to next node
            current = current->next;
            
        
        }
        
        
        // insert new node, link it in
        ptr->next = current;
        previous->next = ptr;
        return true;
    }
    delete ptr;
    
}

bool SortSetList::remove(int target) {
	Node *previous = head;
	Node *current = head;
    
	if (head == NULL)
		return false;
	if (head->data == target) { // Case for deleting the first node.
		head->data = -1;
        head = head->next;
        delete previous;
		previous = NULL;
        current = NULL;
		return true;
	}
	while (current != NULL) { // Case for deleting non-first node.
		if (current->data != target) {
            previous = current;
			current = current->next;
		}
        else { // found data
            previous->next = current->next;
            current->data = -1;
            current->next = NULL;
            delete current;
            return true;
        }
	}
	return false;
}

SortSetList SortSetList::operator+(const SortSetList& bSet)const {
    SortSetList unionSet;
    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;

    bool aEnd = false;
    bool bEnd = false;
    

    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            unionSet.insert(aCurrent->data);
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            unionSet.insert(bCurrent->data);
            bCurrent = bCurrent->next;
        }
        else {
            
            unionSet.insert(bCurrent->data);
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
    }
    
    if (aCurrent==NULL) {
        aEnd = true;
    }
    else {
        bEnd = true;
    }
    
    if(aEnd && !bEnd) {
        while(bCurrent !=NULL) {
            unionSet.insert(bCurrent->data);
            bCurrent = bCurrent->next;
        }
    }
    else if (!aEnd && bEnd) {
        while(aCurrent !=NULL) {
            unionSet.insert(aCurrent->data);
            aCurrent = aCurrent->next;
        }
    }
    return unionSet;
}

SortSetList SortSetList::operator*(const SortSetList& bSet)const {
    SortSetList intersectionSet;
    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            bCurrent = bCurrent->next;
        }
        else {
            
            intersectionSet.insert(bCurrent->data);
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
    }

    return intersectionSet;
}

SortSetList SortSetList::operator-(const SortSetList& bSet)const {
    SortSetList differenceSet=*this;
//    cout << *this;
//    cout << bSet;
    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    
    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            bCurrent = bCurrent->next;
        }
        else {
            differenceSet.remove(bCurrent->data);
            
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
        
    }
    return differenceSet;
}

SortSetList SortSetList::operator-=(const SortSetList& bSet) {

    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    
    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            bCurrent = bCurrent->next;
        }
        else {
            this->remove(bCurrent->data);
            
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
        
    }
    return *this;
}

SortSetList SortSetList::operator+=(const SortSetList& bSet) {

    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    bool aEnd = false;
    bool bEnd = false;

    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            this->insert(aCurrent->data);
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            this->insert(bCurrent->data);
            bCurrent = bCurrent->next;
        }
        else {
            
            this->insert(bCurrent->data);
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
    }
    
    if (aCurrent==NULL) {
        aEnd = true;
    }
    else {
        bEnd = true;
    }
    
    if(aEnd && !bEnd) {
        while(bCurrent !=NULL) {
            this->insert(bCurrent->data);
            bCurrent = bCurrent->next;
        }
    }
    else if (!aEnd && bEnd) {
        while(aCurrent !=NULL) {
            this->insert(aCurrent->data);
            aCurrent = aCurrent->next;
        }
    }
    return *this;
}

SortSetList SortSetList::operator*=(const SortSetList& bSet) {
    
    Node *aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    while (aCurrent!=NULL && bCurrent!=NULL) {
        
        if(aCurrent->data < bCurrent->data) {
            aCurrent = aCurrent->next;
        }
        else if(aCurrent->data > bCurrent->data) {
            bCurrent = bCurrent->next;
        }
        else {
            
            this->insert(bCurrent->data);
            aCurrent = aCurrent->next;
            bCurrent = bCurrent->next;
        }
    }
    
    return *this;
}

bool SortSetList::operator==(const SortSetList& bSet)const {
    Node* aCurrent = this->head;
    Node *bCurrent = bSet.head;

    while (aCurrent->next != NULL) {
        if (aCurrent->data != bCurrent->data) {
            return false;
        }
        aCurrent = aCurrent->next;
        bCurrent = bCurrent->next;
    }
    return true;
}

bool SortSetList::operator!=(const SortSetList& bSet)const {
    Node* aCurrent = this->head;
    Node *bCurrent = bSet.head;
    
    while (aCurrent->next != NULL) {
        if (aCurrent->data != bCurrent->data) {
            return true;
        }
        aCurrent = aCurrent->next;
        bCurrent = bCurrent->next;
    }
    return false;
}

bool SortSetList::isInSet(int target)const {
    Node* aCurrent = this->head;
    
    while (aCurrent->next != NULL) {
        if (aCurrent->data == target) {
            return true;
        }
        aCurrent = aCurrent->next;
    }
    return false;
}

ostream& operator<<(ostream &output, const SortSetList& thelist) {
    
    SortSetList::Node* current = thelist.head;
    output << "{";
    while (current != NULL) {
        output <<  " " << current->data ;
        current = current->next;
    }
    output << "}";
    return output;
}

istream& operator>>(istream &input, SortSetList set) {
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

