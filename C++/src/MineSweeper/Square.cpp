/*
 * Tile.cpp
 *
 *  Created on: 26-Oct-2018
 *      Author: madhavasahu
 */
#include "Square.h"
Square::Square() {
		isSquareFlagged=false;
		isSquareRevealed=false;
		squareValue = 0;
}
Square::Square(int value) { // @suppress("Class members should be properly initialized")
	squareValue = value;

}
bool Square::getFlaggedState(){
		return isSquareFlagged;
	}
void Square::setFlaggedState(bool value){
		this->isSquareFlagged=value;
	}
void Square::setRevealedState(bool revealed){
	this->isSquareRevealed=revealed;
}
bool Square::getRevealedState(){
	return isSquareRevealed;
}
int Square::getSquareValue() {
	return squareValue;
}
const Square& Square::operator=(const Square &squareRef) {
	squareValue = squareRef.squareValue;
	return *this;
}
bool operator==(const Square &squareRef, const int value) {
	return squareRef.squareValue == value;
}
bool operator==(const Square &squareRef1, const Square &squareRef2) {
	return squareRef1.squareValue == squareRef2.squareValue;
}
bool operator !=(const Square &squareRef, int value) {
	return squareRef.squareValue != value;
}
std::ostream& operator<<(std::ostream &cout, const Square &squareRef) {
	cout << squareRef.squareValue;
	return cout;
}
