#ifndef VSPTR_LINKEDLIST_H
#define VSPTR_LINKEDLIST_H

#include "VSPtr.h"
using std::string;

struct VSPtrType{
    VSPtr<int> *intType;
    VSPtr<float> *floatType;
    VSPtr<double> *doubleType;
    VSPtr<long> *longType;
    VSPtr<char> *charType;
    VSPtr<string> *stringType;
    VSPtr<bool> *boolType;
};

struct Node {
    VSPtrType data = VSPtrType();
    string dataType;
    int ID;
    Node *next;
};


class LinkedList {
private:
    Node *head, *tail;
    int length = 0;

public:
    LinkedList();
    template<typename T>
    void createNode(VSPtr<T> *);

    int getLength();

    Node* getHead();
    template<typename T>
    void deleteAtPosition(VSPtr<T> *);
};
#endif
