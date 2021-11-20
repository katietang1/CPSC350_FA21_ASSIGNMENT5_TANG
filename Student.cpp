/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/

#include <iostream>
#include "Student.h"

//overloaded constructor
Student::Student(){
    needTime = 0;
    waitTime = 0;
    arrivalTime = 0;
}

//destructor
Student::~Student(){
}

/* stores how much time is needed at window*/
void Student::setNeedTime(int time){
    needTime = time;
}
/* stores how long they wait in queue */
void Student::setWaitTime(int time){
    waitTime = time;
}
/* stores the tick they arrived*/
void Student::setArrivalTime(int time){
    arrivalTime = time;
}