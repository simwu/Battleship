#include "ship.h"


// KEEP THIS CONSTRUCTOR
// NEED TO PASS THE SHIP'S NUMBER
Ship::Ship(SHIPS type, int size) {
	this->type = type;
	this->size = SHIP_POSITIONS[(int)type];
	this->status = SHIP_STATUS::NOT_DEPLOYED;
	this->number = number;

	// Ship positions. Create the rows
	positions = new int*[size];

	// Create the cols
	for (int row = 0; row < size; row++) {
		positions[row] = new int[2];
	}

	// Init the positions
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < 2; col++) {
			positions[row][col] = 0;
		}
	}

	// Ship hits. Create the rows
	hits = new int[size];

	// Init the hits
	for (int row = 0; row < size; row++) {
		hits[row] = 0;
	}
}

Ship::~Ship() {
	delete(positions);
	delete(hits);
}


SHIP_STATUS Ship::attacked(int row, int col) {
	SHIP_STATUS status = SHIP_STATUS::HIT_AGAIN;
	int numberOfHits = 0;

	for (int index = 0; index < size; index++) {
		if (positions[index][0] == row && positions[index][1] == col) {

			if (positions[index][2]	 == 0) {
				// Hit
				positions[index][2] = 1;
				numberOfHits++;
				status = SHIP_STATUS::DAMAGED;

			}
		}
		else if (positions[index][2] == 1) {
			numberOfHits++;
		}
	}

	if (numberOfHits == size) {
		status = SHIP_STATUS::SUNK;
	}
	return status;
}

SHIPS Ship::getType() {
	return type;
}

int Ship::getSize() {
	return size;
}

int Ship::getNumber() {
	return number;
}

SHIP_STATUS Ship::getStatus() {
	return status;
}

void Ship::deploy() {
	status = SHIP_STATUS::DEPLOYED;
}