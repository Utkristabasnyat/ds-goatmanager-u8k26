
/*
  Name: Utkrista Mardan Basnyat
  Course: COMSC-210 Data Structures.
  Lab 23: Goat Manager 3001
  File: Goat.h
*/

#ifndef GOAT_H
#define GOAT_H

#include <iostream>
#include <string>
using namespace std;

class Goat {
private:
  string name;
  int age;
  string color;

public:
  // default constructor
  Goat() {
    name = "";
    age = 0;
    color = "";
  }

  // constructor with name
  Goat(string n) {
    name = n;
    age = 0;
    color = "";
  }

  // constructor with name and age
  Goat(string n, int a) {
    name = n;
    age = a;
    color = "";
  }

  // constructor with all three values
  Goat(string n, int a, string c) {
    name = n;
    age = a;
    color = c;
  }

  // setters and getters
  void set_name(string n) {
    name = n;
  }

  string get_name() const {
    return name;
  }

  void set_age(int a) {
    age = a;
  }

  int get_age() const {
    return age;
  }

  void set_color(string c) {
    color = c;
  }

  string get_color() const {
    return color;
  }
};

#endif
