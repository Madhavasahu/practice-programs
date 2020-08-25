/*
 * Game.h
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#ifndef GAME_H_
#define GAME_H_
#include<exception>
#include<chrono>
#include "GameExceptions.h"
#include "Constants.h"
#include "Board.h"
#include "Player.h"
#include "ScoreBoard.h"
class Game { 				//controller of the game and compositely related to Player,Board,ScoreBoard classes
private:
	Player player;
	Board board;
	ScoreBoard scoreboard;
	bool isGameOver;

public:
	Game();
	void resetTheGame();
	void replayTheGame();
	void openTheSquareAt(int,int);
	void flagTheSquareAt(int,int);
	void processUserCommand(char,int,int);
	bool isGameWon();
	bool isValidPosition(int,int);
	bool isValidCommand(char);
	bool isValidResponse(char);
	void playGame();
};

#endif /* GAME_H_ */
