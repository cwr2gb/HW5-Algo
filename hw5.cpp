//Charles Regan
//cwr2gb
//hw5.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Student.h"
#include "Class.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
//Prototypes

//Global Variables

int main(int argc, char **argv){
  
  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  
  // attempt to open the supplied file
  ifstream file(argv[1]);
  
  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  FILE *fp = fopen(argv[1], "r");
  int regis, countR;
  int clases, countC;
  int numC, countN;
  while (regis != 0 && clases != 0 && numC != 0){
    file >> regis;
    countR = regis;
    file >> clases;
    countC = clases;
    file >> numC;
    countN = numC;
    
    if(regis == 0 && clases == 0 && numC == 0){
      break;
    }
    
    cout << "R: " << regis << " C: " << clases << " N: " << numC << endl;
    
    //Gets Registration requests
    vector<Student> stus;
    while(countR > 0){
      //Name of Student
      string name;
      file >> name;
      int test = 0;
      for(vector<Student>::iterator x = stus.begin(); x != stus.end(); ++x){        
	if(x->getName() == name ){
	  test++;
	}
      }
      //Class Requests
      string clas;
      file >> clas;
      //Handles if Students exist or not already
      if(test == 0){
	Student add = Student(name, numC);
	add.addClass(clas);
	stus.push_back(add);
      }
      else{
	for(vector<Student>::iterator y = stus.begin(); y != stus.end(); ++y){ 
	  if(y->getName() == name){
	    y->addClass(clas);
	  }
	}
      }
      //Takes one away from Requests
      countR--;
    }  
   
    //Gets Classes
    vector<Class> classes;  
    while(countC > 0){
      string clas2;
      file >> clas2;
      int stus;
      file >> stus;
      Class add = Class(clas2, stus);
      classes.push_back(add);
      countC--;
    }

    //Handles Putting Students in Classes Initally
    for(vector<Student>::iterator b = stus.begin(); b != stus.end(); ++b){
      for(vector<Class>::iterator c = classes.begin(); c !=classes.end(); ++c){
	if(b->getClass(c->getName())){
	  cout << b->getName() << " wants class: " << c->getName() << endl;
	  if(c->canAddStu(b->getName()) && c->getNumStu() != c->getCurrNumStu() && b->getEnrolled() > 0){
	    c->addStudent(b->getName());
	    b->minus();
	  }
	}
      }
    }
    for(vector<Class>::iterator a = classes.begin(); a != classes.end(); ++a){
      cout << a->getName() << " " << a->getNumStu() << " " << a->getCurrNumStu() << endl;
    }
    //DETERMINES FINAL OUTPUT
    int leftToEnroll = 0;
    for(vector<Student>::iterator w = stus.begin(); w != stus.end(); ++w){
      cout << w->getName() << " " << w->getEnrolled() << endl;
      leftToEnroll += w->getEnrolled();
    }
    cout << "Left to Enroll: " << leftToEnroll << endl;
    if(leftToEnroll ==0){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }    
    
  }
}











