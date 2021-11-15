#ifndef UNIT_H
#define UNIT_H

#include <cstdlib>
#include <string>

class unit
{

public:

//constructor
unit(std::string i, double t, double p, bool e);

//accessors
double getTemp();
double getPres();
std::string getID();
bool getExists();

//mutators
void setTemp(double newTemp);
void setPres(double newPres);
void setID(std::string newID);
void setExists(bool newExists);

//functions
void report();

private:

//private member variables
double temperature;
double pressure;
std::string ID;
bool exists;

};

#endif
