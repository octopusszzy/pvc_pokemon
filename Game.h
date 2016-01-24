#pragma once

#include "Team.h"
#include "Weather.h"
#include "Pokemon.h"

class Game{
	friend class Pokemon;
	friend class Team;
private:
	
	Weather weather;
	int weatherCnt;

	Team* teams[2];
	//return -7 if error
	int calculatePriority(int move, int team, bool information);
	int round;
public:
	Game(Team* team0, Team* team1);
	~Game();
	bool Round(int move0, int move1, bool information = true);
	int autoRun();
	int getRound();
	void aiMoveMonteCarlo(int &move0, int &move1);
};