// intlist.cpp
// Implements class IntList
// Amol Bhat, 4/18/25

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    Node* current = source.head;
    while (current) {
        push_back(current->info);
        current = current->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int total = 0; 
    Node* current = head;
    while(current) {
        total += current->info;
        current = current->next;

    }
    return total; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;
    while(current) {
        if(current->info == value) return true;
        current = current->next;
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) return 0; 
    int maxVal = head->info; 
    Node* current = head->next;
    while (current) {
        if (current->info > maxVal) maxVal = current->info; 
        current = current->next;
    }
    return maxVal; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr){
        return 0.0;
    }
    int total = sum();
    int num = count();

    return (double) total / num;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    if(!tail) tail = head; 
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head){
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
    


// return count of values
int IntList::count() const {
   int cnt = 0;
   Node* current = head;
   while (current){
    cnt++;
    current = current->next; 
   }
   return cnt;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this != &source) {
        //Delete existing nodes
        Node* current = head;
        while(current) {
            Node* nextNode = current->next; 
            delete current;
            current = nextNode;

        }
        head = tail = nullptr;

        // Deep Copy 
        Node* src = source.head; 
        while(src) {
            push_back(src->info);
            src = src->next;
        }
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

