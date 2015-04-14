#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

using namespace std;

class Class {
public:
  Class(string s, int x);
  void addStudent(string addStu);
  void removeStudent(string removeStu);
  string getName();
  int getNumStu();
  int getCurrNumStu();
  bool canAddStu(string s);
  string name;
  int enrollStu;
  vector<string> students;
  int currEnroll;
 private:
  
};

#endif
