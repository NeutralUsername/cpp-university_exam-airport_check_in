#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

using namespace std;

//Implementierung der Klasse Passenger
Passenger::Passenger(string n) {
 	if(n.length() > 0)
    name = n;
  else
    throw runtime_error("");
  category = Category::Economy;
}

Passenger::Passenger(string n, Category c) {
 	if(n.length() > 0)
    name = n;
  else
    throw runtime_error("");
  category = c;
}

string Passenger::get_name() const {
 	return name; 
}

Category Passenger::get_category() const{
 return category; 
}

bool Passenger::in_category(Category c) const{
  if(c == category)
    return true;
  return false;
}

bool Passenger::operator== (Passenger p) const {
  if(name == p.get_name())
    return true;
  return false;
}

void Passenger::print(ostream& os) const {
  os << "["<< name << ": " << category_names[(int)category] <<"]"; 
}

ostream& operator<<(ostream& os, Passenger p) {
  p.print(os);
  return os;
}
