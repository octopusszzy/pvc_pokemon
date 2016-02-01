#pragma once

#include "Type.h"
#include "Category.h"
#include "Constants.h"

class Data{
public:
	//Life,Attack,Defense,SpecialAttack,SpecialDefense,Speed,Type1,Type2
	static int PokemonData[PokemonDataRange][8];
	static char PokemonName[PokemonDataRange][PokemonNameLength];

	//Type,Category,Power,Accuracy,PP,HitTimes,CriticalHit,Priority,touch,voice,protectMode
	static int SkillData[SkillDataRange][11];

	static char SkillName[SkillDataRange][SkillNameLength];

	static char ItemName[ItemRange][ItemNameLength];

	static char AbilityName[AbilityRange][AbilityNameLength];
};