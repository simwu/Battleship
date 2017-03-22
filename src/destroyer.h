#pragma once

#include "constants.h"
#include "ship.h"

class Destroyer : public Ship {
private:

public:
	Destroyer(SHIPS type, int size);
	~Destroyer();
};

