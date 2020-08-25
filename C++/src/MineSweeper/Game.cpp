/*
 * Game.cpp
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */

#include "Game.h"

#include <iostream>
using namespace std;
using namespace chrono;
Game::Game() {
	isGameOver = false;
}
void Game::playGame() {

	cout << "INSTRUCTIONS" << endl;
	cout << " Open the cells without stepping on the 15 mines" << endl;
	cout
			<< "To OPEN a cell first enter \"O\"  and then enter the cell's coordinates"
			<< endl;
	cout
			<< "To FLAG a cell first enter \"F\"  and then enter the cell's coordinates"
			<< endl;
	auto startingTimer = high_resolution_clock::now();	//start recording time
	while (!isGameOver) {
		static char command;
		static int xPos, yPos;
		board.drawBoard();
		try {
			cout << "enter the command:: \"O\" or \"F\"" << endl;
			player.setCommand();
			command = player.getCommand();
			if (!isValidCommand(command)) {
				throw InvalidCommand();
			} else {
				cout << "enter the x and y coordinates::" << endl;
				player.setPositions();
				xPos = player.getxPos();
				yPos = player.getyPos();
				if (!isValidPosition(xPos, yPos)) {
					throw InvalidPosition();
				}
			}
		} catch (InvalidCommand &ref) {
			cout << ref.what() << endl;
			player.setCommand();
		} catch (InvalidPosition &ref) {
			cout << ref.what() << endl;
			player.setPositions();
		}
		processUserCommand(command, xPos, yPos); //process the command because it is a valid one
		if (isGameWon()) {
			board.drawBoard();
			cout << "congratulations..you win" << endl;
			auto finishingTimer = high_resolution_clock::now(); //end the timer and calculate time
			duration<double> time = finishingTimer - startingTimer; //calculate the time
			scoreboard.setScore(time.count()); //set the score(recorded time) in score board class
			scoreboard.displayScore();			//display the score after win
			isGameOver = true;
		}
	}

	if (!isGameWon()) { 					//if loses the game show the bombs
		cout << "you lose the game" << endl;
		board.revealAllMines();
		board.drawBoard();
	}
	replayTheGame(); 						//replays the game if user wants it.

}

bool Game::isValidResponse(char response) {
	if (response == 'y' || response == 'Y' || response == 'N'
			|| response == 'n') {
		return true;
	} else {
		return false;
	}
}
void Game::replayTheGame() {
	char replay;
	cout << "Want to replay ?..enter y or n" << endl;
	cin >> replay;
	try {
		if (!isValidResponse(replay)) {
			throw InvalidResponse();
		}
	} catch (InvalidResponse &ref) {
		cout << ref.what() << endl;
		cin >> replay;
	}
	switch (replay) {
	case 'y':
	case 'Y':
		resetTheGame();
		break;
	case 'n':
	case 'N':
		cout << "game exited" << endl;
		break;
	default:
		cout << "invalid (exited)" << endl; //just to catch any other invalid response
	}

}
void Game::resetTheGame() {   		//reset all to the initial value
	board.setSafeSquares(0);
	board.setFlagsCount(0);
	isGameOver = false;
	scoreboard.setScore(0);
	board.initBoard();
	board.fillOriginalBoard();
	playGame();
}
bool Game::isGameWon() {
	if ((board.isRevealedAllSafeSquares())) {
		return true;
	} else {
		return false;
	}
}
bool Game::isValidCommand(char command) {
	if (command == 'O' || command == 'o' || command == 'F' || command == 'f') {
		return true;
	} else {
		return false;
	}

}
bool Game::isValidPosition(int xPos, int yPos) {
	Constants size;
	if (xPos < 0 || xPos > size.cols || yPos < 0 || yPos > size.cols) {
		return false;
	} else {
		return true;
	}
}

void Game::processUserCommand(char command, int xPos, int yPos) {
	switch (command) {
	case 'O':
	case 'o':
		openTheSquareAt(xPos, yPos);
		break;
	case 'f':
	case 'F':
		flagTheSquareAt(xPos, yPos);
		break;
	default:
		cout << "unknown command" << endl; //just to catch any other command error
	}

}
void Game::openTheSquareAt(int xPos, int yPos) {
	Constants constants;
	int squareContent = board.revealSquareAt(xPos, yPos);
	switch (squareContent) {
	case constants.MINE_PRESENT:						       //if it is a mine
		isGameOver = true;
		break;
	default:
		if (!board.isRevealed(xPos, yPos)) {
			board.setRevealedState(true, xPos, yPos);
			board.incrementSafeSquaresCount();
		} else {
			cout << "it is already revealed" << endl;
		}
		break;
	}
}

void Game::flagTheSquareAt(int xPos, int yPos) {
	//flag the position if and only if the position is not revealed yet
	int maxFlags = board.getMinesCount();
	static int currentFlags;
	if (!(board.isRevealed(xPos, yPos))) {
		if (board.isFlagged(xPos, yPos)) { 	//if revealed, check for flag status
			board.unflagAt(xPos, yPos); 		//if already flagged unflag it
			currentFlags = board.getFlagsCount();
			cout << "Flags remaining::" << maxFlags - currentFlags << endl;
		} else { //if it was'nt flagged, check for the maximum flags count and then decide whether to flag or not
			if (currentFlags < maxFlags) {
				board.flagAt(xPos, yPos);
				currentFlags = board.getFlagsCount();
				cout << "Flags remaining::" << maxFlags - currentFlags << endl; //to show the remaining flags
			} else {							//if was'nt flagged then flag it
				cout << "you can only flag 15 squares" << endl;
			}
		}
	} else {
		cout << "this square is already revealed" << endl;
	}
}
