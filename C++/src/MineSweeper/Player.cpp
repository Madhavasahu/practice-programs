/*
 * Player.cpp
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#include <iostream>
#include "Player.h"
using namespace std;
Player::Player() {
	command = '0';
	xPos = 0;
	yPos = 0;
}
void Player::setCommand() {
	cin >> command;
}
void Player::setPositions(){
	cin >> xPos;
	cin >> yPos;
}
char Player::getCommand() {
	return command;
}
int Player::getxPos() {
	return xPos;
}
int Player::getyPos() {
	return yPos;
}
