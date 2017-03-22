#include "player.h"

Player::Player(int number, string name) : shipBoard(BOARD_ROWS, BOARD_COLS), attackBoard(BOARD_ROWS, BOARD_COLS) {
	this->number = number;
	this->name = name;
	

	// Create the Destroyers array. Create the rows
	destroyers = new Ship*[SHIP_QUANTITIES[(int)SHIPS::DESTROYER]];

	// Create the Destroyers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::DESTROYER]; shipNumber++) {
		destroyers[shipNumber - 1] = new Destroyer(SHIPS::DESTROYER, shipNumber);
	}

	// Create the Sub array. Create the rows
	subs = new Ship*[SHIP_QUANTITIES[(int)SHIPS::SUB]];

	// Create the Subs
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::SUB]; shipNumber++) {
		subs[shipNumber - 1] = new Sub(SHIPS::SUB, shipNumber);
	}
	
	// Create the Cruisers array. Create the rows
	cruisers = new Ship*[SHIP_QUANTITIES[(int)SHIPS::CRUISER]];

	// Create the Cruisers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::CRUISER]; shipNumber++) {
		cruisers[shipNumber - 1] = new Cruiser(SHIPS::CRUISER, shipNumber);
	}

	// Create the Battleships array. Create the rows
	battleships = new Ship*[SHIP_QUANTITIES[(int)SHIPS::BATTLESHIP]];

	// Create the Battleships
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::BATTLESHIP]; shipNumber++) {
		battleships[shipNumber - 1] = new Battleship(SHIPS::BATTLESHIP, shipNumber);
	}

	// Create the Carriers array. Create the rows
	carriers = new Ship*[SHIP_QUANTITIES[(int)SHIPS::CARRIER]];

	// Create the Carriers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::CARRIER]; shipNumber++) {
		carriers[shipNumber - 1] = new Carrier(SHIPS::CARRIER, shipNumber);
	}

	//Create the Ship Inventory
	numberOfShips = 0;

	for (int shipNumber = 1; shipNumber <= NUMBER_OF_SHIPS_TYPES; shipNumber++) {
		// Col 0: Total number of ships of this type
		shipInventory[shipNumber - 1][0] = SHIP_QUANTITIES[(int)SHIP_TYPES[shipNumber]];
		// Col 1: Number of ships of this type left
		shipInventory[shipNumber - 1][1] = SHIP_QUANTITIES[(int)SHIP_TYPES[shipNumber]];
		// Col 2: Number of ships of this type currently deployed
		shipInventory[shipNumber - 1][2] = 0;

		numberOfShips = numberOfShips + SHIP_QUANTITIES[(int)SHIP_TYPES[shipNumber]];
	}

	shipsLeft = numberOfShips;

}

Player::~Player() {
	// Delete the Destroyers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::DESTROYER]; shipNumber++) {
		delete(destroyers[shipNumber - 1]);
	}
	delete(destroyers);

	// Delete the Subs
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::SUB]; shipNumber++) {
		delete(subs[shipNumber - 1]);
	}
	delete(subs);

	// Delete the Cruisers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::CRUISER]; shipNumber++) {
		delete(cruisers[shipNumber - 1]);
	}
	delete(cruisers);

	// Delete the Battleships
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::BATTLESHIP]; shipNumber++) {
		delete(battleships[shipNumber - 1]);
	}
	delete(battleships);

	// Delete the Carriers
	for (int shipNumber = 1; shipNumber <= SHIP_QUANTITIES[(int)SHIPS::CARRIER]; shipNumber++) {
		delete(carriers[shipNumber - 1]);
	}
	delete(carriers);
}

