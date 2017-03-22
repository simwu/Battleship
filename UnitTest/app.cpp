#include "constants.h"
#include "controller.h"
#include "player.h"
#include "destroyer.cpp"
#include "sub.cpp"
#include "cruiser.cpp"
#include "battleship.cpp"
#include "carrier.cpp"
#include <string>
#include <iostream>
using namespace std;

// Needed by UnitTests
#include "controller.cpp"
#include "board.cpp"
#include "player.cpp"
#include "ship.cpp"

// Function prototypes
void testNewGame();
void testShipBoard();
void testPositionValidation();
void displayValidity(POSITION_TYPES positionType, int startRow, int startCol, int endRow, int endCol);

void main() {
	int menuOption = 0;

	while (menuOption != 9) {

		cout << "Unit Tests" << endl;
		cout << "1. Test New Game" << endl;
		cout << "2. Test Ship Board" << endl;
		cout << "3. Test Position Validation via user input" << endl;
		cout << "9. Exit" << endl;

		cout << endl << "Enter your Menu option: ";
		cin >> menuOption;
		cin.clear();	
		cin.ignore(INT_MAX, '\n');

		switch (menuOption){

		case 1: {
			testNewGame();
			break;
		}
		case 2: {
			testShipBoard();
			break;
		}
		case 3: {
			testPositionValidation();
			break;
		}
		case 9: {
			cout << endl << "All Unit Tests completed." << endl << endl;
			break;
		}
		default: {
			cout << endl << "Invalid Menu option." << endl << endl;
			break;
		}
		}
	}
}

void testNewGame() {
	// Test object creation and deletion
	Controller controller;

	string *players = new string[3];
	players[0] = "Javier";
	players[1] = "Refugio";
	players[2] = "Michael";

	controller.newGame(3, players);
}

// SIMPLIFIED
void testShipBoard() {
	// Test the new Boards
	Board shipBoard(100, 100);

	cout << "Testing the Ship Board" << endl << endl;

	for (int row = 1; row <= shipBoard.getRows(); row++) {
		for (int col = 1; col <= shipBoard.getCols(); col++) {
			// NEW
			Ship *ship = shipBoard.getLocation(row, col);
			cout << "[" << row << "][" << col << "]: " << SHIP_TYPE_NAMES[(int)ship->getType()] << endl;
		}
	}

	cout << endl;

	/*
	// Test Board (array)
	Player playerArray(1, "Javier");
	const int(*boardPtr)[BOARD_ROWS] = playerArray.getBoardArray();

	cout << "Test Board (array)" << endl << endl;

	for (int row = 0; row < BOARD_ROWS; row++) {
	for (int col = 0; col < BOARD_COLS; col++) {
	cout << "[" << (row) << "][" << (col) << "]\t" << boardPtr[row][col] << endl;
	// boardPtr is const, cannot be modified
	//boardPtr[row][col] = 2;
	}
	}

	// Test Board (vector)
	Player playerVector(1, "Javier");
	// Without declaring const vector, builds OK and allows modification
	const vector<vector<int>> boardVector = playerVector.getBoardVector();

	cout << endl << "Test Board (vector)" << endl << endl;

	for (int row = 0; row < boardVector.size(); row++) {
	for (int col = 0; col < boardVector[row].size(); col++) {
	cout << "[" << (row) << "][" << (col) << "]\t" << boardVector[row][col] << endl;

	// Able to modify the vector because not declare const in main()
	//boardVector[row][col] = 2;
	}
	}

	// Creating another Player causes stack overflow in main()
	//Player playerVector2(1, "Jude");
	vector<vector<int>> boardVector2 = playerVector.getBoardVector();

	cout << endl << "Test Board (local vector)" << endl << endl;
	*/
}

void testPositionValidation() {
	// Test positions via user input
	bool finished = false;
	int type = 0;
	int startRow = 0;
	int startCol = 0;
	int endRow = 0;
	int endCol = 0;

	// Test Player position validation
	Player player(1, "Javier");

	cout << endl << "Enter ship type, start row, start col, end row, end col. Enter ship type 0 to exit:" << endl << endl;

	while (!finished) {
		cout << "Enter ship type (1-5): ";
		cin >> type;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		if (type > 0) {
			cout << "Enter start row: ";
			cin >> startRow;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Enter start col: ";
			cin >> startCol;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Enter end row:  ";
			cin >> endRow;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "Enter end col:  ";
			cin >> endCol;
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			SHIPS ship = SHIPS::NO_SHIP;

			switch (type) {
			case 1: {
				ship = SHIPS::DESTROYER;
				break;
			}
			case 2: {
				ship = SHIPS::SUB;
				break;
			}
			case 3: {
				ship = SHIPS::CRUISER;
				break;
			}
			case 4: {
				ship = SHIPS::BATTLESHIP;
				break;
			}
			case 5: {
				ship = SHIPS::CARRIER;
				break;
			}
			}

			POSITION_TYPES positionType = player.positionShip(ship, startRow, startCol, endRow, endCol);
			displayValidity(positionType, startRow, startCol, endRow, endCol);
		}
		else {
			finished = true;
		}
	}

	cout << endl;
}

void displayValidity(POSITION_TYPES positionType, int startRow, int startCol, int endRow, int endCol) {
	cout << endl;
	switch (positionType) {
	case POSITION_TYPES::NOT_ON_SHIP_BOARD: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are not on the Ship Board" << endl << endl;
		break;
	}
	case POSITION_TYPES::NOT_A_STRAIGHT_LINE: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are not on a straight line" << endl << endl;
		break;
	}
	case POSITION_TYPES::INVALID_NUMBER_POSITIONS: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are an invalid number of positions" << endl << endl;
		break;
	}
	case POSITION_TYPES::ALREADY_OCCUPIED: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are already occupied on the Ship Board" << endl << endl;
		break;
	}
	case POSITION_TYPES::EAST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on an EAST horizontal line" << endl << endl;
		break;
	}
	case POSITION_TYPES::WEST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a WEST horizontal line" << endl << endl;
		break;
	}
	case POSITION_TYPES::NORTH: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a NORTH vertical line" << endl << endl;
		break;
	}
	case POSITION_TYPES::SOUTH: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a SOUTH vertical line" << endl << endl;
		break;
	}
	case POSITION_TYPES::NORTH_EAST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a NORTH-EAST diagonal line" << endl << endl;
		break;
	}
	case POSITION_TYPES::NORTH_WEST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a NORTH-WEST diagonal line" << endl << endl;
		break;
	}
	case POSITION_TYPES::SOUTH_EAST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a SOUTH-EAST diagonal line" << endl << endl;
		break;
	}
	case POSITION_TYPES::SOUTH_WEST: {
		cout << startRow << "," << startCol << " to " << endRow << "," << endCol << " are on a SOUTH-WEST diagonal line" << endl << endl;
		break;
	}
	}
}
