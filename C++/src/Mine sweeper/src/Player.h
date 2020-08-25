/*
 * Player.h
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
private:
	char command;
	int xPos;
	int yPos;
public:
	Player();
	void setCommand();
	void setPositions();
	char getCommand();
	int getxPos();
	int getyPos();
};

#endif /* PLAYER_H_ */
