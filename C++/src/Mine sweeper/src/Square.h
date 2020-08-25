/*
 * Tile.h
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#ifndef SQUARE_H_
#define SQUARE_H_
#include<iostream>
class Square {
private:
	bool isSquareRevealed;
	bool isSquareFlagged;
	int squareValue;    					//stores the value of revealed position
public:
	Square();
	Square(int);
	void setFlaggedState(bool );
	bool getFlaggedState();
	void setRevealedState(bool);
	bool getRevealedState();
	int getSquareValue();
	const Square& operator=(const Square &ref1);
	friend bool operator==(const Square &ref1, const Square &ref2);
	friend bool operator==(const Square &ref1, const int value);
	friend bool operator!=(const Square &ref1, int value);
	friend std::ostream& operator<<(std::ostream &ref1, const Square &ref2);
};
#endif /* SQUARE_H_ */
