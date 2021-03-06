// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
  int sum=0;
  Node* p;
  for(p=first;p!=NULL;p=p->next){
    sum=sum+p->info;
  }
  return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
  bool is_in=false;
  Node* p=first;
  while(is_in==false && p!=NULL){
    if(p->info==value)
      is_in = true;
    p=p->next;
  }
  return is_in;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
  Node* p;
  int max;
  if(first==NULL)
    max=0;
  else
    max=first->info;
  for(p=first;p!=NULL;p=p->next){
    if(p->info>max)
      max=p->info;
  }
  return max;
}


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
  if(first==NULL){
    return 0.0;
  }
  return 1.0*sum()/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
  Node* p=new Node;
  p->info=value;
  p->next=first;
  first=p;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
