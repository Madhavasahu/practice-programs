/*
 * ScoreBoard.cpp
 *
 *  Created on: 29-Oct-2018
 *      Author: madhavasahu
 */

#include "ScoreBoard.h"
#include <iostream>
ScoreBoard::ScoreBoard() {
	score=0;
}
void ScoreBoard::setScore(double score){
	this->score=int(score);
}
void ScoreBoard::displayScore(){
std::cout<<"Your score is "<<score<<"Secs"<<std::endl;
}