POSITION_TYPES Player::positionShip(SHIPS shipType, int startRow, int startCol, int endRow, int endCol) {

	POSITION_TYPES positionType = POSITION_TYPES::NO_SHIPS_OF_THIS_TYPE;

	// Check Player has at least one Ship of this type left
	if (shipInventory[(int)shipType][1] > 0) {

		// Validate Ship positions
		positionType = isPositionValid(shipType, startRow, startCol, endRow, endCol);

		// Check all the Ship positions are unoccupied
		int startingRow = startRow;
		int endingRow = endRow;
		int startingCol = startCol;
		int endingCol = endCol;

		switch (positionType) {
			case POSITION_TYPES::SOUTH: {
				// Flip South orientation North
				startingRow = endRow;
				endingRow = startRow;
			}
			case POSITION_TYPES::NORTH: {
				for (int row = startingRow; row <= endingRow; row++) {
					for (int col = startingCol; col <= endingCol; col++) {
						if (shipBoard.isOccupied(row, col)) {
							positionType = POSITION_TYPES::ALREADY_OCCUPIED;

							// Finished
							col = endingCol;
							row = endingRow;
						}
					}
				}

				// Position the Ship
				if (positionType != POSITION_TYPES::ALREADY_OCCUPIED) {
					for (int row = startingRow; row <= endingRow; row++) {
						for (int col = startingCol; col <= endingCol; col++) {
							Ship *ship = findShip(shipType);
							shipBoard.setLocation(row, col, ship);
						}
					}
				}

				break;
			}
			case POSITION_TYPES::EAST: {
				// Flip East orientation West
				startingCol = endCol;
				endingCol = startCol;
			}
			case POSITION_TYPES::WEST: {
				for (int row = startingRow; row <= endingRow; row++) {
					for (int col = startingCol; col <= endingCol; col++) {
						if (shipBoard.isOccupied(row, col)) {
							positionType = POSITION_TYPES::ALREADY_OCCUPIED;

							// Finished
							col = endingCol;
							row = endingRow;
						}
					}
				}

				// Position the Ship
				if (positionType != POSITION_TYPES::ALREADY_OCCUPIED) {
					for (int row = startingRow; row <= endingRow; row++) {
						for (int col = startingCol; col <= endingCol; col++) {
							Ship *ship = findShip(shipType);
							shipBoard.setLocation(row, col, ship);
						}
					}
				}

				break;
			}
			case POSITION_TYPES::SOUTH_EAST: {
				// Flip South East orientation North West
				startingRow = endRow;
				endingRow = startRow;
				startingCol = endCol;
				endingCol = startCol;
			}
			case POSITION_TYPES::NORTH_WEST: {
				int diagonalCol = 0;

				for (int row = startingRow; row <= endingRow; row++) {
					for (int col = startingCol + diagonalCol; col <= startingCol + diagonalCol; col++) {
						if (shipBoard.isOccupied(row, col)) {
							positionType = POSITION_TYPES::ALREADY_OCCUPIED;

							// Finished
							col = endingCol;
							row = endingRow;
						}
					}
					diagonalCol++;
				}

				// Position the Ship
				if (positionType != POSITION_TYPES::ALREADY_OCCUPIED) {
					int diagonalCol = 0;

					for (int row = startingRow; row <= endingRow; row++) {
						for (int col = startingCol + diagonalCol; col <= startingCol + diagonalCol; col++) {
							Ship *ship = findShip(shipType);
							shipBoard.setLocation(row, col, ship);
						}
						diagonalCol++;
					}
				}

				break;
			}
			case POSITION_TYPES::SOUTH_WEST: {
				// Flip South West orientation North East
				startingRow = endRow;
				endingRow = startRow;
				startingCol = endCol;
				endingCol = startCol;
			}
			case POSITION_TYPES::NORTH_EAST: {
				int diagonalCol = 0;

				for (int row = startingRow; row <= endingRow; row++) {
					for (int col = startingCol + diagonalCol; col >= startingCol + diagonalCol; col--) {
						if (shipBoard.isOccupied(row, col)) {
							positionType = POSITION_TYPES::ALREADY_OCCUPIED;

							// Finished
							col = endingCol;
							row = endingRow;
						}
					}
					diagonalCol--;
				}

				// Position the Ship
				if (positionType != POSITION_TYPES::ALREADY_OCCUPIED) {
					int diagonalCol = 0;

					for (int row = startingRow; row <= endingRow; row++) {
						for (int col = startingCol + diagonalCol; col >= startingCol + diagonalCol; col--) {
							Ship *ship = findShip(shipType);
							shipBoard.setLocation(row, col, ship);
						}
						diagonalCol--;
					}
				}

				break;
			}
		}
	}

	return positionType;
}

bool Player::isStraightLine(int startRow, int startCol, int endRow, int endCol) {
	bool straightLine = false;

	// Horizontal or vertical line
	if (startRow == endRow || startCol == endCol) {
		// Must be a straight line
		straightLine = true;
	}
	// Diagonal line
	else if (startCol < endCol || startCol > endCol) {
		// Check for a straight line
		if (abs(startRow - endRow) == abs(startCol - endCol)) {
			// Must be a straight line
			straightLine = true;
		}
	}

	return straightLine;
}

