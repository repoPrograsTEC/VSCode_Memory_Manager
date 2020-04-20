#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H



template<typename T>
struct Node {
    T *data;
    int value, ID;
    Node *next;
};

template<class T>
class LinkedList {
private:
    Node<T> *head, *tail;
    int length = 0;

public:
    LinkedList();

    void createNode(T*);
    void display();
    int getLength();
    Node<T>* getAtPosition(int);

    void insertAtFirst(T *);
    void insertAtEnd(T *);
    void insertAtPosition(int, T *);

    void deleteFirst();
    void deleteLast();
    void deleteAtPosition(int id);

    void assignAll(int, int);
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
