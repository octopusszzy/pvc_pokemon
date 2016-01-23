#pragma once
#include "Pokemon.h"
#include "Ability.h"
#include "Game.h"

#define TeamNameLength 20

class Team{
	friend class Game;
private:
	char name[TeamNameLength+1];
	int chooseNextPokemon(int alive, bool randomGenerate);

	int bind;

	bool stealthRock;
	int spikes;
	int toxicSpikes;
	bool stickyWeb;
	Team* copy();
public:
	Pokemon* pokemons[6];
	int totalPokemons;
	int alivePokemons;

	Team(char *n = "No name");
	~Team();
	void showAll();
	void showHitPoints(int pos);
	void set(int _id, int _level, bool information = true, char* _nickname = NULL, Gender _gender = Male, Nature _nature = Hardy, Item _item = EMPTY, int _happiness = 255);
	void reset(int pos, bool information);
	void move(int s, Team* rival, Game* game, bool information = true);
	void pokemonSwitch(int pos, bool information = true);
	void setEvs(int pos, int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed);
	void setIvs(int pos, int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed);
	void setAbility(int pos, Ability _ability);
	void setSkill(int pos, int skillId);

	int generateLegalMove(int *moves, Team* rivalTeam);
	int aiMove(int *moves, int movesCnt);
	int aiMoveRandom(int *moves, int movesCnt);
};