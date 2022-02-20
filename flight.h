#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

using namespace std;

// Definition der Klasse Flight
class Flight {
  string no;
  int seats;
  vector<Passenger> checked_in;
  vector<Passenger> boarded;
  public:
  Flight(string, int);
  bool check_in(const Passenger&);
  bool board(const Passenger&);
  bool ready(const vector<int>&) const;
  void print(ostream&) const;
  void pretty_print() const;
};

ostream& operator<< (ostream&, Flight);


#endif
