#pragma once

#include "Type.h"
#include "Skill.h"
#include "Item.h"
#include "Ability.h"
#include "Gender.h"
#include "Nature.h"
#include "Data.h"
#include "State.h"
#include "stdlib.h"
#include "Team.h"
#include "Game.h"

#define Changes 8

class Pokemon{
	friend class Team;
	friend class Game;
private:
	char nickname[PokemonNameLength];
	char name[PokemonNameLength];
	int id;
	Type type[2];
	Gender gender;
	int level;
	Nature nature;
	Item item;
	int happiness;
	Ability ability;
	Ability copiedAbility;

	int EVs[6];//努力值
	int IVs[6];//个体值
	int BaseStats[6];//种族值
	int HitPoints[6];//能力值
	//Life,Attack,Defense,SpecialAttack,SpecialDefense,Speed,Accuracy,Avoidance
	int LevelChanges[Changes];
	int life;
	Skill *skills[5];
	bool substitute;
	State state;
	int sleepCnt;
	bool confused;
	bool charmed;
	bool seed;
	bool curse;
	bool fireFlash;
	bool afraid;
	int choice;//专爱系列
	int lastSkill;
	int heavyPoisoningCnt;

	void calculatePoints();
	void calculateNature();
	int calculateHurt(Type attackType, Type defendType1, Type defendType2, int &hurt);
	void setBaseStats(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed);
	bool legalEVs(int ev);
	bool legalIVs(int iv);
	int calculateLevelChange(int base, int change);
	int calculateCriticalHit(int level);
	int calculateAccuracy(int level, Pokemon* rival);
	void reduceLife(int amount, bool information);
	void addLife(int amount, bool information);
	bool generateRandom(int probability, int base = 100);
	int calculateFiveHits();
	//等级变化,pos表示LevelChange的位置,amount表示变化量,可正可负
	void levelChange(int pos, int amount, bool information);
	int calculateHeavyPoisoning();
	State calculateEffectSpore();

	Pokemon(int _id, int _level, char* _nickname = NULL, Gender _gender = Male, Nature _nature = Hardy, Item _item = EMPTY, int _happiness = 255);
	void setEVs(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed);
	void setIVs(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed);
	void setAbility(Ability _ability);
	void setSkill(int skillId);

	void setItem(Item _item);
	void releaseItem();

	~Pokemon();
	void showHitPoints();
	bool hasSubstitute();
	Pokemon* copy();
	Pokemon(const Pokemon& pokemon);
	void attack(Game* game, Team* rivalTeam, int skillPos, bool information = true);
	void showAll();
	void setState(State _state, Pokemon* rival, bool information);
};