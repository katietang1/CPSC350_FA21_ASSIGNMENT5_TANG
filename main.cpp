/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
/*main method */
#include <iostream>
#include "Registrar.h"

using namespace std;

int main (int argc, char **argv){
    string fileName;
    cout << "Welcome to the University Registrar" << endl;

    if (argc = 2){
        fileName = argv[1];
        Registrar reg;
        reg.fileName = fileName;
        reg.sim();
    }
    else if (argc < 2){
        cout << "No file name input, please try again" << endl;
        return 0;
    } else if (argc > 2){
        cout << "Only 2 commands, please try again" << endl;
        return 0;
    } else {
        cout << "Invalid. Please try again" << endl;
        return 0;
    }

}
