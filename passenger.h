#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Category{Economy, Business, First};
const vector<string> category_names{"Economy", "Business", "First"};

//Definition der Klasse Passenger
class Passenger {
  string name;
  Category category;
  public:
  Passenger(string);
  Passenger(string, Category);
  string get_name() const;
  Category get_category() const;
  bool in_category(Category) const;
  bool operator==(Passenger) const;
  void print(ostream&) const;
};

ostream& operator<< (ostream&, Passenger);
#endif
