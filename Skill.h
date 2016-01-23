#pragma once

#include "Type.h"
#include "Category.h"
#include "Range.h"
#include "Data.h"

class Skill{
public:
	Type type;
	Category category;
	int priority;
	char name[SkillNameLength];
	int power;
	int ppMax;
	int pp;
	int accuracy;
	Range range;
	int skillId;
	int hitTimes;
	int critialHit;
	int touch;

	Skill* copy();
	Skill(const Skill& skill);
	void affect();
	Skill(int _skillId);
	int getPP();
	void show();
};