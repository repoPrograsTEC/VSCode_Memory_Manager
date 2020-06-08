#include <iostream>
#include <assert.h>
#include "../Headers/LinkedList.h"
using std::cout;
using std::endl;

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}
template<typename T>
void LinkedList::createNode(VSPtr<T> *pVsPtr){
    length++;

    Node *temp = new Node;

   if (typeid(T) == typeid(int)){
       (temp->data).intType = (VSPtr<int>*)pVsPtr;
       temp->dataType = typeid(int).name();
   } else if (typeid(T) == typeid(float)){
       (temp->data).floatType = (VSPtr<float>*)pVsPtr;
       temp->dataType = typeid(float).name();
   } else if (typeid(T) == typeid(double)){
       (temp->data).doubleType = (VSPtr<double>*)pVsPtr;
       temp->dataType = typeid(double).name();
   } else if (typeid(T) == typeid(long)){
       (temp->data).longType = (VSPtr<long>*)pVsPtr;
       temp->dataType = typeid(long).name();
   } else if (typeid(T) == typeid(char)){
       (temp->data).charType = (VSPtr<char>*)pVsPtr;
       temp->dataType = typeid(char).name();
   } else if (typeid(T) == typeid(string)){
       (temp->data).stringType = (VSPtr<string>*)pVsPtr;
       temp->dataType = typeid(string).name();
   } else if (typeid(T) == typeid(bool)){
       (temp->data).boolType = (VSPtr<bool>*)pVsPtr;
       temp->dataType = typeid(bool).name();
   }

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

void LinkedList::display(){
    Node *temp = new Node;
    temp = head;
    cout << endl << "¡IMPRIMIENDO LISTA! " << endl;
    while(temp != NULL){
        if (temp->dataType == typeid(int).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).intType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << ((temp->data).intType)->getAddress() << "  ";
            cout << "       *PTR: " << *(((temp->data).intType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(float).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).floatType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << ((temp->data).floatType)->getAddress() << "  ";
            cout << "       *PTR: " << *(((temp->data).floatType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(double).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).doubleType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << ((temp->data).doubleType)->getAddress() << "  ";
            cout << "       *PTR: " << *(((temp->data).doubleType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(long).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).longType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << ((temp->data).longType)->getAddress() << "  ";
            cout << "       *PTR: " << *(((temp->data).longType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(char).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).charType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << static_cast<void *>(((temp->data).charType)->getAddress()) << "  ";
            cout << "       *PTR: " << *(((temp->data).charType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(string).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).stringType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << static_cast<void *>(((temp->data).stringType)->getAddress()) << "  ";
            cout << "       *PTR: " << *(((temp->data).stringType)->getAddress()) << endl;
            temp = temp->next;
        } else if (temp->dataType == typeid(bool).name()){
            cout << "       INSTANCIA VSPOINTER : " << (temp->data).boolType << "  ";
            cout << "       ID: " << temp->ID << "  ";
            cout << "       PTR: " << static_cast<void *>(((temp->data).boolType)->getAddress()) << "  ";
            cout << "       *PTR: " << *(((temp->data).boolType)->getAddress()) << endl;
            temp = temp->next;
        }
    }
    cout << endl << "****************************************************"
                    "**************************************************** " << endl;
}

int LinkedList::getLength() {
    return length;
}
Node* LinkedList::getAtPosition(int id){
    Node *current = new Node;
    Node *previous = new Node;
    current = head;

    int i = 1;
    while (i != id){
        previous = current;
        current = current->next;
        i++;
    }

    return current;
}
Node *LinkedList::getHead() {
    return this->head;
}

template<class T>
void LinkedList::insertAtFirst(VSPtr<T> *value){
    length++;
    Node *temp = new Node;
    temp->data = value;
    temp->next = head;
    temp->ID = this->getLength() + 1;
    head = temp;
}
template<class T>
void LinkedList::insertAtEnd(VSPtr<T> *value){
    length++;
    Node *temp = new Node;
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
void LinkedList::insertAtPosition(int pos, VSPtr<T> *value){
    length++;
    Node *previous = new Node;
    Node *current = new Node;
    Node *temp = new Node;
    current = head;
    for(int i = 1; i < pos; i++){
        previous = current;
        current = current->next;
    }
    temp->data = value;

    //ASIGNACIÓN DE ID
    int mayor = 0;
    Node *temp2 = new Node;
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

void LinkedList::deleteFirst(){
    length--;
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}
void LinkedList::deleteLast(){
    length--;
    Node *current = new Node;
    Node *previous = new Node;
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
void LinkedList::deleteAtPosition(VSPtr<T> *vsPtr){
    length--;
    Node *current = new Node;
    Node *previous = new Node;
    current = head;

    for(int i = 0; i < this->getLength(); i++){
        if (typeid(T) == typeid(int) && (current->data.intType) == (VSPtr<int>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(float) && (current->data.floatType) == (VSPtr<float>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(double) && (current->data.doubleType) == (VSPtr<double>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(long) && (current->data.longType) == (VSPtr<long>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(char) && (current->data.charType) == (VSPtr<char>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(string) && (current->data.stringType) == (VSPtr<string>*)vsPtr){
            previous->next = current->next;
            break;
        } else if (typeid(T) == typeid(bool) && (current->data.boolType) == (VSPtr<bool>*)vsPtr){
            previous->next = current->next;
            break;
        } else{
            previous = current;
            current = current->next;
        }
    }
}