#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H

#include "VSPtr.h"

template<typename T>
struct Node {
    VSPtr<T> *data;
    int ID;
    Node *next;
};

template<class T>
class LinkedList {
private:
    Node<T> *head, *tail;
    int length = 0;

public:
    LinkedList();

    void createNode(VSPtr<T> *);

    void display();
    int getLength();
    Node<T>* getAtPosition(int);
    Node<T>* getHead();

    void insertAtFirst(T *);
    void insertAtEnd(T *);
    void insertAtPosition(int, T *);

    void deleteFirst();
    void deleteLast();
    void deleteAtPosition(VSPtr<T> *);

    void assignAll(int, int);
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
