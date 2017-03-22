#include "board.h"

Board::Board(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	board = new Ship**[rows];

	for (int row = 0; row < rows; row++) {
		board[row] = new Ship*[cols];
	}

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			board[row][col] = new Ship(SHIPS::NO_SHIP, 0);
		}
	}
}

Board::~Board() {
	delete[] board;
}

int Board::getRows() {
	return rows;
}

int Board::getCols() {
	return cols;
}

Ship* Board::getLocation(int row, int col) const {
	return board[row - 1][col - 1];
}

bool Board::isOccupied(int row, int col) {
	return board[row - 1][col - 1]->getType() != SHIPS::NO_SHIP;
}

void Board::setLocation(int row, int col, Ship *ship) {
	board[row - 1][col - 1] = ship;
}
