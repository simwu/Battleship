#pragma once

#include "constants.h"
#include "ship.h"

class Carrier : public Ship {
private:

public:
	Carrier(SHIPS type, int size);
	~Carrier();
};

