#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "unit.h"

class robot
{

public:

//constructors
robot();

//accessors
int getSmallClawStatus();
int getBigClawStatus();
int getScrewdriverStatus();
int getArmBaseStatus();

int getLinActXAPos();
int getLinActXBPos();
int getLinActYAPos();
int getLinActYBPos();
int getLinActZPos();
int getLinActXCPos();
int getLinActWPos();

int getRotaryMotorOnePos();
int getRotaryMotorTwoPos();
int getRotaryMotorThreePos();
int getRotaryMotorFourPos();
int getRotaryMotorFivePos();
int getRotaryMotorSixPos();
int getRotaryMotorSDPos();
int getRotaryMotorSevenPos();
int getRotaryMotorEightPos();

//mutators
void setSmallClawStatus(int newSCS);
void setBigClawStatus(int newBCS);
void setScrewdriverStatus(int newSS);
void setArmBaseStatus(int newABS);

void setLinActXAPos(int newPos);
void setLinActXBPos(int newPos);
void setLinActYAPos(int newPos);
void setLinActYBPos(int newPos);
void setLinActZPos(int newPos);
void setLinActXCPos(int newPos);
void setLinActWPos(int newPos);

void setRotaryMotorOnePos(int newPos);
void setRotaryMotorTwoPos(int newPos);
void setRotaryMotorThreePos(int newPos);
void setRotaryMotorFourPos(int newPos);
void setRotaryMotorFivePos(int newPos);
void setRotaryMotorSixPos(int newPos);
void setRotaryMotorSDPos(int newPos);
void setRotaryMotorSevenPos(int newPos);
void setRotaryMotorEightPos(int newPos);

//functions
void initializeUnit(std::string i, double t, double p, bool e);

void displayUnitStatuses();

void closeSmallClaw();
void openSmallClaw();
void closeBigClaw();
void openBigClaw();
void extendScrewdriver();
void retractScrewdriver();

void moveToUnit(int row, int col);

void removeCircuitBoard(std::string boardLoc);
void placeCircuitBoard(std::string boardLoc);

void screwUnit();
void unscrewUnit();
void insertUnit();
void removeUnit();

void moveLinActXATo(int newPos);
void moveLinActXBTo(int newPos);
void moveLinActYATo(int newPos);
void moveLinActYBTo(int newPos);
void moveLinActZTo(int newPos);
void moveLinActXCTo(int newPos);
void moveLinActWTo(int newPos);

void moveXActConcurTo(int newPos);
void moveYActConcurTo(int newPos);

void moveRotaryMotorOneTo(int newPos);
void moveRotaryMotorTwoTo(int newPos);
void moveRotaryMotorThreeTo(int newPos);
void moveRotaryMotorFourTo(int newPos);
void moveRotaryMotorFiveTo(int newPos);
void moveRotaryMotorSixTo(int newPos);
void moveRotaryMotorSDTo(int newPos);
void moveRotaryMotorSevenTo(int newPos);
void moveRotaryMotorEightTo(int newPos);

int getUnitRowCoordinates(int row);
int getUnitColCoordinates(int col);

void moveToStowPosition();
void moveToOperatePosition();

void printPhysicalPositions();


private:

//private member variables
	int smallClawStatus; //0 if closed, 1 if open to any degree
	int bigClawStatus; //0 if closed, 1 if open to any degree
	int screwdriverStatus; //0 if retracted completely, 1 if otherwise
	int armBaseStatus; //0 if completely folded in, 99 if ready for operation, 1-98 if in between
	int isStowed; //0 if not in stow position, 1 if it is
	int unitInSmallClaw; //0 if not, 1 if so
	int boardInBigClaw; //0 if not, 1 if so

	std::vector<int> boardsInPlace;

	int linActXAPos; //moves base of arm on x-axis [0:100]
	int linActXBPos; //moves base of arm on x-axis [0:100]
	int linActYAPos; //moves base of arm on y-axis [0:100]
	int linActYBPos; //moves base of arm on y-axis [0:100]
	int linActZPos; //moves base of arm on z-axis [0:100]
	int linActXCPos; //might not need
	int linActWPos; //extends and retracts hand from wrist [0:100]

	int rotaryMotorOnePos; //[0:360]
	int rotaryMotorTwoPos; //[0:90]
	int rotaryMotorThreePos; //[0:180]
	int rotaryMotorFourPos; //[0:180]
	int rotaryMotorFivePos; //[75:180]
	int rotaryMotorSixPos; //[75:180]
	int rotaryMotorSDPos; //[0:360]
	int rotaryMotorSevenPos; //[75:180]
	int rotaryMotorEightPos; //[75:180]

	std::vector<std::vector<unit> > circuitBoardA;
	std::vector<unit> boardATopRow; //3 units
	std::vector<unit> boardABottomRow; //4 units

	std::vector<std::vector<unit> > circuitBoardB;
	std::vector<unit> boardBTopRow; //3 units
	std::vector<unit> boardBBottomRow; //4 units

	std::vector<std::vector<unit> > circuitBoardC;
	std::vector<unit> boardCTopRow; //3 units
	std::vector<unit> boardCBottomRow; //4 units

};


#endif
