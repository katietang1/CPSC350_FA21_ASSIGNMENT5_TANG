/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#include <iostream>
#include "Windows.h"

//overloaded constructor
Windows::Windows(){
    idleTime = 0;
    processTime = 0;
    isOpen = true;
    processStart = 0;
    studentWait = 0;
}

//destructor
Windows::~Windows(){
}

void Windows::addStudent(Student s){
    student = s;
    this->processTime = s.needTime;
    this->isOpen = false;
    this->processStart = s.arrivalTime;
    this->studentWait = s.waitTime;
}

/* Stores idle time for each window*/
int Windows::getIdleTime(){
    return idleTime;
}
/* Incraments idle time for each window*/
void Windows::setIdleTime(int t){
    this->idleTime += t;
}
/* Check if window is open*/
bool Windows::getOpenStatus(){
    return isOpen;
}
/* Sets status based on isOpen*/
void Windows::setStatus(bool b){
    this->isOpen = b;
}