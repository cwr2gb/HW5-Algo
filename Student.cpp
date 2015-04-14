//Student.cpp
#include "Student.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

//Constructor
Student::Student(string s, int x){
  enroll = x;
  name = s;
}
//Adds a Class
void Student::addClass(string add){
  classes.push_back(add);
}
//Gets a class the student wants
bool Student::getClass(string c){
  for(int x = 0; x < classes.size(); x++){        
    if(classes[x] == c){
      return true;
    }
  }
  return false;
}
//Gets how many the classes the Studen is enrolled in
int Student::getEnrolled(){
  return enroll;
}
//Subtracts one from Enrollment total
void Student::minus(){
  enroll--;
}
//Adds one to Enrollment total
void Student::add(){
  enroll++;
}
//Returns student name
string Student::getName(){
  return name;
}
//Prints Class Requests
void Student::printRequests(){
  for(vector<string>::iterator x = classes.begin(); x != classes.end(); ++x){ 
    cout << *x << endl;
  }
}

