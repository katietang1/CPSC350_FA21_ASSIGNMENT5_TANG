/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/

#ifndef WINDOWS_H
#define WINDOWS_H

#include <iostream>
#include "Student.h"
/*Windows class contains windows data and an instance of student */
using namespace std;

class Windows{
    public:
    Windows();
    ~Windows();

    int idleTime;
    int processTime;
    int processStart; 
    int studentWait;
    
    void addStudent(Student student);
    void setIdleTime(int time);
    int getIdleTime();
    bool getOpenStatus(); 
    void setStatus(bool b);

    private:
    Student student;
    bool isOpen;
};



#endif