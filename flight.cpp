#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"
#include "flight.h"

// Implementierung der Klasse Flight

Flight::Flight(string n, int s) {
  if(n.length() > 0 && s >= 0) {
    no = n;
    seats = s;
  }
  else
    throw runtime_error("");
}

bool Flight::check_in(const Passenger& p){
  bool ci = false;
  for(auto pass : checked_in) {
    if(p.get_name() == pass.get_name())
      ci = true;
  }
  if(!ci) {
   	if(checked_in.size() <  seats){
      checked_in.push_back(p);
      return true;
    }
  }
  return false;
}

bool Flight::board(const Passenger& p) {
  bool ci = false;
  for(auto pass : checked_in) {
    if(p.get_name() == pass.get_name())
      ci = true;
  }
  if(ci) {
   	bool b = false;
    for(auto pass : boarded) {
      if(p.get_name() == pass.get_name())
        b = true;
    }	
    if(!b) {
     	boarded.push_back(p);
      return true;
    }
  }
  return false;
}

void Flight::print(ostream& os) const {
  os << "[" << no << ", {";
  for(int i = 0; i < checked_in.size(); i++) {
    os << checked_in[i];
   	for(auto p2 : boarded) {
      if(checked_in[i] == p2)
        os <<"*";
    }
    if(i != checked_in.size()-1)
      os <<", ";
  }
  os << "}]";
}

void Flight::pretty_print() const {
  cout << no;
  if(boarded.size() == 0 && checked_in.size() == 0)
    return;
  vector<Passenger> missing;
  for(auto p1 : checked_in) {
    bool b = false;
    for(auto p2 : boarded) {
      if(p1 == p2)
        b = true;
    }
    if(!b)
      missing.push_back(p1);
  }
  if(boarded.size() >0 ) {
   	cout << ", boarded: {"; 
    for(int i = 0; i < boarded.size(); i++) {
     	cout << boarded[i]; 
      if(i != boarded.size() -1)
        cout <<", ";
    }
    cout << "}";
    if(missing.size() > 0) {
     	cout << ", missing: {"; 
      for(int i = 0; i < missing.size(); i++) {
        cout << missing[i]; 
        if(i != missing.size() -1)
          cout <<", ";
    	}
      cout << "}";
    }
  }
  else if(missing.size() > 0) {
   	cout << ", missing: {"; 
    for(int i = 0; i < missing.size(); i++) {
      cout << missing[i]; 
      if(i != missing.size() -1)
        cout <<", ";
    }
     cout << "}";
  }
}

bool Flight::ready(const vector<int>& seats_per_category) const {
  if(seats_per_category.size() != 3) throw runtime_error("");
  for(auto s : seats_per_category)
    if(s < 0)
      throw runtime_error("");
  
  for(auto p1 : checked_in) {
    bool b = false;
   	for(auto p2: boarded) {
     	if( p1 == p2)
        b = true;
    }
    if(!b)
      return false;
  }
  vector<int> used_seats_per_category {0,0,0};
  for(auto p : boarded) {
    used_seats_per_category[(int)p.get_category()] = used_seats_per_category[(int)p.get_category()] +1;
  }
  for(int i = 0; i< 3; i++) {
    if(used_seats_per_category[i] > seats_per_category[i])
       return false;
  }
  return true;
}



ostream& operator<< (ostream& os, Flight f) {
  f.print(os);
  return os;
}
