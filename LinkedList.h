/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "Node.h"

using namespace std;
/*Linked List class with standard linked list functions */
template <class T>
class LinkedList{ //templated list 

private:
    Node<T> *front;
    Node<T> *back;
    unsigned int size;

public:
    LinkedList(); //constructor 
    ~LinkedList(); //destructor 

    void insertFront(T d);
    T removeFront();
    void insertBack(T d);
    T removeBack();

    T getBack();
    T getFront();

    T deleteAtPos(int pos);
    Node<T>* removeNode(T value);
    Node<T>* findPos(T pos);

    int find(T value);
    bool isEmpty();
    unsigned int getSize();
};

template <class T>
LinkedList<T>::LinkedList(){
    front = nullptr;
    back = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){

}

template <class T>
void LinkedList<T>::insertFront(T d){
    Node<T> *node = new Node<T>(d);
    if(front == nullptr) { //if list is empty
      back = node;
      front = node;
      return;
    }
    node -> next = front;
    front = node;
    ++size;
}

template <class T>
void LinkedList<T>::insertBack(T d){
    Node<T> *node = new Node<T>(d); //same as front but now back
    if (back == nullptr){
      back = node;
      front = node;
      ++size;
      return;
    }

    back->next = node;
    back = node;
    size++;
}

template <class T>
T LinkedList<T>::removeFront(){
    //check if empty
    if (front == nullptr){
        cout << "LinkedList is empty!" << endl;
    }
    else{
        Node<T> *node = front;
        if(front->next == NULL){
          back = NULL;
        }
  
        front = front->next;
        --size;
        node->next = NULL;
        T temp = node->data;

        delete node;
        return temp;
    }
}

template <class T>
T LinkedList<T>::removeBack(){
    //check if empty
    if (back == nullptr){
        cout << "LinkedList is empty!" << endl;

    }
    else if(back == front) {
      T temp = back -> data;
      front = NULL;
      back = NULL;
      size--;
      return temp;
    }
    else{
        T temp = back -> data;
        Node<T> *curr = front;
        while (curr -> next != back){
            curr = curr -> next;
        }
        curr -> next = NULL;
        back = curr;
        --size;
        return temp;
    }
}

template <class T>
T LinkedList<T>::getBack(){
    //check if empty
    if (size == 0){
        cout << "LinkedList is empty!" << endl;
    }
    else{
        T temp = back -> data;
        return temp;
    }
}

template <typename T>
T LinkedList<T>::getFront(){
  return front->data;
}

template <class T>
int LinkedList<T>::find(T value){
    int pos = -1;
    Node<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr ->data == value){
            break;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        pos=-1;
        cout << "Value not found" << endl;
    }

    return pos;
}

template <class T>
Node<T>* LinkedList<T>::findPos(T pos){

    Node<T> *curr = front;

    for(int i = 0; i < getSize(); i++){
        if(i != pos){
            curr = curr -> next;
        }else{
            return curr;
        }
    }
}

template <class T>
T LinkedList<T>::deleteAtPos(int pos){
    //error checking, you can always before you continue

    int nodePosition = 0;
    Node<T> *curr = front;
    Node<T> *prev = front;

    while(nodePosition != pos){
        prev = curr;
        curr = curr->next;
        ++nodePosition;
    }
    //found it
    prev->next = curr->next;
    curr->next = NULL;
    T d = curr->data;
    --size;
    delete curr;
    return d;
}

template <class T>
Node<T>* LinkedList<T>::removeNode(T value){
    
    Node<T> *node = findPos(value); //assume the find() function returns a pointer to ListNode

    if(node == NULL){
        return NULL;
    }
    Node<T> *curr = front;
    Node<T> *prev = front;

    while(curr != node){
        prev = curr;
        curr = curr->next;
    }

    if(node == front){
        front = front->next;
    }
    else if(node == back){
        prev->next = NULL;
        back = prev;
    }
    else{
        //its between front and back
        prev->next = curr->next;
        curr->next = NULL;
    }
    --size;
    return curr;

}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (size == 0);
}

template <class T>
unsigned int LinkedList<T>::getSize(){
    return size;
}




#endif