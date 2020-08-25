/*
 * GameExceptions.h
 *
 *  Created on: 03-Nov-2018
 *      Author: madhavasahu
 */
//this file is to contain all the exceptions implementation used in the Game

#ifndef GAMEEXCEPTIONS_H_
#define GAMEEXCEPTIONS_H_
using namespace std;
#include<exception>
class InvalidCommand: public exception {
public:
	virtual const char* what() const throw () {
		return "Invalid command.enter the correct command";
	}
};
class InvalidResponse: public exception {
public:
	virtual const char* what() const throw () {
		return "Invalid response.enter the correct response";
	}
};
class InvalidPosition: public exception {
public:
	virtual const char* what() const throw () {
		return "Invalid position.enter the correct position";
	}
};

#endif /* GAMEEXCEPTIONS_H_ */
