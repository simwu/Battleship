#pragma once

#include "constants.h"
#include "ship.h"

class Board {
private:
	Ship	***board;
	int		rows;
	int		cols;

public:
	Board(int rows, int cols);
	~Board();

	// Getters
	int getRows();
	int getCols();

	Ship* getLocation(int row, int col) const;
	bool isOccupied(int row, int col);

	// Setters
	void setLocation(int row, int col, Ship *ship);
};
