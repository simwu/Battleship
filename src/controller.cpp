#include "controller.h"

Controller::Controller() {

}

Controller::~Controller() {
	// Delete the Players
	for (std::vector<Player*>::iterator iterator = players.begin(); iterator != players.end(); iterator++) {
		delete (*iterator);
	}

	// Clear the Players vector
	players.clear();
}

void Controller::newGame(int numberOfPlayers, string *names) {
	// Delete the old Player objects
	for (std::vector<Player*>::iterator iterator = players.begin(); iterator != players.end(); iterator++) {
		delete (*iterator);
	}
	players.clear();

	// Create the new Player objects
	for (int number = 1; number <= numberOfPlayers; number++) {
		Player *player = new Player(number, names[number - 1]);
		players.push_back(player);
	}
	currentPlayer = 1;

	this->numberOfPlayers = numberOfPlayers;
}

bool Controller::isGameInProgress() {
	bool gameInProgress = false;


	for (int player = 0; player < numberOfPlayers; player++) {
		if (players[player]->isActive()) {
			gameInProgress = true;

			break;
		}
	}

	return true;
}
