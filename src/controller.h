#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "constants.h"
#include "player.h"
#include <vector>
#include <string>

using namespace std;

class Controller {

private:
	vector<Player*> players;
	int             currentPlayer;
	int				numberOfPlayers;

	// Helper functions
	void nextPlayer();

public:
	Controller();
	~Controller();
	
	const string VERSION = "Battleship v0.1";

	void newGame(int numberOfPlayers, string *names);
	bool isGameInProgress();
};

#endif // CONTROLLER_H
