
/*
  Name: Utkrista Mardan Basnyat
  Course: COMSC-210 Data Structures
  Lab 23: Goat Manager 3001
  File: main.cpp
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
  srand(time(0));

  // read names from file
  ifstream fin("names.txt");
  string names[SZ_NAMES];
  int i = 0;

  while (i < SZ_NAMES && fin >> names[i])
    i++;

  fin.close();

  // read colors from file
  ifstream fin1("colors.txt");
  string colors[SZ_COLORS];
  i = 0;

  while (i < SZ_COLORS && fin1 >> colors[i])
    i++;

  fin1.close();

  // menu loop
  bool again = true;

  while (again) {
    int choice = main_menu();

    if (choice == 1) {
      cout << "Add a goat - coming soon!" << endl;
    }
    else if (choice == 2) {
      cout << "Delete a goat - coming soon!" << endl;
    }
    else if (choice == 3) {
      cout << "List goats - coming soon!" << endl;
    }
    else if (choice == 4) {
      cout << "Goodbye!" << endl;
      again = false;
    }
  }

  return 0;
}

// display menu and get a valid choice
int main_menu() {
  int choice;

  while (true) {
    cout << endl;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";

    if (cin >> choice && choice >= 1 && choice <= 4)
      return choice;

    if (cin.eof())
      return 4;

    cout << "Invalid choice. Please enter 1-4." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}
