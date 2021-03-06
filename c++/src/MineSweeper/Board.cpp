/*
 * Board.cpp
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */
#include<iostream>
#include<iomanip>
#include "Board.h"
using namespace std;
Board::Board() {
	safeSquares = 0;
	minesCount = 15;
	flagsCount = 0;
	Board::initBoard(); //Initialize the original and user boards.
	Board::fillOriginalBoard(); //fill the original board squares with mines and numbers.
}
int Board::getSafeSquares() {
	return safeSquares;
}
void Board::incrementSafeSquaresCount() {
	++safeSquares;
}
void Board::setSafeSquares(int value) {
	safeSquares = value;
}
bool Board::isRevealedAllSafeSquares() {
	return safeSquares == ((cols * rows) - (minesCount));
}

void Board::drawBoard() {
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			cout << "   ";
		}
		cout << setw(2) << i;
	}
	cout << endl;
	cout << "    " << "- - - - - - - - - -";
	for (int j = 0; j < rows; j++) {
		cout << endl;
		cout << setw(2) << j << "|";
		for (int k = 0; k < cols; k++) {
			if (isFlagged(j, k)) {
				cout << " F";
			} else {
				if (!isRevealed(j, k)) {
					cout << " █";
				} else {
					Constants constant;
					int squareContent = squares[j][k].getSquareValue();
					switch (squareContent) {
					case 0:
						cout << " .";
						break;
					case constant.MINE_PRESENT:
						cout << " *";
						break;
					default:
						cout << " " << squares[j][k];
					}
				}
			}

		}

	}
	cout << endl;
}
void Board::revealAllMines() { //reveals the bombs in the original board once the user hit a bomb
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (squares[i][j] == MINE) {
				squares[i][j].setRevealedState(true);
			}
		}
	}

}
void Board::initBoard() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			squares[i][j] = 0;
			squares[i][j].setRevealedState(false);
			squares[i][j].setFlaggedState(false);

		}
	}
}
void Board::fillOriginalBoard() {
	Board::putMines(); 						   //put mines randomly in the board
	Board::putNumbers(); //put numbers according to surrounding mines in the board
}
void Board::putMines() {
	int localMineCounter = 0;		//a local counter to count the mines placed
	srand(time(NULL)); //to place mines randomly and place in different position for different times
	while (true) {
		if (localMineCounter == minesCount) {
			break;
		}
		int randomI = rand() % rows;
		int randomJ = rand() % rows;
		if (squares[randomI][randomJ] != MINE) { //randomly creating the objects and assigning mines
			squares[randomI][randomJ] = MINE;
			localMineCounter++;
		}
	}
}
void Board::putNumbers() {
	int minesCount = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!hasBomb(i, j)) {
				minesCount = scanMinesAround(i, j); //scan the no.of mines around the current position
				squares[i][j] = minesCount; //assign the number to the objects by overloading =.
			}
		}
	}
}

int Board::scanMinesAround(int xPos, int yPos) { //scan the no.of mines around the given position
	int result = 0;
	if (isValid(xPos, yPos + 1)) { 				//check right middle position
		if (hasBomb(xPos, yPos + 1)) {
			result++;
		}
	}
	if (isValid(xPos + 1, yPos + 1)) { 				//check right down position
		if (hasBomb(xPos + 1, yPos + 1)) {
			result++;
		}
	}
	if (isValid(xPos - 1, yPos + 1)) { 				//check  right up position
		if (hasBomb(xPos - 1, yPos + 1)) {
			result++;
		}
	}
	if (isValid(xPos + 1, yPos)) { 					//check down middle position
		if (hasBomb(xPos + 1, yPos)) {
			result++;
		}
	}
	if (isValid(xPos - 1, yPos)) { 					//check up middle position
		if (hasBomb(xPos - 1, yPos)) {
			result++;
		}
	}
	if (isValid(xPos + 1, yPos - 1)) { 				//check left down position
		if (hasBomb(xPos + 1, yPos - 1)) {
			result++;
		}
	}
	if (isValid(xPos, yPos - 1)) { 					//check left middle position
		if (hasBomb(xPos, yPos - 1)) {
			result++;
		}
	}
	if (isValid(xPos - 1, yPos - 1)) { 				//check left up position
		if (hasBomb(xPos - 1, yPos - 1)) {
			result++;
		}
	}
	return result;
}
void Board::flagAt(int xPos, int yPos) {
	squares[xPos][yPos].setFlaggedState(true); //assign any value for putting a flag ,here i am taking 100
	flagsCount++;
}
void Board::unflagAt(int xPos, int yPos) {
	squares[xPos][yPos].setFlaggedState(false);	//replace the position with its the initial value 10 again to unflag
	flagsCount--;

}
int Board::getFlagsCount() {
	return flagsCount;
}
void Board::setRevealedState(bool state, int xPos, int yPos) {
	squares[xPos][yPos].setRevealedState(state);
}
bool Board::isRevealed(int xPos, int yPos) {
	if (squares[xPos][yPos].getRevealedState() == true) {
		return true;
	}
	return false;
}
bool Board::isFlagged(int xPos, int yPos) {
	if (squares[xPos][yPos].getFlaggedState() == true) { //checking whether there is a flag or not.
		return true; //here 100 means putting a flag. there is no specific reason for taking 100
	}
	return false;
}
bool Board::isValid(int xPos, int yPos) {
	if (xPos >= 0 && xPos < rows && yPos >= 0 && yPos < cols) {
		return true;
	} else {
		return false;
	}
}

bool Board::hasBomb(int xPos, int yPos) {
	if (squares[xPos][yPos] == MINE) {
		return true;
	} else {
		return false;
	}
}

int Board::revealSquareAt(int xPos, int yPos) {
	return squares[xPos][yPos].getSquareValue();
}
void Board::setFlagsCount(int value) {
	this->flagsCount = value;
}
int Board::getMinesCount() {
	return minesCount;
}
