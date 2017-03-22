#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
#include "board.h"
#include "ship.h"
#include "destroyer.h"
#include "sub.h"
#include "cruiser.h"
#include "battleship.h"
#include "carrier.h"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Player {
	private:
		int			number;
		string		name;

		Board		shipBoard;
		Board		attackBoard;

		Ship		**destroyers;
		Ship		**subs;
		Ship		**cruisers;
		Ship		**battleships;
		Ship		**carriers;

		int			shipInventory[NUMBER_OF_SHIPS_TYPES][3];
		int			numberOfShips;
		int			shipsLeft;

		// Helper Fuctions
		bool isStraightLine(int startRow, int startCol, int endRow, int endCol);

		POSITION_TYPES isPositionValid(SHIPS shipType, int startRow, int startCol, int endRow, int endCol);
		Ship*		findShip(SHIPS shipType);

	public:
		Player(int number, string name);
		~Player();

		bool isActive();
		POSITION_TYPES positionShip(SHIPS shipType, int startRow, int startCol, int endRow, int endCol);
};

#endif // PLAYER_H
