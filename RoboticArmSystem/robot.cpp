#include "robot.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "unit.h"

//constructors
robot::robot(){
	smallClawStatus = 0;
	bigClawStatus = 1;
	screwdriverStatus = 0;
	armBaseStatus = 0;
	isStowed = 1;
	unitInSmallClaw = 0;
	boardInBigClaw = 0;

	boardsInPlace.push_back(1); //Circuit Board A  (1 means board in place, 0 means the slot is empty)
	boardsInPlace.push_back(1); //Circuit Board B
	boardsInPlace.push_back(1); //Circuit Board C

	linActXAPos = 0;
	linActXBPos = 0;
	linActYAPos = 0;
	linActYBPos = 0;
	linActZPos = 0;
	linActXCPos = 0;
	linActWPos = 0;

	rotaryMotorOnePos = 90;
	rotaryMotorTwoPos = 0;
	rotaryMotorThreePos = 0;
	rotaryMotorFourPos = 0;
	rotaryMotorFivePos = 180;
	rotaryMotorSixPos = 180;
	rotaryMotorSDPos = 0;
	rotaryMotorSevenPos = 75;
	rotaryMotorEightPos = 75;

	circuitBoardA.push_back(boardATopRow);
	circuitBoardA.push_back(boardABottomRow);

	circuitBoardB.push_back(boardBTopRow);
	circuitBoardB.push_back(boardBBottomRow);

	circuitBoardC.push_back(boardCTopRow);
	circuitBoardC.push_back(boardCBottomRow);
}

//accessors
int robot::getSmallClawStatus(){return smallClawStatus;}
int robot::getBigClawStatus(){return bigClawStatus;}
int robot::getScrewdriverStatus(){return screwdriverStatus;}
int robot::getArmBaseStatus(){return armBaseStatus;}

int robot::getLinActXAPos(){return linActXAPos;}
int robot::getLinActXBPos(){return linActXBPos;}
int robot::getLinActYAPos(){return linActYAPos;}
int robot::getLinActYBPos(){return linActYBPos;}
int robot::getLinActZPos(){return linActZPos;}
int robot::getLinActXCPos(){return linActXCPos;}
int robot::getLinActWPos(){return linActWPos;}

int robot::getRotaryMotorOnePos(){return rotaryMotorOnePos;}
int robot::getRotaryMotorTwoPos(){return rotaryMotorTwoPos;}
int robot::getRotaryMotorThreePos(){return rotaryMotorThreePos;}
int robot::getRotaryMotorFourPos(){return rotaryMotorFourPos;}
int robot::getRotaryMotorFivePos(){return rotaryMotorFivePos;}
int robot::getRotaryMotorSixPos(){return rotaryMotorSixPos;}
int robot::getRotaryMotorSDPos(){return rotaryMotorSDPos;}
int robot::getRotaryMotorSevenPos(){return rotaryMotorSevenPos;}
int robot::getRotaryMotorEightPos(){return rotaryMotorEightPos;}

//mutators
void robot::setSmallClawStatus(int newSCS){smallClawStatus = newSCS;}
void robot::setBigClawStatus(int newBCS){bigClawStatus = newBCS;}
void robot::setScrewdriverStatus(int newSS){screwdriverStatus = newSS;}
void robot::setArmBaseStatus(int newABS){armBaseStatus = newABS;}

void robot::setLinActXAPos(int newPos){linActXAPos = newPos;}
void robot::setLinActXBPos(int newPos){linActXBPos = newPos;}
void robot::setLinActYAPos(int newPos){linActYAPos = newPos;}
void robot::setLinActYBPos(int newPos){linActYBPos = newPos;}
void robot::setLinActZPos(int newPos){linActZPos = newPos;}
void robot::setLinActXCPos(int newPos){linActXCPos = newPos;}
void robot::setLinActWPos(int newPos){linActWPos = newPos;}

