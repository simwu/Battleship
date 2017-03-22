#ifndef SHIP_H
#define SHIP_H

#include "constants.h"

class Ship {
	private:
		SHIPS			type;
		int				number;
		SHIP_STATUS		status;
		int				size;
		int				**positions;
		int				*hits;

	public:

		Ship(SHIPS type, int number);
		~Ship();

		SHIPS getType();
		int getNumber();
		SHIP_STATUS getStatus();
		int getSize();
		
		void deploy();

		SHIP_STATUS attacked(int row, int col);
};

#endif // SHIP_H
