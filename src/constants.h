#ifndef CONSTANTS_H
#define CONSTANTS_H

// NEW
#include <string>
using namespace std;

const int   MIN_PLAYERS = 2;
const int   MAX_PLAYERS = 4;
const int   BOARD_ROWS = 25;
const int   BOARD_COLS = 25;

const int   NUMBER_OF_SHIPS_TYPES = 5;

enum class SHIPS {
	NO_SHIP = 0,
	DESTROYER = 1,
	SUB = 2,
	CRUISER = 3,
	BATTLESHIP = 4,
	CARRIER = 5
};

enum class DESTROYERS {
	D1 = 1,
	D2 = 2,
	D3 = 3,
	D4 = 4,
	D5 = 5
};

enum class SUBS {
	S1 = 1,
	S2 = 2,
	S3 = 3,
	S4 = 4,
	S5 = 5
};

const int SHIP_QUANTITIES[] = {
	0, 1, 1, 1, 1, 1
};

// Needed for use within a for loop in Player constructor
const SHIPS SHIP_TYPES[] = {
	SHIPS::NO_SHIP,
	SHIPS::DESTROYER,
	SHIPS::SUB,
	SHIPS::CRUISER,
	SHIPS::BATTLESHIP,
	SHIPS::CARRIER
};

const string SHIP_TYPE_NAMES[] = {
	"No Ship",
	"Destroyer",
	"Sub",
	"Cruiser",
	"Battleship",
	"Carrier"
};

const int   SHIP_POSITIONS[] = {
	0, 2, 3, 3, 4, 5
};

enum class POSITION_TYPES {
	NO_SHIPS_OF_THIS_TYPE = 1,
	NOT_ON_SHIP_BOARD = 2,
	NOT_A_STRAIGHT_LINE = 3,
	INVALID_NUMBER_POSITIONS = 4,
	ALREADY_OCCUPIED = 5,
	EAST = 6,
	WEST = 7,
	NORTH = 8,
	SOUTH = 9,
	NORTH_EAST = 10,
	NORTH_WEST = 11,
	SOUTH_EAST = 12,
	SOUTH_WEST = 13
};

enum class SHIP_STATUS {
	NOT_DEPLOYED,
	DEPLOYED,
	DAMAGED,
	HIT_AGAIN,
	SUNK
};

#endif // CONSTANTS_H
