
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

  string names[SZ_NAMES];
  string colors[SZ_COLORS];

  // read goat names
  ifstream fin("names.txt");
  int nameCount = 0;

  while (nameCount < SZ_NAMES && fin >> names[nameCount])
    nameCount++;

  fin.close();

  // read goat colors
  ifstream fin1("colors.txt");
  int colorCount = 0;

  while (colorCount < SZ_COLORS && fin1 >> colors[colorCount])
    colorCount++;

  fin1.close();

  if (nameCount != SZ_NAMES || colorCount != SZ_COLORS) {
    cout << "Error: Could not load names and colors." << endl;
    return 1;
  }

  list<Goat> trip;
  bool again = true;

  while (again) {
    int choice = main_menu();

    if (choice == 1) {
      add_goat(trip, names, colors);
    }
    else if (choice == 2) {
      delete_goat(trip);
    }
    else if (choice == 3) {
      display_trip(trip);
    }
    else if (choice == 4) {
      cout << endl << "Thank you for using Goat Manager 3001!" << endl;
      again = false;
    }
  }

  return 0;
}

// show main menu and validate choice
int main_menu() {
  int choice;

  while (true) {
    cout << endl;
    cout << "================================" << endl;
    cout << "       GOAT MANAGER 3001        " << endl;
    cout << "================================" << endl;
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

// add a randomly generated goat
void add_goat(list<Goat> &trip, string names[], string colors[]) {
  string name = names[rand() % SZ_NAMES];
  int age = rand() % (MAX_AGE + 1);
  string color = colors[rand() % SZ_COLORS];

  Goat newGoat(name, age, color);
  trip.push_back(newGoat);

  cout << endl;
  cout << "----- GOAT ADDED -----" << endl;
  cout << "Name : " << newGoat.get_name() << endl;
  cout << "Age  : " << newGoat.get_age() << endl;
  cout << "Color: " << newGoat.get_color() << endl;
  cout << "----------------------" << endl;
  cout << "Total goats: " << trip.size() << endl;
}

// display all goats in a table
void display_trip(list<Goat> trip) {
  cout << endl;
  cout << "========== CURRENT GOATS ==========" << endl;

  if (trip.empty()) {
    cout << "No goats in the trip." << endl;
    cout << "===================================" << endl;
    return;
  }

  cout << left
       << setw(6) << "No."
       << setw(12) << "Name"
       << setw(7) << "Age"
       << "Color" << endl;
  cout << "-----------------------------------" << endl;

  int number = 1;

  for (Goat goat : trip) {
    cout << left
         << setw(6) << ("[" + to_string(number) + "]")
         << setw(12) << goat.get_name()
         << setw(7) << goat.get_age()
         << goat.get_color() << endl;
    number++;
  }

  cout << "-----------------------------------" << endl;
  cout << "Total goats: " << trip.size() << endl;
}

// display goats and get a valid selection
int select_goat(list<Goat> trip) {
  display_trip(trip);

  if (trip.empty())
    return 0;

  int selection;

  while (true) {
    cout << "Enter goat number to delete (1-"
         << trip.size() << "): ";

    if (cin >> selection &&
        selection >= 1 &&
        selection <= static_cast<int>(trip.size())) {
      return selection;
    }

    if (cin.eof())
      return 0;

    cout << "Invalid goat number. Please try again." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

// delete the selected goat from the list
void delete_goat(list<Goat> &trip) {
  if (trip.empty()) {
    cout << endl << "No goats available to delete." << endl;
    return;
  }

  int selection = select_goat(trip);

  if (selection == 0)
    return;

  list<Goat>::iterator it = trip.begin();

  for (int i = 1; i < selection; i++)
    it++;

  string deletedName = it->get_name();
  trip.erase(it);

  cout << endl;
  cout << "Goat \"" << deletedName
       << "\" deleted successfully!" << endl;
  cout << "Total goats remaining: " << trip.size() << endl;
}