void robot::setRotaryMotorOnePos(int newPos){rotaryMotorOnePos = newPos;}
void robot::setRotaryMotorTwoPos(int newPos){rotaryMotorTwoPos = newPos;}
void robot::setRotaryMotorThreePos(int newPos){rotaryMotorThreePos = newPos;}
void robot::setRotaryMotorFourPos(int newPos){rotaryMotorFourPos = newPos;}
void robot::setRotaryMotorFivePos(int newPos){rotaryMotorFivePos = newPos;}
void robot::setRotaryMotorSixPos(int newPos){rotaryMotorSixPos = newPos;}
void robot::setRotaryMotorSDPos(int newPos){rotaryMotorSDPos = newPos;}
void robot::setRotaryMotorSevenPos(int newPos){rotaryMotorSevenPos = newPos;}
void robot::setRotaryMotorEightPos(int newPos){rotaryMotorEightPos = newPos;}

//functions
void robot::initializeUnit(std::string i, double t, double p, bool e){
	unit temp = unit(i, t, p, e);
	if(i[0] == 'A'){
		if(i[1] == 'A' || i[1] == 'B' || i[1] == 'C'){
			circuitBoardA[0].push_back(temp);
		}
		else{
			circuitBoardA[1].push_back(temp);
		}
	}
	if(i[0] == 'B'){
		if(i[1] == 'A' || i[1] == 'B' || i[1] == 'C'){
			circuitBoardB[0].push_back(temp);
		}
		else{
			circuitBoardB[1].push_back(temp);
		}
	}
	if(i[0] == 'C'){
		if(i[1] == 'A' || i[1] == 'B' || i[1] == 'C'){
			circuitBoardC[0].push_back(temp);
		}
		else{
			circuitBoardC[1].push_back(temp);
		}
	}
}


void robot::displayUnitStatuses(){

	std::cout << "_________________________________________________________" << std::endl;

	std::cout << std::endl << std:: endl << "Circuit Board A:" << std::endl;
	for(int i=0; i<circuitBoardA[0].size(); i++){
		circuitBoardA[0][i].report();
	}
	for(int i=0; i<circuitBoardA[1].size(); i++){
		circuitBoardA[1][i].report();
	}

	std::cout << std::endl << "_________________________________________________________" << std::endl;

	std::cout << std::endl << std::endl << "Circuit Board B:" << std::endl;
		for(int j=0; j<circuitBoardB[0].size(); j++){
		circuitBoardB[0][j].report();
	}
	for(int j=0; j<circuitBoardB[1].size(); j++){
		circuitBoardB[1][j].report();
	}

	std::cout << std::endl << "_________________________________________________________" << std::endl;

	std::cout << std::endl << std::endl << "Circuit Board C:" << std::endl;
	for(int k=0; k<circuitBoardC[0].size(); k++){
		circuitBoardC[0][k].report();
	}
	for(int k=0; k<circuitBoardC[1].size(); k++){
		circuitBoardC[1][k].report();
	}

	std::cout << std::endl << "_________________________________________________________" << std::endl;
	std::cout << std::endl << std::endl;

}

void robot::closeSmallClaw(){
	if(smallClawStatus == 0){
		std::cout << "Small claw is already closed." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveRotaryMotorFiveTo(180);
		moveRotaryMotorSixTo(180);
		setSmallClawStatus(0);
	}
}

void robot::openSmallClaw(){
	if(smallClawStatus != 0){
		std::cout << "Small claw is already open." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveRotaryMotorFiveTo(75);
		moveRotaryMotorSixTo(75);
		setSmallClawStatus(1);
	}
}

void robot::closeBigClaw(){
	if(bigClawStatus == 0){
		std::cout << "Big claw is already closed." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveRotaryMotorSevenTo(180);
		moveRotaryMotorEightTo(180);
		setBigClawStatus(0);
	}
}

void robot::openBigClaw(){
	if(bigClawStatus != 0){
		std::cout << "Big claw is already open." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveRotaryMotorSevenTo(75);
		moveRotaryMotorEightTo(75);
		setBigClawStatus(1);
	}
}

void robot::extendScrewdriver(){
	if(screwdriverStatus != 0){
		std::cout << "Screwdriver is already extended." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveLinActXCTo(100);
		setScrewdriverStatus(1);
	}
}

