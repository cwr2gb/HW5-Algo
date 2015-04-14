//Class.cpp
#include "Class.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

//Constructor
Class::Class(string s, int x){
  enrollStu = x;
  name = s;
  currEnroll = 0;
}
//Adds a Student
void Class::addStudent(string addStu){
  currEnroll++;
  students.push_back(addStu);
}
//Gets Class Name
string Class::getName(){
  return name;
}
//Removes a Student
void Class::removeStudent(string removeStu){
  currEnroll--;
  int count = 0;
  for(vector<string>::iterator x = students.begin(); x != students.end(); ++x){
    count++;
    if(*x == removeStu)
      students.erase(students.begin()+count);
  }
}
//Gets how many Students can be enrolled in the class
int Class::getNumStu(){
  return enrollStu;
}
//Gets how many Students are enrolled in the class
int Class::getCurrNumStu(){
  return currEnroll;
}
//Checks if student is already enrolled in class or not
bool Class::canAddStu(string s){
  for(vector<string>::iterator x = students.begin(); x != students.end(); ++x){
    if(*x == s)
      return false;
  }
  return true;
}

