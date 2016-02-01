#include "Skill.h"
#include "type.h"
#include "string.h"
#include "Category.h"
#include "Range.h"
#include "stdio.h"
#include "Data.h"

Skill::Skill(int _skillId)
{
	skillId = _skillId;
	skillId = skillId > SkillDataRange - 1 ? 0 : (skillId < 1 ? 0 : skillId);
	strcpy(name, Data::SkillName[skillId]);
	type = (Type)Data::SkillData[skillId][0];
	category = (Category)Data::SkillData[skillId][1];
	power = Data::SkillData[skillId][2];
	accuracy = Data::SkillData[skillId][3];
	ppMax = Data::SkillData[skillId][4];
	pp = ppMax;
	hitTimes = Data::SkillData[skillId][5];
	critialHit = Data::SkillData[skillId][6];
	priority = Data::SkillData[skillId][7];
	touch = Data::SkillData[skillId][8];
	voice = Data::SkillData[skillId][9];
	protectMode = Data::SkillData[skillId][10];
}

void Skill::affect()
{

}

void Skill::show()
{
	printf("skillId: %d power: %d cateory:",skillId, power);
	switch (category)
	{
	case Physical: printf("Physical"); break;
	case Special: printf("Special"); break;
	default: printf("Other");
	}
	printf(" type: %d pp:%d/%d accuracy:%d\n", (int)type, pp, ppMax, accuracy);
}

Skill* Skill::copy()
{
	Skill *tmp = new Skill(skillId);
	tmp->pp = pp;
	return tmp;
}

Skill::Skill(const Skill& skill)
{
	skillId = skill.skillId;
	strcpy(name, skill.name);
	type = skill.type;
	category = skill.category;
	power = skill.power;
	ppMax = skill.ppMax;
	pp = skill.pp;
	priority = skill.priority;
	accuracy = skill.accuracy;
	range = skill.range;
	hitTimes = skill.hitTimes;
	touch = skill.touch;
	voice = skill.voice;
}