void robot::retractScrewdriver(){
	if(screwdriverStatus == 0){
		std::cout << "Screwdriver is already retracted." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else{
		moveLinActXCTo(0);
		setScrewdriverStatus(0);
	}
}

void robot::moveToUnit(int row, int col){}

void robot::removeCircuitBoard(std::string boardLoc){
	int loc;
	bool invalid = false;
	if(boardLoc == "A"){
		loc = 0;
	}
	else if(boardLoc == "B"){
		loc = 1;
	}
	else if(boardLoc == "C"){
		loc = 2;
	}
	else{
		invalid = true;
	}
	if(isStowed == 1){
		std::cout << "Cannot perform this operation in stow position. Move to operate position then try again." << std::endl;
	}
	else if(invalid == true){
		std::cout << "Invalid circuit board location." << std::endl;
	}
	else if(boardsInPlace[loc] == 0){
		std::cout << "No board to remove at this location." << std::endl;
	}
	else if(boardInBigClaw == 1){
		std::cout << "Cannot perform this operation with a board already in big claw. Discard board in big claw or put it in an empty slot." << std::endl;
	}
	else{
		if(bigClawStatus == 0){
			std::cout << "Big claw closed, opening it now..." << std::endl;
			openBigClaw();
		}
		else{
			std::cout << "Big claw already open and ready." << std::endl;
		}
		moveXActConcurTo(30); //pulling base of apparatus out to give space

		moveYActConcurTo(50); //y position for extracting board will always be 50, right in the middle

		if(loc == 0){
			moveLinActZTo(10);
		}
		else if(loc == 1){
			moveLinActZTo(45);
		}
		else if(loc == 2){
			moveLinActZTo(80);
		} //just need to move big claw inward along x-axis at this point to get in position for grabbing

		moveXActConcurTo(0);

		closeBigClaw(); //will have grasped handle of circuit board at this point

		moveXActConcurTo(100); //pulling board out all the way along the x-axis

		boardInBigClaw = 1;
		boardsInPlace[loc] = 0; //updating array of whether or not boards are in locations
	}
}

void robot::placeCircuitBoard(std::string boardLoc){
	int loc;
	bool invalid = false;
	if(boardInBigClaw == 0){
		std::cout << "Big claw doesn't have a board in it. Pickup a board then try this operation again." << std::endl;
	}
	else if(boardLoc == "A"){
		loc = 0;
	}
	else if(boardLoc == "B"){
		loc = 1;
	}
	else if(boardLoc == "C"){
		loc = 2;
	}
	else{
		invalid = true;
	}
	if(invalid == true){
		std::cout << "Invalid circuit board location." << std::endl;
	}
	else if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else if(boardsInPlace[loc] == 1){
		std::cout << "Board already in place here. Cannot perform operation." << std::endl;
	}
	else{
		moveXActConcurTo(100);
		moveYActConcurTo(50);

		if(loc == 0){
			moveLinActZTo(10);
		}
		else if(loc == 1){
			moveLinActZTo(45);
		}
		else if(loc == 2){
			moveLinActZTo(80);
		}  //in position at this point, just need to move board inwward along x-axis

		moveXActConcurTo(0);//board in place to be released
		openBigClaw(); //releasing board

		boardInBigClaw = 0;
		boardsInPlace[loc] = 1;

		moveXActConcurTo(30);
	}
}

void robot::screwUnit(){
	if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else if(screwdriverStatus == 0){
		std::cout << "Screwdriver must be extended first." << std::endl;
	}
	else{
		moveRotaryMotorSDTo(3600);//clockwise 10 revs
	}
}

void robot::unscrewUnit(){
	if(isStowed == 1){
		std::cout << "Cannot perform this operation when system is in stow position." << std::endl << std::endl;
	}
	else if(screwdriverStatus == 0){
		std::cout << "Screwdriver must be extended first." << std::endl;
	}
	else{
		moveRotaryMotorSDTo(-3600);//counterclockwise 10 revs
	}


}

void robot::insertUnit(){}

void robot::removeUnit(){}

void robot::moveLinActXATo(int newPos){
	int i = 1;
	if(newPos < linActXAPos){
		i *= -1;
	}
	while(linActXAPos != newPos){
		if(linActXAPos % 10 == 0){
			std::cout << "LinActXA: " << linActXAPos << std::endl;
		}
		linActXAPos+=i;
	}
	std::cout << "LinActXA: " << linActXAPos << std::endl;
}

void robot::moveLinActXBTo(int newPos){

	int i = 1;
	if(newPos < linActXBPos){
		i *= -1;
	}
	while(linActXBPos != newPos){
		if(linActXBPos % 10 == 0){
			std::cout << "LinActXB: " << linActXBPos << std::endl;
		}
		linActXBPos+=i;
	}
	std::cout << "LinActXB: " << linActXBPos << std::endl;

}

void robot::moveLinActYATo(int newPos){
	int i = 1;
	if(newPos < linActYAPos){
		i *= -1;
	}
	while(linActYAPos != newPos){
		if(linActYAPos % 10 == 0){
			std::cout << "LinActYA: " << linActYAPos << std::endl;
		}
		linActYAPos+=i;
	}
	std::cout << "LinActYA: " << linActYAPos << std::endl;
}

void robot::moveLinActYBTo(int newPos){
	int i = 1;
	if(newPos < linActYBPos){
		i *= -1;
	}
	while(linActYBPos != newPos){
		if(linActYBPos % 10 == 0){
			std::cout << "LinActYB: " << linActYBPos << std::endl;
		}
		linActYBPos+=i;
	}
	std::cout << "LinActYB: " << linActYBPos << std::endl;


}

void robot::moveLinActZTo(int newPos){
	int i = 1;
	if(newPos < linActZPos){
		i *= -1;
	}
	while(linActZPos != newPos){
		if(linActZPos % 10 == 0){
			std::cout << "LinActZ: " << linActZPos << std::endl;
		}
		linActZPos+=i;
	}
	std::cout << "LinActZ: " << linActZPos << std::endl;


}

void robot::moveLinActXCTo(int newPos){
	int i = 1;
	if(newPos < linActXCPos){
		i *= -1;
	}
	while(linActXCPos != newPos){
		if(linActXCPos % 10 == 0){
			std::cout << "LinActXC: " << linActXCPos << std::endl;
		}
		linActXCPos+=i;
	}
	std::cout << "LinActXC: " << linActXCPos << std::endl;


}

void robot::moveLinActWTo(int newPos){
	int i = 1;
	if(newPos < linActWPos){
		i *= -1;
	}
	while(linActWPos != newPos){
		if(linActWPos % 10 == 0){
			std::cout << "LinActW: " << linActWPos << std::endl;
		}
		linActWPos+=i;
	}
	std::cout << "LinActW: " << linActWPos << std::endl;


}

void robot::moveXActConcurTo(int newPos){
	int i = 1;
	if(newPos < linActXAPos){
		i *= -1;
	}
	while(linActXAPos != newPos){
		if(linActXAPos % 10 == 0){
			std::cout << "LinActXA: " << linActXAPos << ", LinActXB: " << linActXBPos << std::endl;
		}
		linActXAPos+=i;
		linActXBPos+=i;
	}
	std::cout << "LinActXA: " << linActXAPos << ", LinActXB: " << linActXBPos << std::endl;
}

void robot::moveYActConcurTo(int newPos){
	int i = 1;
	if(newPos < linActYAPos){
		i *= -1;
	}
	while(linActYAPos != newPos){
		if(linActYAPos % 10 == 0){
			std::cout << "LinActYA: " << linActYAPos << ", LinActYB: " << linActYBPos << std::endl;
		}
		linActYAPos+=i;
		linActYBPos+=i;
	}
	std::cout << "LinActYA: " << linActYAPos << ", LinActYB: " << linActYBPos << std::endl;
}

void robot::moveRotaryMotorOneTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorOnePos){
		i *= -1;
	}
	while(rotaryMotorOnePos != newPos){
		if(rotaryMotorOnePos % 15 == 0){
			std::cout << "Rotary Motor 1: " << rotaryMotorOnePos << std::endl;
		}
		rotaryMotorOnePos+=i;
	}
	std::cout << "Rotary Motor 1: " << rotaryMotorOnePos << std::endl;

}

void robot::moveRotaryMotorTwoTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorTwoPos){
		i *= -1;
	}
	while(rotaryMotorTwoPos != newPos){
		if(rotaryMotorTwoPos % 15 == 0){
			std::cout << "Rotary Motor 2: " << rotaryMotorTwoPos << std::endl;
		}
		rotaryMotorTwoPos+=i;
	}
	std::cout << "Rotary Motor 2: " << rotaryMotorTwoPos << std::endl;

}

void robot::moveRotaryMotorThreeTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorThreePos){
		i *= -1;
	}
	while(rotaryMotorThreePos != newPos){
		if(rotaryMotorThreePos % 15 == 0){
			std::cout << "Rotary Motor 3: " << rotaryMotorThreePos << std::endl;
		}
		rotaryMotorThreePos+=i;
	}
	std::cout << "Rotary Motor 3: " << rotaryMotorThreePos << std::endl;

}

void robot::moveRotaryMotorFourTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorFourPos){
		i *= -1;
	}
	while(rotaryMotorFourPos != newPos){
		if(rotaryMotorFourPos % 15 == 0){
			std::cout << "Rotary Motor 4: " << rotaryMotorFourPos << std::endl;
		}
		rotaryMotorFourPos+=i;
	}
	std::cout << "Rotary Motor 4: " << rotaryMotorFourPos << std::endl;

}

void robot::moveRotaryMotorFiveTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorFivePos){
		i *= -1;
	}
	while(rotaryMotorFivePos != newPos){
		if(rotaryMotorFivePos % 15 == 0){
			std::cout << "Rotary Motor 5: " << rotaryMotorFivePos << std::endl;
		}
		rotaryMotorFivePos+=i;
	}
	std::cout << "Rotary Motor 5: " << rotaryMotorFivePos << std::endl;

}

void robot::moveRotaryMotorSixTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorSixPos){
		i *= -1;
	}
	while(rotaryMotorSixPos != newPos){
		if(rotaryMotorSixPos % 15 == 0){
			std::cout << "Rotary Motor 6: " << rotaryMotorSixPos << std::endl;
		}
		rotaryMotorSixPos+=i;
	}
	std::cout << "Rotary Motor 6: " << rotaryMotorSixPos << std::endl;

}

void robot::moveRotaryMotorSDTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorSDPos){
		i *= -1;
	}
	while(rotaryMotorSDPos != newPos){
		if(rotaryMotorSDPos % 15 == 0){
			std::cout << "Rotary Motor SD: " << rotaryMotorSDPos << std::endl;
		}
		rotaryMotorSDPos+=i;
	}
	std::cout << "Rotary Motor SD: " << rotaryMotorSDPos << std::endl;

}

void robot::moveRotaryMotorSevenTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorSevenPos){
		i *= -1;
	}
	while(rotaryMotorSevenPos != newPos){
		if(rotaryMotorSevenPos % 15 == 0){
			std::cout << "Rotary Motor 7: " << rotaryMotorSevenPos << std::endl;
		}
		rotaryMotorSevenPos+=i;
	}
	std::cout << "Rotary Motor 7: " << rotaryMotorSevenPos << std::endl;

}

void robot::moveRotaryMotorEightTo(int newPos){
	int i = 1;
	if(newPos < rotaryMotorEightPos){
		i *= -1;
	}
	while(rotaryMotorEightPos != newPos){
		if(rotaryMotorEightPos % 15 == 0){
			std::cout << "Rotary Motor 8: " << rotaryMotorEightPos << std::endl;
		}
		rotaryMotorEightPos+=i;
	}
	std::cout << "Rotary Motor 8: " << rotaryMotorEightPos << std::endl;

}

int robot::getUnitRowCoordinates(int row){
	if(row < 1 || row > 2){
		return -1;
	}
	else if(row == 1){
		return 0;
	}
	else if(row == 2){
		return 50;
	}


}

