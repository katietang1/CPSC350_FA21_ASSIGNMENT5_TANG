/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#ifndef GENQUEUE_H
#define GENQUEUE_H

#include "LinkedList.h"
/*GenQueue class made with linked list */
template<class T>
class GenQueue{
  public:
    GenQueue();
    ~GenQueue();

    // functions
    void enqueue(T d); //push from back
    T dequeue(); //pop from front
    T peek();
    bool isEmpty();
    int getSize();
  private:
    LinkedList<T> *list; 
    int size;
};

template<class T>
GenQueue<T>::GenQueue(){
    list = new LinkedList<T>;
    size = 0;
}

template<class T>
GenQueue<T>::~GenQueue(){}

template<class T>
void GenQueue<T>::enqueue(T d){
  list->insertBack(d);
  ++size;
}

template<typename T>
T GenQueue<T>::dequeue(){
  //check if empty
  if(isEmpty()){
    throw runtime_error("Queue is empty!");
  }
  else{
    --size;
    return (list->removeFront());
  }
}

template<typename T>
T GenQueue<T>::peek(){
  //check if empty
  if(isEmpty()){
    throw runtime_error("Queue is empty!");
  }
  else{
    return list->getFront();
  }
}

template<typename T>
bool GenQueue<T>::isEmpty(){
    return list->isEmpty();
}

template<typename T>
int GenQueue<T>::getSize(){
    return list->getSize();
}


#endif