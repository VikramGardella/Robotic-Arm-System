#include "unit.h"
#include <cstdlib>
#include <string>
#include <iostream>

//constructor
unit::unit(std::string i, double t, double p, bool e){
	ID = i;
	temperature = t;
	pressure = p;
	exists = e;
}

//accessors
double unit::getTemp(){return temperature;}
double unit::getPres(){return pressure;}
std::string unit::getID(){return ID;}
bool unit::getExists(){return exists;}

//mutators
void unit::setTemp(double newTemp){temperature = newTemp;}
void unit::setPres(double newPres){pressure = newPres;}
void unit::setID(std::string newID){ID = newID;}
void unit::setExists(bool newExists){exists = newExists;}

//functions
void unit::report(){
	if(exists == true){
		std::cout << "------------------" << std::endl;
		std::cout << "ID: " << ID << std::endl;
		std::cout << "Temperature: " << temperature << std::endl;
		std::cout << "Pressure: " << pressure << std::endl;
		std::cout << "------------------" << std::endl;
	}
	else{
		std::cout << "------------------" << std::endl;
		std::cout << std::endl << std::endl << "EMPTY" << std::endl;
		std::cout << "------------------" << std::endl;
	}
}
