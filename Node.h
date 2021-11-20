/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
/*Node class */
template <class T>
class Node{ //templated node 
    public:
        T data;
        Node *next;

        Node();
        Node(T d);
        ~Node();
};
template <class T>
Node<T>::Node(){ //default constructor

}
template <class T>
Node<T>::Node(T d){ //overloaded constructor
    data = d;
    next = nullptr;
}
template <class T>
Node<T>::~Node(){  //destructor 
    next = nullptr;
}

#endif