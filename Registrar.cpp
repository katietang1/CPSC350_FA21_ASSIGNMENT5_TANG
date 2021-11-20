/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 5: Registrar's Office
*/
/* Main body of program, runs registrar simulation until no students left then prints the stats*/
#include "Registrar.h"

//overloaded constructor
Registrar::Registrar(){
    studentWaitQueue = new GenQueue<Student>;
    studentWaitTime = new GenQueue<int>;
    currentTime = 0;
    totalWindow = 0;
}
//destructor
Registrar::~Registrar(){
}

//simulation starts by processing file then calling other methods to run and finally calls getStats
void Registrar::sim(){
    inFile.open(fileName); //file processing

    if (!inFile.is_open()){
        cout << "Cannot open file" << endl;
        return;
    }
    getline(inFile, line); 
    totalWindow = stoi(line); //convert input to int
    window = new Windows[totalWindow];
    for (int i = 0; i < totalWindow; i++){
        Windows m_Window;
        window[i] = m_Window;
    }
    //get time the student(s) arrive
    while (getline(inFile, line)) {
        if (stoi(line) != currentTime){
            int gapTime = stoi(line) - currentTime;
            currentTime = stoi(line);
            //Add time gaps to window idle time 
            windowUpdateIdle(gapTime);
        }
        checkWindowCompletion();
        processInput();
        assignStudentWindow();

        currentTime += 1;
        windowUpdateIdle(1);
    }

    bool keepRunning = true;
    // run until queue is empty
    while(keepRunning){
        if (studentWaitQueue->isEmpty()){
            windowLastPiece();
            keepRunning = false;
        }
        else{
            checkWindowCompletion();
            assignStudentWindow();
            currentTime += 1; //update tick
            windowUpdateIdle(1);
        }
    }
    //get and print stats data
    getStats();
}

/* Process file input and call appropriate functions*/
void Registrar::processInput(){
    getline(inFile, line);
    int comingStudent = stoi(line);
    //putting students in queue
    for (int i = 0; i < comingStudent; i++){
        Student s;
        getline(inFile, line);
        int currProcess = stoi(line);
        s.setNeedTime(currProcess);
        s.setArrivalTime(currentTime);
        studentWaitQueue->enqueue(s);
    }
}
/* Assign students to windows if windows are open*/
void Registrar::assignStudentWindow(){
  //Check if theres open window for students in waitlist
  for (int i = 0; i < totalWindow; i++){
      if (window[i].getOpenStatus()){
          if (!studentWaitQueue->isEmpty()){
              Student s = studentWaitQueue->dequeue();
              int currWaitTime = currentTime - s.arrivalTime;
              s.setWaitTime(currWaitTime);
              studentWaitTime->enqueue(currWaitTime); //adding wait time to queue 
              window[i].addStudent(s); //adding student to window
          }
      }
  }
}

/*Check if windows are empty */
void Registrar::checkWindowCompletion(){
    for (int i = 0; i < totalWindow; i++){
        if (window[i].processStart + window[i].processTime + window[i].studentWait == currentTime){
            window[i].setStatus(true);
        }
    }
}

/* Update idle time for window*/
void Registrar::windowUpdateIdle(int t){
    for (int i = 0; i < totalWindow; i++){
        if (window[i].getOpenStatus()){
            window[i].setIdleTime(t);
        }
    }
}
/* Making sure all windows are done */
void Registrar::windowLastPiece(){
    bool windowEmpty = false;
    while (!windowEmpty){
        int windowDone = 0;
        checkWindowCompletion();
        for (int i = 0; i < totalWindow; i++){
            if (window[i].getOpenStatus()){
                windowDone += 1;
            }
        }
        // if window is empty
        if (windowDone == totalWindow){
            windowEmpty = true;
        }
        else{
            currentTime += 1;
            windowUpdateIdle(1);
        }
    }
}

/* Calculate and print stats*/
void Registrar::getStats(){
    int studentNum = studentWaitTime->getSize();
    int studWaitArr[studentNum];
    int studWaitSum = 0, studWaitMax = 0, studWait10 = 0, windIdleSum = 0, windIdleMax = 0, windIdle5 = 0, studWaitArrPos;
    double studMean = 0.0, windMean = 0.0, studWaitMed = 0.0;

    int didNotWait = 0;
    // calculating student wait data
    for (int i = 0; i < studentNum; i++){
        int temp = studentWaitTime->dequeue();
        studWaitArr[i] = temp;

        if (temp == 0){
          didNotWait += 1;
        }
        studWaitSum += temp;
        // finding max
        if (studWaitMax < temp){
            studWaitMax = temp;
        }
        //getting students over 10
        if (temp >= 10){
            studWait10 += 1;
        }
    }

    // student mean
    studMean = (double)studWaitSum / (double)studentNum;

    //student median
    if (studentNum % 2 == 0){
          studWaitArrPos = (studentNum / 2) - 1;
          studWaitMed = (double)(studWaitArr[studWaitArrPos] + studWaitArr[studWaitArrPos + 1]) / (double)2;
     } else{
          studWaitArrPos = (studentNum - didNotWait + 1) / 2 -1;
          studWaitMed = studWaitArr[studWaitArrPos];
    }

    //calculating window idle data
    for (int i = 0; i < totalWindow; i++){
        int temp = window[i].getIdleTime();
        windIdleSum += temp;
        // window max
        if (windIdleMax < temp){
            windIdleMax = temp;
        }
        // window idle over 5
        if (temp > 5){
            windIdle5 += 1;
        }
    }
    // window mean
    windMean = (double)windIdleSum / (double)totalWindow;

    //Print out Stats Result
    cout << "<=========== Registrar Stats ===========>" << endl;
    cout << "1. The mean student wait time: ";
    cout << studMean << endl;
    cout << "2. The median student wait time: ";
    cout << studWaitMed << endl;
    cout << "3. The longest student wait time: ";
    cout << studWaitMax << endl;
    cout << "4. The number of students waiting over 10 minutes: ";
    cout << studWait10 << endl;
    cout << "5. The mean window idle time: ";
    cout << windMean << endl;
    cout << "6. The longest window idle time: ";
    cout << windIdleMax << endl;
    cout << "7. Number of windows idle for over 5 minutes: ";
    cout << windIdle5 << endl;
}