int robot::getUnitColCoordinates(int col){



}

void robot::moveToStowPosition(){
	if(unitInSmallClaw == 1){
		std::cout << "Object in claw hand, cannot perform stow operation." << std::endl;
	}
	else if(boardInBigClaw == 1){
		std::cout << "Circuit board must be released from large claw before this operation can be performed." << std::endl;

	}
	else if(isStowed == 1){
		std::cout << "Already stowed." << std::endl;
	}
	else{
		retractScrewdriver();
		closeSmallClaw();
		openBigClaw();
		moveLinActWTo(0);

		moveYActConcurTo(50);

		if(rotaryMotorOnePos >= 0 && rotaryMotorOnePos < 180){
			moveRotaryMotorOneTo(0);
		}
		else{
			moveRotaryMotorOneTo(180);
		}

		moveRotaryMotorTwoTo(90);
		moveRotaryMotorThreeTo(0);
		moveRotaryMotorFourTo(0);

		moveYActConcurTo(50);

		moveLinActZTo(50);

		moveRotaryMotorOneTo(90);

		moveLinActZTo(0);

		moveYActConcurTo(0);

		moveRotaryMotorTwoTo(0);
		isStowed = 1;
	}
}

void robot::moveToOperatePosition(){
	//check if in stow position,
	//if so:
		//move linActYA & linActYB to 50 concurrently
		//move rMotor 2 from 0 to 60
		//move rMotor 3 from 0 to 60
		//move rMotor 4 from 0 to 90
		//move linActW from 0 to 30
	//else
		//print error message

	if(isStowed == 1){
		moveYActConcurTo(50);

		moveRotaryMotorTwoTo(60);

		moveRotaryMotorThreeTo(60);

		moveRotaryMotorFourTo(90);

		moveLinActWTo(30);
		isStowed = 0;
	}
	else{
		std::cout << "System must be in stow position to perform this operation." << std::endl;
	}
}

void robot::printPhysicalPositions(){
	std::cout << std::endl << "Small Claw Status: " << smallClawStatus << std::endl;
	std::cout << "Big Claw Status: " << bigClawStatus << std::endl;
	std::cout << "Screwdriver Status: " << screwdriverStatus << std::endl;
	std::cout << "Arm Base Status: " << armBaseStatus << std::endl << std::endl;
	std::cout << "Big claw holding board: " << boardInBigClaw << std::endl;
	std::cout << "Boards in place: [" << boardsInPlace[0] << ", " << boardsInPlace[1] << ", " << boardsInPlace[2] << "]" << std::endl << std::endl;

	std::cout << "Linear Actuator Positions:" << std::endl;
	std::cout << "LinAct XA: " << linActXAPos << std::endl;
	std::cout << "LinAct XB: " << linActXBPos << std::endl;
	std::cout << "LinAct YA: " << linActYAPos << std::endl;
	std::cout << "LinAct YB: " << linActYBPos << std::endl;
	std::cout << "LinAct Z: " << linActZPos << std::endl;
	std::cout << "LinAct XC: " << linActXCPos << std::endl;
	std::cout << "LinAct W: " << linActWPos << std::endl << std::endl << std::endl;

	std::cout << "Rotary Motor Positions:" << std::endl;
	std::cout << "RM1: " << rotaryMotorOnePos << std::endl;
	std::cout << "RM2: " << rotaryMotorTwoPos << std::endl;
	std::cout << "RM3: " << rotaryMotorThreePos << std::endl;
	std::cout << "RM4: " << rotaryMotorFourPos << std::endl;
	std::cout << "RM5: " << rotaryMotorFivePos << std::endl;
	std::cout << "RM6: " << rotaryMotorSixPos << std::endl;
	std::cout << "RMSD: " << rotaryMotorSDPos << std::endl;
	std::cout << "RM7: " << rotaryMotorSevenPos << std::endl;
	std::cout << "RM8: " << rotaryMotorEightPos << std::endl << std::endl << std::endl;


}
