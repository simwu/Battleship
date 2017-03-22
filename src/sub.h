#pragma once

#include "constants.h"
#include "ship.h"

class Sub : public Ship {
private:

public:
	Sub(SHIPS type, int size);
	~Sub();
};

