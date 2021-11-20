/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "GenQueue.h"
/*Student class stores and retrieves information about student */
class Student{

public:
    Student();
    ~Student();

    int waitTime;
    int needTime;
    int arrivalTime;

    void setWaitTime(int time);
    void setNeedTime(int time); 
    void setArrivalTime(int time);
    
};




#endif