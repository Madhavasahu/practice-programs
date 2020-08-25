/*
 * Board.h
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <cstdlib>
#include "Square.h"
#include "Constants.h"
class Board {
private:
	int MINE = -1;
	int rows = 10;
	int cols = 10;
	int minesCount;
	int safeSquares;
	int flagsCount;
	Square squares[10][10];		//original board in which bombs and numbers are placed
public:
	Board();
	void setSafeSquares(int);
	void incrementSafeSquaresCount();
	bool isRevealedAllSafeSquares();
	void drawBoard();
	void initBoard();
	int scanMinesAround(int, int);
	bool hasBomb(int, int);
	bool isValid(int, int); 			//check whether a position is valid or not
	void fillOriginalBoard(); 			//fills the original board with numbers and mines
	void putNumbers();
	void putMines();
	int revealSquareAt(int, int); 		//returns the value of the given the position
	void flagAt(int, int);
	bool isFlagged(int, int);			//check if the given position is already flagged
	void unflagAt(int, int);
	bool isRevealed(int, int);			//check if the given position is already revealed
	int getSafeSquares();
	int getMinesCount();
	int getFlagsCount();
	void setFlagsCount(int);
	void setRevealedState(bool,int,int);
	void revealAllMines();
};

#endif /* BOARD_H_ */
