#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
  Student(string s, int x);
  void addClass(string add);
  bool getClass(string c);
  int getEnrolled();
  void add();
  void minus();
  void printRequests();
  string getName();
  string clas, name;
  int enroll;
  vector<string> classes;
 private:
  
};

#endif