POSITION_TYPES Player::isPositionValid(SHIPS shipType, int startRow, int startCol, int endRow, int endCol) {
	POSITION_TYPES positionType = POSITION_TYPES::NOT_ON_SHIP_BOARD;
	int numberPositions = 0;

	// Validate coordinates lie within the Ship Board
	if ((startRow <= shipBoard.getRows() &&
		startCol <= shipBoard.getCols() &&
		endRow <= shipBoard.getRows() &&
		endCol <= shipBoard.getCols())) {

		// Validate the coordinates lie on a straight line
		if (isStraightLine(startRow, startCol, endRow, endCol)) {

			// Horizontal line
			if (startRow == endRow) {
				numberPositions = abs(endCol - startCol) + 1;

				// EAST-WEST orientation
				if (startCol > endCol) {
					positionType = POSITION_TYPES::EAST;
				}
				else {
					positionType = POSITION_TYPES::WEST;
				}
			}
			// Vertical line
			else if (startCol == endCol) {
				numberPositions = abs(endRow - startRow) + 1;

				// NORTH-SOUTH orientation
				if (startRow < endRow) {
					positionType = POSITION_TYPES::NORTH;
				}
				else {
					positionType = POSITION_TYPES::SOUTH;
				}
			}
			// Diagonal line
			else {
				numberPositions = abs(startRow - endRow) + 1;

				// NORTH-EAST - NORTH-WEST orientation
				if (startRow < endRow && startCol > endCol) {
					positionType = POSITION_TYPES::NORTH_EAST;
				}
				else if (startRow < endRow && startCol < endCol) {
					positionType = POSITION_TYPES::NORTH_WEST;
				}
				// SOUTH-EAST - SOUTH-WEST orientation
				else if (startRow > endRow && startCol > endCol) {
					positionType = POSITION_TYPES::SOUTH_EAST;
				}
				else {
					positionType = POSITION_TYPES::SOUTH_WEST;
				}
			}

			// Validate number of positions
			if (numberPositions != SHIP_POSITIONS[(int)shipType]) {
				positionType = POSITION_TYPES::INVALID_NUMBER_POSITIONS;
			}
		}
		else {
			positionType = POSITION_TYPES::NOT_A_STRAIGHT_LINE;
		}
	}

	return positionType;
}

Ship* Player::findShip(SHIPS shipType) {
	Ship *ship = new Ship(SHIPS::NO_SHIP, 0);

	switch (shipType) {
		case SHIPS::DESTROYER: {
			for (int shipNumber = 1; shipNumber <= shipInventory[(int)SHIPS::DESTROYER - 1][0]; shipNumber++) {
				if (destroyers[shipNumber - 1]->getStatus() == SHIP_STATUS::NOT_DEPLOYED) {
					ship = destroyers[shipNumber - 1];
					ship->deploy();
				}
			}

			break;
		}
		case SHIPS::SUB: {
			for (int shipNumber = 1; shipNumber <= shipInventory[(int)SHIPS::SUB - 1][0]; shipNumber++) {
				if (subs[shipNumber - 1]->getStatus() == SHIP_STATUS::NOT_DEPLOYED) {
					ship = subs[shipNumber - 1];
					ship->deploy();
				}
			}

			break;
		}
		case SHIPS::CRUISER: {
			for (int shipNumber = 1; shipNumber <= shipInventory[(int)SHIPS::CRUISER - 1][0]; shipNumber++) {
				if (cruisers[shipNumber - 1]->getStatus() == SHIP_STATUS::NOT_DEPLOYED) {
					ship = cruisers[shipNumber - 1];
					ship->deploy();
				}
			}

			break;
		}
		case SHIPS::BATTLESHIP: {
			for (int shipNumber = 1; shipNumber <= shipInventory[(int)SHIPS::BATTLESHIP - 1][0]; shipNumber++) {
				if (battleships[shipNumber - 1]->getStatus() == SHIP_STATUS::NOT_DEPLOYED) {
					ship = battleships[shipNumber - 1];
					ship->deploy();
				}
			}

			break;
		}
		case SHIPS::CARRIER: {
			for (int shipNumber = 1; shipNumber <= shipInventory[(int)SHIPS::CARRIER - 1][0]; shipNumber++) {
				if (carriers[shipNumber - 1]->getStatus() == SHIP_STATUS::NOT_DEPLOYED) {
					ship = carriers[shipNumber - 1];
					ship->deploy();
				}
			}

			break;
		}
	}

	return ship;
}

bool Player::isActive() {
	return numberOfShips > 0;
}