#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H

#include "VSPtr.h"
#include <any>
#include <variant>
using std::any;
using std::variant;
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

    void display();

    int getLength();
    Node* getAtPosition(int);
    Node* getHead();

    template<typename T>
    void insertAtFirst(VSPtr<T> *);
    template<typename T>
    void insertAtEnd(VSPtr<T> *);
    template<typename T>
    void insertAtPosition(int, VSPtr<T> *);

    void deleteFirst();
    void deleteLast();
    template<typename T>
    void deleteAtPosition(VSPtr<T> *);
    template<typename T>
    void assignAll(int, int);
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
