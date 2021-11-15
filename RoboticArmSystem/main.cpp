#include <iostream>
#include <cstdlib>
#include<ctime>
#include "robot.h"
#include "unit.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void printAvailableOperations(){
	cout << endl << endl;
	cout << "'operate' - Move system to operate position" << endl;
	cout << "'stow' - Move system to stow position" << endl;
	cout << "'move' - Move to a desired unit" << endl;
	cout << "'posreport' - Print out current positions of simulated hardware" << endl;
	cout << "'pullboard' - Pull circuit board out" << endl;
	cout << "'putboard' - Put circuit board in" << endl;
	cout << "'closesc' - Close the small claw" << endl;
	cout << "'opensc' - Open the small claw" << endl;
	cout << "'closebc' - Close the big claw" << endl;
	cout << "'openbc' - Open the big claw" << endl;
	cout << "'extendsd' - Extend the screwdriver attachment" << endl;
	cout << "'retractsd' - Retracts the screwdriver attachment" << endl;
	cout << "'screw' - Screw the unit at current arm position into place" << endl;
	cout << "'unscrew' - Unscrew the unit at current arm position" << endl;
	cout << "'insertexp' - Place unit in claw in place to be screwed in" << endl;
	cout << "'remove' - Remove unit in claw from circuit board after unscrewing" << endl;
	cout << "'unitreport' - Get report on which positions have units in them" << endl;
	cout << "'exit' - Terminate program" << endl << endl;
}

int main(int argc, char** argv){
	robot prototype = robot();
	prototype.printPhysicalPositions();

	vector<string> IDs;
	vector<double> temps;
	vector<double> press;

	ifstream aUnitsFile;
	ifstream bUnitsFile;
	ifstream cUnitsFile;

	string line;

	aUnitsFile.open(argv[1]);

	if(aUnitsFile.is_open()){
		while(getline(aUnitsFile, line)){
			istringstream iss(line);
			string sub;
			iss >> sub;
			IDs.push_back(sub);
			iss >> sub;
			temps.push_back(atof(sub.c_str()));
			iss >> sub;
			press.push_back(atof(sub.c_str()));
		}
		aUnitsFile.close();
	}

	bUnitsFile.open(argv[2]);

	if(bUnitsFile.is_open()){
		while(getline(bUnitsFile, line)){
			istringstream iss(line);
			string sub;
			iss >> sub;
			IDs.push_back(sub);
			iss >> sub;
			temps.push_back(atof(sub.c_str()));
			iss >> sub;
			press.push_back(atof(sub.c_str()));
		}
		bUnitsFile.close();
	}

	cUnitsFile.open(argv[3]);

	if(cUnitsFile.is_open()){
		while(getline(cUnitsFile, line)){
			istringstream iss(line);
			string sub;
			iss >> sub;
			IDs.push_back(sub);
			iss >> sub;
			temps.push_back(atof(sub.c_str()));
			iss >> sub;
			press.push_back(atof(sub.c_str()));
		}
		cUnitsFile.close();
	}

	for(int i=0; i<IDs.size(); i++){
		cout << "ID: " << IDs[i] << ", temp: " << temps[i] << ", press: " << press[i] << endl;
		prototype.initializeUnit(IDs[i], temps[i], press[i], true);
	}

	cout << "Choose from the following operations:" << endl << endl;
	printAvailableOperations();
	string userInput;
	cin >> userInput;
	cout << endl;
	while(userInput != "exit"){
		if(userInput == "move"){
			cout << "Moving..." << endl;
		}
		else if(userInput == "stow"){
			cout << "Stowing..." << endl;
			prototype.moveToStowPosition();
		}
		else if(userInput == "operate"){
			cout << "Moving to operate position..." << endl;
			prototype.moveToOperatePosition();
		}
		else if(userInput == "posreport"){
			cout << "Printing simulated hardware's positions..." << endl;
			prototype.printPhysicalPositions();
		}
		else if(userInput == "pullboard"){
			string desLoc;
			cout << "Which board would you like to pull out? Enter 'A', 'B', or 'C'." << endl << endl;
			cin >> desLoc;
			prototype.removeCircuitBoard(desLoc);
		}
		else if(userInput == "putboard"){
			string desLoc;
			cout << "Which slot would you like to put the circuit board in? Enter 'A', 'B', or 'C'." << endl << endl;
			cin >> desLoc;
			prototype.placeCircuitBoard(desLoc);
		}
		else if(userInput == "closesc"){
			cout << "Closing small claw..." << endl;
			prototype.closeSmallClaw();
		}
		else if(userInput == "opensc"){
			cout << "Opening small claw" << endl;
			prototype.openSmallClaw();
		}
		else if(userInput == "closebc"){
			cout << "Closing big claw" << endl;
			prototype.closeBigClaw();
		}
		else if(userInput == "openbc"){
			cout << "Opening big claw" << endl;
			prototype.openBigClaw();
		}
		else if(userInput == "screw"){
			cout << "Screwing..." << endl;
			prototype.screwUnit();
		}
		else if(userInput == "unscrew"){
			cout << "Unscrewing..." << endl;
			prototype.unscrewUnit();
		}
		else if(userInput == "insertexp"){
			cout << "Inserting..." << endl;
		}
		else if(userInput == "removeexp"){
			cout << "Removing..." << endl;
		}
		else if(userInput == "unitreport"){
			prototype.displayUnitStatuses();
		}
		else if(userInput == "exit"){
			cout << "Exiting..." << endl;
		}
		else{
			cout << "Invalid command." << endl;
		}
		cout << endl;

		if(userInput != "exit"){
			cout << "Enter another command or 'exit' to terminate the program." << endl;
			printAvailableOperations();
			cin >> userInput;
		}
	}
}
