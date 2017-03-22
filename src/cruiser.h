#pragma once

#include "constants.h"
#include "ship.h"

class Cruiser : public Ship {
private:

public:
	Cruiser(SHIPS type, int size);
	~Cruiser();
};

