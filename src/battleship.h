#pragma once

#include "constants.h"
#include "ship.h"

class Battleship : public Ship {
private:

public:
	Battleship(SHIPS type, int size);
	~Battleship();
};

