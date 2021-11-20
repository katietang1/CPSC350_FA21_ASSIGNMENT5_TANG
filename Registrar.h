/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
#ifndef REGISTRAR_H
#define REGISTRAT_H

#include <iostream>
#include <fstream>
#include "Windows.h"

using namespace std;

class Registrar{

    public:

    Registrar();
    ~Registrar();

    GenQueue<Student> *studentWaitQueue; //Queue of type student
    GenQueue<int> *studentWaitTime; //Queue that stores each student wait time

    ifstream inFile;
    string fileName;
    string line;

    int currentTime;
    int totalWindow;
    Windows *window;

    void sim(); 
    void processInput(); 
    void assignStudentWindow();
    void checkWindowCompletion();
    void windowUpdateIdle(int time);
    void windowLastPiece();
    void getStats(); 

};
#endif
