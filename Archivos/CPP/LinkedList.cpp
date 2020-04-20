#include <iostream>
#include "../Headers/LinkedList.h"
using std::cout;
using std::endl;

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    tail = NULL;
}

template<class T>
void LinkedList<T>::createNode(T *value){
    length++;
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->value = *value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        // ID PARA EL NODO DE LA LISTA
        temp->ID = this->getLength();
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
        // ID PARA EL NODO DE LA LISTA
        tail->ID = this->getLength();
    }
}
template<class T>
void LinkedList<T>::display(){
    Node<T> *temp = new Node<T>;
    temp = head;
    cout << endl << "¡IMPRIMIENDO LISTA! " << endl;
    while(temp != NULL){
        cout << "       ID: " << temp->ID << "  ";
        cout << "   VSPTR: " << temp->data << "  ";
        cout << "   Value: " << temp->value << endl;
        temp = temp->next;
    }
    cout << endl << "**************************************************** " << endl;
}
template<class T>
int LinkedList<T>::getLength() {
    return length;
}
template<class T>
Node<T>* LinkedList<T>::getAtPosition(int id){
    Node<T> *current = new Node<T>;
    Node<T> *previous = new Node<T>;
    current = head;

    int i = 1;
    while (i != id){
        previous = current;
        current = current->next;
        i++;
    }

    return current;
}

template<class T>
void LinkedList<T>::insertAtFirst(T* value){
    length++;
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = head;
    temp->ID = this->getLength() + 1;
    head = temp;
}
template<class T>
void LinkedList<T>::insertAtEnd(T* value){
    length++;
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->ID = this->getLength();
        temp = NULL;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->ID = this->getLength();
    }
}
template<class T>
void LinkedList<T>::insertAtPosition(int pos, T* value){
    length++;
    Node<T> *previous = new Node<T>;
    Node<T> *current = new Node<T>;
    Node<T> *temp = new Node<T>;
    current = head;
    for(int i = 1; i < pos; i++){
        previous = current;
        current = current->next;
    }
    temp->data = value;

    //ASIGNACIÓN DE ID
    int mayor = 0;
    Node<T> *temp2 = new Node<T>;
    temp2 = head;
    while(temp2 != NULL){
        if (temp2->ID > mayor){
            mayor = temp2->ID;
        }
        temp2 = temp2->next;
    }
    temp->ID = mayor + 1;

    previous->next = temp;
    temp->next = current;
}

template<class T>
void LinkedList<T>::deleteFirst(){
    length--;
    Node<T> *temp = new Node<T>;
    temp = head;
    head = head->next;
    delete temp;
}
template<class T>
void LinkedList<T>::deleteLast(){
    length--;
    Node<T> *current = new Node<T>;
    Node<T> *previous = new Node<T>;
    current = head;
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
}
template<class T>
void LinkedList<T>::deleteAtPosition(int id){
    if (id == 1){
        deleteFirst();
    }else {
        length--;
        Node<T> *current = new Node<T>;
        Node<T> *previous = new Node<T>;
        current = head;

        for (int i = 1; i < id; i++) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
    }
}
template<class T>
void LinkedList<T>::assignAll(int id, int sp){
    Node<T> *temp = new Node<T>;
    temp = head;
    while(temp != NULL){
        if (temp->data == (GarbageCollector<T>::getList()->getAtPosition(id))->data){
            temp->value = sp;
        }
        temp = temp->next;
    }
}