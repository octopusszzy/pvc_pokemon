#include "Pokemon.h"
#include "stdio.h"
#include "Type.h"
#include "Gender.h"
#include "Nature.h"
#include "Data.h"
#include "Ability.h"
#include "string.h"
#include "stdlib.h"
#include "State.h"
#include "windows.h"
#include "Team.h"

void Pokemon::calculatePoints()
{
	HitPoints[0] = (BaseStats[0] * 2 + (EVs[0] >> 2) + IVs[0])*level / 100 + level + 10;
	for (int i = 1; i < 6; ++i)
	{
		HitPoints[i] = (BaseStats[i] * 2 + (EVs[i] >> 2) + IVs[i])*level / 100 + 5;
	}
	calculateNature();
}

Pokemon::~Pokemon()
{
	for (int i = 0; i < 5; ++i)
	{
		if (skills[i] != NULL)
			delete skills[i];
	}
}

void Pokemon::calculateNature()
{
	switch (nature)
	{
	case Hardy:
	case Docile:
	case Serious:
	case Bashful:
	case Quirky: break;
	case Lonely: HitPoints[1] += HitPoints[1] / 10; HitPoints[2] -= HitPoints[2] / 10; break;
	case Brave: HitPoints[1] += HitPoints[1] / 10; HitPoints[5] -= HitPoints[5] / 10; break;
	case Adamant: HitPoints[1] += HitPoints[1] / 10; HitPoints[3] -= HitPoints[3] / 10; break;
	case Naughty: HitPoints[1] += HitPoints[1] / 10; HitPoints[4] -= HitPoints[4] / 10; break;
	case Bold: HitPoints[2] += HitPoints[2] / 10; HitPoints[1] -= HitPoints[1] / 10; break;
	case Relaxed: HitPoints[2] += HitPoints[2] / 10; HitPoints[5] -= HitPoints[5] / 10; break;
	case Impish: HitPoints[2] += HitPoints[2] / 10; HitPoints[3] -= HitPoints[3] / 10; break;
	case Lax: HitPoints[2] += HitPoints[2] / 10; HitPoints[4] -= HitPoints[4] / 10; break;
	case Timid: HitPoints[5] += HitPoints[5] / 10; HitPoints[1] -= HitPoints[1] / 10; break;
	case Hasty: HitPoints[5] += HitPoints[5] / 10; HitPoints[2] -= HitPoints[2] / 10; break;
	case Jolly: HitPoints[5] += HitPoints[5] / 10; HitPoints[3] -= HitPoints[3] / 10; break;
	case Naive: HitPoints[5] += HitPoints[5] / 10; HitPoints[4] -= HitPoints[4] / 10; break;
	case Modest: HitPoints[3] += HitPoints[3] / 10; HitPoints[1] -= HitPoints[1] / 10; break;
	case Mild: HitPoints[3] += HitPoints[3] / 10; HitPoints[2] -= HitPoints[2] / 10; break;
	case Quiet: HitPoints[3] += HitPoints[3] / 10; HitPoints[5] -= HitPoints[5] / 10; break;
	case Rash: HitPoints[3] += HitPoints[3] / 10; HitPoints[4] -= HitPoints[4] / 10; break;
	case Calm: HitPoints[4] += HitPoints[4] / 10; HitPoints[1] -= HitPoints[1] / 10; break;
	case Gentle: HitPoints[4] += HitPoints[4] / 10; HitPoints[2] -= HitPoints[2] / 10; break;
	case Sassy: HitPoints[4] += HitPoints[4] / 10; HitPoints[5] -= HitPoints[5] / 10; break;
	case Careful: HitPoints[4] += HitPoints[4] / 10; HitPoints[3] -= HitPoints[3] / 10; break;
	default:;
	}
}

void Pokemon::setSkill(int skillId)
{
	int i = 0;
	for (; i < 4; ++i)
	{
		if (!skills[i])
			break;
		if (skills[i]->skillId == skillId)
		{
			printf("已经学会此技能了！\n");
			return;
		}
	}
	if (i == 4)
	{
		printf("技能已经满4个了！\n");
		return;
	}
	skills[i] = new Skill(skillId);
}

void Pokemon::setAbility(Ability _ability)
{
	Ability tmp;
	switch (_ability)
	{
	case ArenaTrap: tmp = ShadowTag; break;
	case VitalSpirit: tmp = Insomnia; break;
	case WhiteSmoke: tmp = ClearBody; break;
	case PurePower: tmp = HugePower; break;
	case ShellArmor: tmp = BattleArmor; break;
	case AirLock: tmp = CloudNine; break;
	default: tmp = _ability;
	}
	ability = tmp;
	copiedAbility = tmp;
}

Pokemon* Pokemon::copy()
{
	Pokemon *tmp = new Pokemon(id, level);
	tmp->choice = choice;
	strcpy(tmp->name, name);
	strcpy(tmp->nickname, nickname);
	tmp->id = id;
	tmp->type[0] = type[0];
	tmp->type[1] = type[1];
	tmp->gender = gender;
	tmp->level = level;
	tmp->nature = nature;
	tmp->item = item;
	tmp->happiness = happiness;
	tmp->ability = ability;
	for (int i = 0; i < 6; ++i)
	{
		tmp->EVs[i] = EVs[i];
		tmp->IVs[i] = IVs[i];
		tmp->BaseStats[i] = BaseStats[i];
		tmp->HitPoints[i] = HitPoints[i];
	}
	for (int i = 0; i < 8; ++i)
	{
		tmp->LevelChanges[i] = LevelChanges[i];
	}
	tmp->ability = ability;
	tmp->copiedAbility = ability;
	tmp->life = life;
	tmp->substitute = substitute;
	tmp->state = state;
	tmp->confused = confused;
	tmp->charmed = charmed;
	tmp->seed = seed;
	tmp->curse = curse;
	tmp->sleepCnt = sleepCnt;
	tmp->fireFlash = fireFlash;
	tmp->afraid = afraid;
	tmp->heavyPoisoningCnt = heavyPoisoningCnt;
	tmp->lastSkill = lastSkill;
	tmp->protectMode = protectMode;
	tmp->protectTime = protectTime;
	tmp->doubleRound = doubleRound;
	tmp->mad = mad;
	tmp->disableSkill = disableSkill;
	tmp->disableSkillCnt = disableSkillCnt;
	for (int i = 0; i < 4; ++i)
	{
		tmp->skills[i] = NULL;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!skills[i])
			break;
		tmp->skills[i] = skills[i]->copy();
	}
	tmp->skills[4] = new Skill(0);
	return tmp;
}


Pokemon::Pokemon(const Pokemon& pokemon)
{
	choice = pokemon.choice;
	strcpy(name, pokemon.name);
	strcpy(nickname, pokemon.nickname);
	id = pokemon.id;
	type[0] = pokemon.type[0];
	type[1] = pokemon.type[1];
	gender = pokemon.gender;
	level = pokemon.level;
	nature = pokemon.nature;
	item = pokemon.item;
	happiness = pokemon.happiness;
	ability = pokemon.ability;
	for (int i = 0; i < 6; ++i)
	{
		EVs[i] = pokemon.EVs[i];
		IVs[i] = pokemon.IVs[i];
		BaseStats[i] = pokemon.BaseStats[i];
		HitPoints[i] = pokemon.HitPoints[i];
	}
	for (int i = 0; i < 8; ++i)
	{
		LevelChanges[i] = pokemon.LevelChanges[i];
	}
	ability = pokemon.ability;
	copiedAbility = ability;
	life = pokemon.life;
	substitute = pokemon.substitute;
	state = pokemon.state;
	sleepCnt = pokemon.sleepCnt;
	confused = pokemon.confused;
	charmed = pokemon.charmed;
	seed = pokemon.seed;
	curse = pokemon.curse;
	fireFlash = pokemon.fireFlash;
	heavyPoisoningCnt = pokemon.heavyPoisoningCnt;
	afraid = pokemon.afraid;
	lastSkill = pokemon.lastSkill;
	protectMode = pokemon.protectMode;
	protectTime = pokemon.protectTime;
	doubleRound = pokemon.doubleRound;
	mad = pokemon.mad;
	disableSkill = pokemon.disableSkill;
	disableSkillCnt = pokemon.disableSkillCnt;
	for (int i = 0; i < 4; ++i)
	{
		skills[i] = NULL;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!pokemon.skills[i])
			break;
		skills[i] = pokemon.skills[i]->copy();
	}
	skills[4] = new Skill(0);
}

int Pokemon::calculateHeavyPoisoning()
{
	if (state == HeavyPoisoning && heavyPoisoningCnt >= 0)
	{
		switch (heavyPoisoningCnt)
		{
		case 0: return HitPoints[0] >> 4; break;
		case 1: return HitPoints[0] >> 3; break;
		case 2: return HitPoints[0] >> 2; break;
		default: return HitPoints[0] >> 1; 
		}
	}
	return 0;
}

Pokemon::Pokemon(int _id, int _level, char* _nickname, Gender _gender, Nature _nature, Item _item, int _happiness)
{
	choice = -1;
	id = _id;
	id = id >= PokemonDataRange ? 0 : (id < 0 ? 0 : id);
	strcpy(name, Data::PokemonName[id]);

	if (!_nickname)
	{
		strcpy(nickname, Data::PokemonName[id]);
	}
	else
		strcpy(nickname, _nickname);

	level = _level;
	level = level > 100 ? 100 : (level < 1 ? 1 : level);
	type[0] = (Type)Data::PokemonData[id][6];
	type[1] = (Type)Data::PokemonData[id][7];
	gender = _gender;
	item = EMPTY;
	nature = _nature;
	happiness = _happiness;
	substitute = false;
	ability = Disabled;
	copiedAbility = ability;
	state = NoState;
	sleepCnt = 0;
	confused = false;
	charmed = false;
	seed = false;
	curse = false;
	fireFlash = false;
	afraid = false;
	heavyPoisoningCnt = -1;
	lastSkill = -1;
	protectMode = 0;
	protectTime = 0;
	doubleRound = 0;
	mad = 0;
	disableSkill = -1;
	disableSkillCnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		EVs[i] = 0;
		IVs[i] = 31;
	}
	for (int i = 0; i < 8; ++i)
	{
		LevelChanges[i] = 0;
	}
	setBaseStats(Data::PokemonData[id][0], Data::PokemonData[id][1], Data::PokemonData[id][2], Data::PokemonData[id][3], Data::PokemonData[id][4], Data::PokemonData[id][5]);
	calculatePoints();
	life = HitPoints[0];
	for (int i = 0; i < 4; ++i)
	{
		skills[i] = NULL;
	}
	skills[4] = new Skill(0);
	setItem(_item);
}

bool Pokemon::legalEVs(int ev)
{
	return ev < 256 && ev > -1;
}

bool Pokemon::legalIVs(int iv)
{
	return iv < 32 && iv > -1;
}

void Pokemon::setEVs(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed)
{
	if (Life + Attack + Defense + SpecialAttack + SpecialDefense + Speed > 510 
		|| !legalEVs(Life) || !legalEVs(Attack) || !legalEVs(Defense) || !legalEVs(SpecialAttack) || !legalEVs(SpecialDefense) || !legalEVs(Speed))
	{
		printf("不合法的努力值！");
		return;
	}
	
	EVs[0] = Life;
	EVs[1] = Attack;
	EVs[2] = Defense;
	EVs[3] = SpecialAttack;
	EVs[4] = SpecialDefense;
	EVs[5] = Speed;
	calculatePoints();
	life = HitPoints[0];
	switch (item)
	{
	case AssaultVest:
		HitPoints[4] += (HitPoints[4] >> 1);
		break;
	case ChoiceBand:
		HitPoints[1] += (HitPoints[1] >> 1);
		break;
	case ChoiceScarf:
		HitPoints[5] += (HitPoints[5] >> 1);
		break;
	case ChoiceSpecs:
		HitPoints[3] += (HitPoints[3] >> 1);
		break;
	default:;
	}
}
void Pokemon::setIVs(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed)
{
	if (!legalIVs(Life) || !legalIVs(Attack) || !legalIVs(Defense) || !legalIVs(SpecialAttack) || !legalIVs(SpecialDefense) || !legalIVs(Speed))
	{
		printf("不合法的个体值！");
		return;
	}
	IVs[0] = Life;
	IVs[1] = Attack;
	IVs[2] = Defense;
	IVs[3] = SpecialAttack;
	IVs[4] = SpecialDefense;
	IVs[5] = Speed;
	calculatePoints();
	life = HitPoints[0];
	switch (item)
	{
	case AssaultVest:
		HitPoints[4] += (HitPoints[4] >> 1);
		break;
	case ChoiceBand:
		HitPoints[1] += (HitPoints[1] >> 1);
		break;
	case ChoiceScarf:
		HitPoints[5] += (HitPoints[5] >> 1);
		break;
	case ChoiceSpecs:
		HitPoints[3] += (HitPoints[3] >> 1);
		break;
	default:;
	}
}

void Pokemon::setBaseStats(int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed)
{
	BaseStats[0] = Life;
	BaseStats[1] = Attack;
	BaseStats[2] = Defense;
	BaseStats[3] = SpecialAttack;
	BaseStats[4] = SpecialDefense;
	BaseStats[5] = Speed;
	calculatePoints();
}

void Pokemon::showHitPoints()
{
	printf("%s(%s): ", nickname, name);
	for (int i = 0; i < 6; ++i)
	{
		printf("%d ", HitPoints[i]);
	}
	printf("level:%d ability:%s\n", level, Data::AbilityName[(int)ability]);
}

void Pokemon::showAll()
{
	printf("%s(%s): %dHP state: ", nickname, name, life);
	switch (state)
	{
	case Burn: printf("Burn"); break;
	case Paralysis: printf("Paralysis"); break;
	case Poisoning: printf("Poisoning"); break;
	case Sleeping: printf("Sleeping"); break;
	case Frozen: printf("Frozen"); break;
	case NoState:
	default: printf("NoState");
	}
	printf(" confused: %d charmed: %d item:%s\n", (int)confused, (int)charmed, Data::ItemName[(int)item]);
	for (int i = 0; i < 8; ++i)
	{
		printf("%d ", LevelChanges[i]);
	}
	printf("\n");
}

bool Pokemon::hasSubstitute()
{
	return substitute;
}

int Pokemon::calculateLevelChange(int base, int change)
{
	switch (change)
	{
	case 0: return base; break;
	case 1: return int(base * 1.5); break;
	case 2: return base * 2; break;
	case 3: return base * 3; break;
	case 4: return base * 4; break;
	case 5: return base * 6; break;
	case 6: return base * 8; break;
	case -1:return int(base / 1.5); break;
	case -2:return base / 2; break;
	case -3:return base / 3; break;
	case -4:return base / 4; break;
	case -5:return base / 6; break;
	case -6:return base / 8; break;
	default:printf("不合法的变化等级！\n"); return base;
	}
}

int Pokemon::calculateCriticalHit(int level)
{
	switch (level)
	{
	case 1: return 125; break;
	case 2: return 250; break;
	case 3: return 375; break;
	case 4: 
	case 5: return 500; break;
	case 6:
	default:return 1000;
	}
}

int Pokemon::calculateAccuracy(int level, Pokemon* rival)
{
	int t = 100;
	switch (level)
	{
	case -6:t = 33; break;
	case -5:t = 38; break;
	case -4:t = 43; break;
	case -3:t = 50; break;
	case -2:t = 60; break;
	case -1:t = 75; break;
	case 0: t = 100; break;
	case 1: t = 133; break;
	case 2: t = 167; break;
	case 3: t = 200; break;
	case 4: t = 233; break;
	case 5: t = 267; break;
	case 6: t = 300; break;
	default:
		if (level < -6)
			t = 33;
		else
			t = 300;
	}
	switch (rival->item)
	{
	case BrightPowder:
		t = int(t*0.9);
		break;
	default:;
	}
	return t;
}

int Pokemon::calculateFiveHits()
{
	int t = rand() % 6;
	switch (t)
	{
	case 0:
	case 1: return 2; break;
	case 2:
	case 3: return 3; break;
	case 4: return 4; break;
	case 5: return 5; break;
	}
}

bool Pokemon::generateRandom(int probability, int base)
{
	int t = rand();
	int ran = t % base;
	return ran < probability;
}

void Pokemon::attack(Game* game, Team* rivalTeam, int skillPos, bool information)
{
	/*if (information)
		printf("skillName = %s\n",skills[skillPos]->name);*/
	Team* team = game->teams[0];
	if (team == rivalTeam)
		team = game->teams[1];

	Pokemon* rival = rivalTeam->pokemons[0];
	if (skillPos < 0 || skillPos > 4 || !skills[skillPos])
	{
		if (information)
			printf("技能不合法！\n");
		return;
	}

	if (skillPos == disableSkill)
	{
		if (information)
			printf("技能被束缚，不能攻击\n");
		return;
	}

	if (choice != -1 && choice != skillPos && skillPos != 4)
	{
		if (information)
			printf("%s(%s)装备了道具%s，不能使用其他技能\n", nickname, name, Data::ItemName[(int)item]);
		return;
	}

	if (state == Sleeping)
	{
		bool awake = false;
		switch (sleepCnt)
		{
		case 1:
			if (ability == EarlyBird)
			{
				sleepCnt = 0;
				state = NoState;
				awake = true;
				if (information)
					printf("%s(%s)醒来了", nickname, name);
			}
			break;
		case 4:
			sleepCnt = 0;
			state = NoState;
			awake = true;
			if (information)
				printf("%s(%s)醒来了", nickname, name);
			break;
		case 2:
		case 3:
			if (rand() % 100 < 50)
			{
				sleepCnt = 0;
				state = NoState;
				awake = true;
				if (information)
					printf("%s(%s)醒来了", nickname, name);
			}
			break;
		default:;
		}
		if (!awake)
		{
			if (information)
				printf("%s(%s)正在睡觉\n", nickname, name);
			protectTime = 0;
			return;
		}
	}
	else if (state == Frozen)
	{
		bool melt = generateRandom(50);
		if (melt)
		{
			if (information)
				printf("%s(%s)解除了冰封\n", nickname, name);
			state = NoState;
		}
		else
		{
			if (information)
				printf("%s(%s)处于冰封状态中\n", nickname, name);
			protectTime = 0;
			return;
		}
	}
	else if (state == Paralysis)
	{
		bool stopParalysis = generateRandom(25);
		if (stopParalysis)
		{
			if (information)
				printf("%s(%s)因为麻痹，无法动弹\n", nickname, name);
			protectTime = 0;
			return;
		}
	}

	if (afraid && ability != InnerFocus)
	{
		if (information)
			printf("%s(%s)害怕了\n", nickname, name);
		protectTime = 0;
		return;
	}

	Skill* skill = skills[skillPos];
	if (!skill->pp && skillPos != 4)
	{
		if (information)
			printf("技能PP值已用完\n");
		protectTime = 0;
		return;
	}

	switch (item)
	{
	case AssaultVest:
		if (skill->category == Other)
		if (information)
			printf("%s(%s)装备了道具%s，不能使用变化类技能\n", nickname, name, Data::ItemName[(int)item]);
		protectTime = 0;
		return;
		break;
	default:;
	}

	if (ability == Truant && lastSkill != -1)
	{
		if (information)
			printf("%s(%s)正在玩\n", nickname, name);
		lastSkill = -1;
		protectTime = 0;
		return;
	}

	int i = 0;
	int hurt = 0;
	int totalHurt = 0;
	int totalHitTimes = 1;
	bool hit = false;

	if (!skill->protectMode)
		protectTime = 0;
	bool stopConfused = false;
	if (confused)
	{
		int relieveConfused = generateRandom(50, 100);
		if (relieveConfused)
		{
			if (information)
				printf("%s(%s)的混乱解除了\n", nickname, name);
			confused = false;
		}
	}
	if (confused)
	{
		if (information)
			printf("%s(%s)混乱了\n", nickname, name);
		stopConfused = generateRandom(50, 100);
	}
	if (stopConfused)
	{
		if (information)
			printf("%s(%s)攻击了自己\n", nickname, name);
		int tmp = HitPoints[1];
		int tmpDefense = HitPoints[2];
		if (ability == HugePower)
			tmp = tmp << 1;
		else if (ability == Hustle)
			tmp += (tmp >> 1);
		else if (ability == Guts && state != NoState)
			tmp += (tmp >> 1);
		else if (ability == MarvelScale && state != NoState)
			tmpDefense += (tmpDefense >> 1);
		if (state == Burn && ability != Guts)
			tmp = tmp >> 1;
		hurt = (level * 2 / 5 + 2) * calculateLevelChange(tmp, LevelChanges[1]) * 40 / calculateLevelChange(tmpDefense, LevelChanges[2]) / 50 + 2;
		int randomHurt = rand() % 39;
		hurt = hurt * (217 + randomHurt) / 255;
		hurt = min(life, hurt);
		reduceLife(hurt, team, information);
		if (information)
			printf("%s(%s)受到了%d点伤害\n", nickname, name, hurt);
	}
	else
	{
		if (information)
			printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
		--skill->pp;
		lastSkill = skillPos;

		switch (skill->skillId)
		{//蓄力攻击飞空潜水挖地等
		case 13:
			if (!doubleRound)
			{
				if (information)
					printf("%s(%s)在身边卷起了旋风\n", nickname, name);
				doubleRound = 1;
				return;
			}
			else
				doubleRound = 0;
			break;
		case 19:
			if (!doubleRound)
			{
				if (information)
					printf("%s(%s)飞上了天空\n", nickname, name);
				doubleRound = 2;
				return;
			}
			else
				doubleRound = 0;
			break;
		default:;
		}

		switch (rival->ability)
		{
		case Pressure:
			if (skill->pp > 0)
			{
				--skill->pp;
				if (information)
					printf("%s(%s)释放了压力");
			}
		case Soundproof:
			if (skill->voice)
			{
				if (information)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("%s(%s)的防音阻止了攻击\n", rival->nickname, rival->name);
				}
				return;
			}
			break;
		case VoltAbsorb:
			if (skill->type == Electric)
			{
				if (information)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("%s(%s)吸收了攻击回复了体力\n");
				}
				rival->addLife(min(rival->HitPoints[0] - rival->life, (rival->HitPoints[0] >> 2)), information);
				return;
			}
			break;
		case WaterAbsorb:
			if (skill->type == Water)
			{
				if (information)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("%s(%s)吸收了攻击回复了体力\n");
				}
				rival->addLife(min(rival->HitPoints[0] - rival->life, (rival->HitPoints[0] >> 2)), information);
				return;
			}
			break;
		case FlashFire:
			if (skill->type == Fire)
			{
				if (information && !rival->fireFlash)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("%s(%s)的火系技能变强了\n", rival->nickname, rival->name);
				}
				rival->fireFlash = true;
				return;
			}
			break;
		case Lightningrod:
			if (skill->type == Electric)
			{
				if (information)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("%s(%s)的特攻上升一级\n", rival->nickname, rival->name);
				}
				rival->levelChange(3, 1, rivalTeam, information);
				return;
			}
			break;
		case Levitate:
			if (skill->type == Ground)
			{
				if (information)
				{
					printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
					printf("技能%s没有命中\n", skill->name);
				}
				return;
			}
			break;
		case WonderGuard:
			if (skill->category != Other)
			{
				int tmpHurt = 0;
				int tmpT = calculateHurt(skill->type, rival->type[0], rival->type[1], tmpHurt);
				if (tmpT <= 1)
				{
					if (information)
					{
						printf("%s(%s)使用了技能%s\n", nickname, name, skill->name);
						printf("%s(%s)因为奇异守护守住了\n", rival->nickname, rival->name);
					}
					return;
				}
			}
			break;
		default:;
		}

		switch (item)
		{
		case ChoiceBand:
		case ChoiceScarf:
		case ChoiceSpecs:
			choice = skillPos;
			break;
		default:;
		}
		if (skill->hitTimes == 5)
			totalHitTimes = calculateFiveHits();
		else if (skill->hitTimes != 1)
			totalHitTimes = skill->hitTimes;
		for (; i < totalHitTimes && rival->life > 0; ++i)
		{
			int tmpSkillPower = skill->power;
			if (life < HitPoints[0] / 3)
			{
				if (ability == Overgrow && skill->type == Grass)
					tmpSkillPower += tmpSkillPower / 3;
				else if (ability == Blaze && skill->type == Fire)
					tmpSkillPower += tmpSkillPower / 3;
				else if (ability == Torrent && skill->type == Water)
					tmpSkillPower += tmpSkillPower / 3;
				else if (ability == Swarm && skill->type == Bug)
					tmpSkillPower += tmpSkillPower / 3;
			}
			if (skill->skillId == 57 && rival->doubleRound == 4)
				tmpSkillPower = tmpSkillPower << 1;
			if (skill->category == Physical)
			{
				int tmp = HitPoints[1];
				if (ability == HugePower)
					tmp = tmp << 1;
				else if (ability == Hustle)
					tmp += (tmp >> 1);
				else if (ability == Guts && state != NoState)
					tmp += (tmp >> 1);
				if (state == Burn && ability != Guts)
					tmp = tmp >> 1;

				int tmpDefense = rival->HitPoints[2];
				if (rival->ability == ThickFat && (skill->type == Ice || skill->type == Fire))
					tmpDefense = tmpDefense << 1;
				else if (rival->ability == MarvelScale && rival->state != NoState)
					tmpDefense += (tmpDefense >> 1);
				hurt = (level * 2 / 5 + 2) * calculateLevelChange(tmp, LevelChanges[1]) * tmpSkillPower / calculateLevelChange(tmpDefense, rival->LevelChanges[2]) / 50 + 2;
			}	
			else if (skill->category == Special)
			{
				int tmpDefense = rival->HitPoints[4];
				if (rival->ability == ThickFat && (skill->type == Ice || skill->type == Fire))
					tmpDefense = tmpDefense << 1;
				hurt = (level * 2 / 5 + 2) * calculateLevelChange(HitPoints[3], LevelChanges[3]) * tmpSkillPower / calculateLevelChange(tmpDefense, rival->LevelChanges[4]) / 50 + 2;
			}
				
			if (true)
			{
				if (skill->category == Other)
					hurt = 0;
				if (skill->type == type[0] || skill->type == type[1])
					hurt += (hurt >> 1);
				int randomHurt = rand() % 39;
				hurt = hurt * (217 + randomHurt) / 255;

				if (skill->type == Fire && fireFlash)
					hurt += (hurt >> 1);

				switch (game->weather)
				{
				case Rainy:
					if (skill->type == Water && ability != CloudNine && rival->ability != CloudNine)
						hurt += (hurt >> 1);
					break;
				case Shiny:
					if (skill->type == Fire && ability != CloudNine && rival->ability != CloudNine)
						hurt += (hurt >> 1);
					break;
				default:;
				}

				int t = calculateHurt(skill->type,rival->type[0],rival->type[1],hurt);
				int hitAccuracy = skill->accuracy * calculateAccuracy(LevelChanges[6] - rival->LevelChanges[7], rival) / 100;
				switch (rival->ability)
				{
				case SandVeil:
					if (game->weather == Sandstorm)
					{
						hitAccuracy -= hitAccuracy / 5;
					}
					break;
				default:;
				}

				switch (ability)
				{
				case Compoundeyes:
					hitAccuracy = int(hitAccuracy*1.3);
					break;
				case Hustle:
					if (skill->category == Physical)
						hitAccuracy = int(hitAccuracy*0.8);
					break;
				default:;
				}

				if (skill->protectMode)
				{
					for (int i = 0; i < protectTime; ++i)
						hitAccuracy = hitAccuracy >> 1;
				}
				switch (skill->skillId)
				{
				case 12:
				case 32:
					if (level >= rival->level)
						hitAccuracy = 30 + level - rival->level;
					else
						hitAccuracy = 0;
				default:;
				}
				hit = generateRandom(hitAccuracy);
				if (skill->protectMode)
				{
					if (hit)
						++protectTime;
					else
						protectTime = 0;
				}
				
				if (rival->doubleRound > 1)
				{
					if ((rival->doubleRound == 4 && skill->skillId == 57)){}
					hit = false;
				}

				switch (game->weather)
				{
				case Hailstone:
					if (skill->skillId == 59)
						hit = true;
					break;
				defaut:;
				}

				switch (rival->item)
				{
				case AirBalloon:
					if (skill->type == Ground)
					{
						hit = false;
						t = 0;
						hurt = 0;
					}
					break;
				default:;
				}

				switch (rival->protectMode)
				{
				case 1:
					if (information)
						printf("%s(%s)守住了攻击\n", rival->nickname, rival->name);
					return;
				case 2:
					if (information)
						printf("%s(%s)守住了攻击\n%s(%s)攻击迅速下降\n", rival->nickname, rival->name, nickname, name);
					levelChange(1, -2, team, information);
					return;
				case 3:
					if (information)
						printf("%s(%s)守住了攻击\n扎伤了%s(%s)\n", rival->nickname, rival->name, nickname, name);
					reduceLife((HitPoints[0] >> 3), team, information);
					return;
				default:;
				}

				if (hurt != 0 && hit)
				{
					bool critical = generateRandom(calculateCriticalHit(skill->critialHit), 1000);
					switch (rival->ability)
					{
					case BattleArmor:
						critical = false;
						break;
					default:;
					}
					if (critical)
					{
						//会心一击，尚未考虑狙击手
						if (information)
							printf("会心一击\n");
						hurt = int(hurt*1.5);
					}
					//命中
					hurt = min(hurt, rival->life);

					switch (rival->item)
					{
					case AirBalloon:
						if (information)
							printf("%s(%s)的%s爆炸了\n",rival->nickname,rival->name,Data::ItemName[(int)rival->item]);
						rival->releaseItem(information);
						break;
					case BabiriBerry:
						if (skill->type == Steel && t > 1)
						{
							hurt = hurt >> 1;
							if (information)
								printf("%s(%s)吃掉了%s，伤害减半\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->releaseItem(information);
						}
						break;
					case CellBattery:
						if (skill->type == Electric)
						{
							if (information)
								printf("%s(%s)使用了%s，攻击上升一级\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->levelChange(1, 1, rivalTeam, information);
							rival->releaseItem(information);
						}
						break;
					case ChartiBerry:
						if (skill->type == Rock && t > 1)
						{
							hurt = hurt >> 1;
							if (information)
								printf("%s(%s)吃掉了%s，伤害减半\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->releaseItem(information);
						}
						break;
					case ChilanBerry:
						if (skill->type == Normal)
						{
							hurt = hurt >> 1;
							if (information)
								printf("%s(%s)吃掉了%s，伤害减半\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->releaseItem(information);
						}
						break;
					case CobaBerry:
						if (skill->type == Flying && t > 1)
						{
							hurt = hurt >> 1;
							if (information)
								printf("%s(%s)吃掉了%s，伤害减半\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->releaseItem(information);
						}
						break;
					case ColburBerry:
						if (skill->type == Dark && t > 1)
						{
							hurt = hurt >> 1;
							if (information)
								printf("%s(%s)吃掉了%s，伤害减半\n", rival->nickname, rival->name, Data::ItemName[(int)rival->item]);
							rival->releaseItem(information);
						}
						break;
					default:;
					}

					switch (item)
					{
					case BlackBelt:
						if (skill->type == Fighting)
							hurt *= 1.2;
						break;
					case BlackGlasses:
						if (skill->type == Dark)
							hurt *= 1.2;
						break;
					case Charcoal:
						if (skill->type == Fire)
							hurt *= 1.2;
						break;
					case BugGem:
						if (skill->type == Bug)
						{
							hurt *= 1.3;
							releaseItem(information);
						}
						break;
					default:;
					}

					if (information)
					{
						if (t < 2)
							printf("效果一般 ");
						else if (t > 1)
						{
							printf("效果拔群 ");
						}
					}

					switch (rival->ability)
					{
					case Sturdy:
						if (hurt == rival->HitPoints[0])
						{
							--hurt;
							if (information)
								printf("%s(%s)因为坚硬站住了\n", rival->nickname, rival->name);
						}
						break;
					default:;
					}

					switch (skill->skillId)
					{
					case 49: hurt = 20; break;
					default:;
					}

					rival->reduceLife(hurt,rivalTeam, information);
					totalHurt += hurt;
					if (information)
						printf("%s(%s)受到了%d点伤害\n", rival->nickname, rival->name, hurt);
					if (skillPos == 4)
					{
						reduceLife((HitPoints[0] >> 2), team, information);
						if (information)
							printf("%s(%s)受到了拼命的反伤\n", nickname, name);
					}
					
					switch (rival->ability)
					{
					case FlameBody:
						if (skill->touch && state == NoState && ability != WaterVeil
							&& type[0] != Fire && type[1] != Fire)
						{
							if (generateRandom(30))
							{
								if (information)
									printf("%s(%s)受到了火焰身躯的影响\n", nickname, name);
								setState(Burn, rival, team, information);
							}
						}
						break;
					case ColorChange:
						if (skill->type != rival->type[0] && skill->type != rival->type[1])
						{
							if (information)
								printf("%s(%s)改变了属性\n", rival->nickname, rival->name);
							rival->type[0] = skill->type;
							rival->type[1] = NUL;
						}
						break;
					case EffectSpore:
					{
						if (skill->touch && state == NoState)
						{
							State s = calculateEffectSpore();
							if (s != NoState)
							{
								if (information)
									printf("%s(%s)受到了孢子的影响\n", nickname, name);
								setState(s, rival, team, information);
							}
						}
						break;
					}
					case PoisonPoint:
						if (skill->touch && state == NoState && ability != Immunity
							&& type[0] != Poison && type[1] != Poison
							&& type[0] != Steel && type[1] != Steel)
						{
							if (generateRandom(30))
							{
								if (information)
									printf("%s(%s)受到了毒刺的影响\n", nickname, name);
								setState(Poisoning, rival, team, information);
							}
						}
						break;
					case CuteCharm:
						if (skill->touch && !charmed && gender != rival->gender && gender != Neutral && rival->gender != Neutral)
						{
							if (generateRandom(30))
							{
								if (information)
									printf("%s(%s)受到了魅惑身躯的影响\n", nickname, name);
								setCharmed(information);
							}
						}
						break;
					case Static:
						if (skill->touch)
						{
							bool beStatic = generateRandom(30);
							if (beStatic)
								setState(Paralysis, rival, team, information);
						}
						break;
					case RoughSkin:
						if (skill->touch)
						{
							reduceLife(min(life, (HitPoints[0] >> 3)), team, information);
							if (information)
								printf("%s(%s)受到了鲨鱼皮的反伤\n", nickname, name);
						}
						break;
					default:;
					}

					if (rival->life <= 0)
					{
						++i;
						break;
					}
				}
				else if (!hit)
				{
					//未命中，飞膝踢等技能有反伤
					if (information && totalHitTimes == 1)
						printf("技能%s没有命中\n", skill->name);
					switch (skill->skillId)
					{
					case 26:
						if (ability != RockHead)
						{
							if (information)
								printf("%s(%s)踢到了地上\n", nickname, name);
							reduceLife((HitPoints[0] >> 1), team, information);
						}
						break;
					case 28:
						rival->levelChange(6, -1, rivalTeam, information);
						break;
					default:;
					}
					break;
				}
			}
		}
		if (information && totalHitTimes > 1 && !stopConfused)
		{
			if (i > 0)
			{
				printf("击中了%d次\n", i);
			}
			else
			{
				printf("技能%s没有命中\n", skill->name);
			}
		}

		float t = 1.0;//天恩系数
		if (ability == SereneGrace)
			t = 1.3;
		if (hit)
		{
			if (rival->ability != ShieldDust)
			{
				//技能追加对对方影响
				switch (skill->skillId)
				{
				case 7:
					if (generateRandom(int(10 * t)))
						rival->setState(Burn, this, rivalTeam, information);
					break;
				case 8:
					if (generateRandom(int(10 * t)))
						rival->setState(Frozen, this, rivalTeam, information);
					break;
				case 9:
					if (generateRandom(int(10 * t)))
						rival->setState(Paralysis, this, rivalTeam, information);
					break;
				case 18:
					if (rival->doubleRound < 2)
					{
						int tt = rivalTeam->chooseNextPokemon(rivalTeam->alivePokemons, true);
						if (tt != -1)
							rivalTeam->pokemonSwitch(tt, this, game, information, true);
					}
					break;
				case 20:
				case 35:
					if (rivalTeam->bind == 0)
						++rivalTeam->bind;
					break;
				case 23:
				case 27:
				case 29:
				case 44:
					if (generateRandom(int(30 * t)))
						rival->afraid = true;
					break;
				case 28:
					if (information)
						printf("%s(%s)的命中下降了\n", rival->nickname, rival->name);
					rival->levelChange(6, -1, rivalTeam, information);
					break;
				case 34:
					if (generateRandom(int(30 * t)))
						rival->setState(Paralysis, this, rivalTeam, information);
					break;
				case 39:
				case 43:
					if (information)
						printf("%s(%s)的防御下降了\n", rival->nickname, rival->name);
					rival->levelChange(2, -1, rivalTeam, information);
					break;
				case 40:
					if (generateRandom(int(30 * t)))
						rival->setState(Poisoning, this, rivalTeam, information);
					break;
				case 41:
					if (generateRandom(int(36 * t)))
						rival->setState(Poisoning, this, rivalTeam, information);
					break;
				case 50:
					if (rival->lastSkill != 4 && rival->lastSkill != -1 && rival->disableSkill != -1)
					{
						rival->disableSkill = rival->lastSkill;
						if (generateRandom(50))
							rival->disableSkillCnt = 5;
						else
							rival->disableSkillCnt = 4;
						if (information)
							printf("%s(%s)的技能%s被封印了\n", rival->nickname, rival->name, rival->skills[rival->lastSkill]->name);
					}
					else
					{
						if (information)
							printf("封印失败了\n");
					}
					break;
				case 51:
					if (generateRandom(10 * t))
					{
						if (information)
							printf("%s(%s)的特防下降了\n", rival->nickname, rival->name);
						rival->levelChange(4, -1, rivalTeam, information);
					}
					break;
				case 52:
				case 53:
					if (generateRandom(10 * t))
					{
						if (information)
							printf("%s(%s)烧伤了\n", rival->nickname, rival->name);
						rival->setState(Burn, rival, rivalTeam, information);
					}
					break;
				case 58:
				case 59:
					if (generateRandom(10 * t))
					{
						if (information)
							printf("%s(%s)被冰冻了\n", rival->nickname, rival->name);
						rival->setState(Frozen, rival, rivalTeam, information);
					}
					break;
				default:;
				}
			}

			if (true)
			{
				//技能追加对己方影响
				switch (skill->skillId)
				{
				case 14:
					if (information)
						printf("%s(%s)的攻击迅速提高\n", nickname, name);
					levelChange(1, 2, team, information);
					break;
				case 36:
					if (ability != RockHead)
					{
						if (information)
							printf("%s(%s)受到了反弹伤害\n", nickname, name);
						reduceLife((hurt >> 2), team, information);
					}
					break;
				case 37:
					++mad;
					switch (mad)
					{
					case 3:
						if (information)
							printf("%s(%s)平静下来了\n", nickname, name);
						mad = 0;
						setConfused(information);
						break;
					case 2:
						if (generateRandom(50))
						{
							if (information)
								printf("%s(%s)平静下来了\n", nickname, name);
							mad = 0;
							setConfused(information);
						}
						break;
					default:;
					}
					break;
				case 38:
					if (ability != RockHead)
					{
						if (information)
							printf("%s(%s)受到了反弹伤害\n", nickname, name);
						reduceLife((hurt / 3), team, information);
					}
					break;
				case 54:
					if (team->mist == 0)
					{
						team->mist = 5;
						if (information)
							printf("%s周围扬起了白雾\n", team->name);
					}
					else
					{
						if (information)
							printf("白雾使用失败\n");
					}
					break;
				default:;
				}
			}
		}
	}
}

State Pokemon::calculateEffectSpore()
{
	int t = rand() % 100;
	if (t < 9) return Poisoning;
	else if (t < 19) return Paralysis;
	else if (t < 30) return Sleeping;
	else return NoState;
}

void Pokemon::reduceLife(int amount, Team* team, bool information)
{
	life -= min(amount, life);
	switch (item)
	{
	case Cherry11:
		if (life > 0 && life < HitPoints[0] >> 1)
		{
			addLife(HitPoints[0] >> 3, false);
			if (information)
				printf("%s(%s)使用了%s，恢复了%d点体力\n", nickname, name, Data::ItemName[(int)item], HitPoints[0] >> 3);
			releaseItem(information);
			if (nature == Bold || nature == Calm || nature == Modest || nature == Timid)
				setConfused(information);
		}
		break;
	case Cherry12:
		if (life > 0 && life < (HitPoints[0] >> 1))
		{
			addLife(HitPoints[0] >> 3, false);
			if (information)
				printf("%s(%s)使用了%s，恢复了%d点体力\n", nickname, name, Data::ItemName[(int)item], HitPoints[0] >> 3);
			releaseItem(information);
			if (nature == Adamant || nature == Careful || nature == Impish || nature == Jolly)
				setConfused(information);
		}
		break;
	case Cherry13:
		if (life > 0 && life < (HitPoints[0] >> 1))
		{
			addLife(HitPoints[0] >> 3, false);
			if (information)
				printf("%s(%s)使用了%s，恢复了%d点体力\n", nickname, name, Data::ItemName[(int)item], HitPoints[0] >> 3);
			releaseItem(information);
			if (nature == Brave || nature == Quiet || nature == Relaxed || nature == Sassy)
				setConfused(information);
		}
		break;
	case AguavBerry:
		if (life > 0 && life < (HitPoints[0] >> 1))
		{
			addLife(HitPoints[0] >> 3, false);
			if (information)
				printf("%s(%s)使用了%s，恢复了%d点体力\n", nickname, name, Data::ItemName[(int)item], HitPoints[0] >> 3);
			releaseItem(information);
			if (nature == Lax || nature == Naive || nature == Naughty || nature == Rash)
				setConfused(information);
		}
		break;
	case ApicotBerry:
		if (life > 0 && life < (HitPoints[0] >> 2))
		{
			levelChange(4, 1, team, information);
			setConfused(information);
			if (information)
				printf("%s(%s)使用了%s，特防上升了一级\n", nickname, name, Data::ItemName[(int)item]);
			releaseItem(information);
		}
		break;
	case BerryJuice:
		if (life > 0 && life < (HitPoints[0] >> 1))
		{
			if (information)
				printf("%s(%s)使用了%s，恢复了%d点体力\n", nickname, name, Data::ItemName[(int)item], min(20, HitPoints[0] - life));
			addLife(20, false);
			releaseItem(information);
		}
		break;
	default:;
	}
	
}

void Pokemon::levelChange(int pos, int amount, Team* team, bool information)
{
	if (ability == ClearBody && amount < 0)
	{
		if (information)
			printf("%s(%s)的净体特性阻止了能力下降\n", nickname, name);
		return;
	}
	if (team->mist > 0 && pos < 0)
	{
		if (information)
			printf("%s的白雾阻止了能力下降\n", team->name);
		return;
	}
	if (ability == KeenEye && amount < 0 && pos == 6)
	{
		if (information)
			printf("%s(%s)的锐利目光特性阻止了命中率下降\n", nickname, name);
		return;
	}
	if (ability == HyperCutter && amount < 0 && pos == 1)
	{
		if (information)
			printf("%s(%s)的怪力钳特性阻止了攻击下降\n", nickname, name);
		return;
	}
	if (pos < 0 || pos >= Changes)
		return;
	LevelChanges[pos] += amount;
	LevelChanges[pos] = LevelChanges[pos] > 6 ? 6 : (LevelChanges[pos] < -6 ? -6 : LevelChanges[pos]);
}

void Pokemon::setState(State _state, Pokemon* rival, Team* team, bool information)
{
	if (state != NoState)
		return;
	state = _state;
	switch (_state)
	{
	case Burn:
		if (type[0] != Fire && type[1] != Fire && ability != WaterVeil)
		{
			if (information)
				printf("%s(%s)烧伤了\n", nickname, name);
		}
		else
		{
			state = NoState;
		}
		break;
	case Paralysis:
		if (ability != Limber && type[0] != Electric && type[1] != Electric)
		{
			if (information)
				printf("%s(%s)麻痹了\n", nickname, name);
		}
		else
		{
			state = NoState;
		}
		break;
	case Poisoning:
		if (type[0] != Poison && type[1] != Poison && type[0] != Steel && type[1] != Steel && ability != Immunity)
		{
			if (information)
				printf("%s(%s)中毒了\n", nickname, name);
		}
		else
		{
			state = NoState;
		}
		break;
	case HeavyPoisoning:
		if (type[0] != Poison && type[1] != Poison && type[0] != Steel && type[1] != Steel && ability != Immunity)
		{
			if (information)
				printf("%s(%s)中毒了\n", nickname, name);
			heavyPoisoningCnt = 0;
		}
		else
		{
			state = NoState;
		}
		break;
	case Sleeping:
		if (ability != Insomnia)
		{
			if (information)
				printf("%s(%s)睡着了\n", nickname, name);
		}
		else
		{
			state = NoState;
		}
		break;
	case Frozen:
		if (type[0] != Ice && type[1] != Ice && ability != MagmaArmor)
		{
			if (information)
				printf("%s(%s)被冰冻了\n", nickname, name);
		}
		else
		{
			state = NoState;
		}
		break;
	default:;
	}
	if (state != NoState && ability == Synchronize)
		rival->setState(_state, this, team, information);
	switch (item)
	{
	case AspearBerry:
		if (state == Frozen)
		{
			if (information)
				printf("%s(%s)吃掉了%s，冰冻解除了\n", nickname, name, Data::ItemName[(int)item]);
			releaseItem(information);
			state = NoState;
		}
		break;
	case ChestoBerry:
		if (state == Sleeping)
		{
			if (information)
				printf("%s(%s)吃掉了%s，睡眠解除了\n", nickname, name, Data::ItemName[(int)item]);
			releaseItem(information);
			state = NoState;
		}
		break;
	case CheriBerry:
		if (state == Paralysis)
		{
			if (information)
				printf("%s(%s)吃掉了%s，麻痹解除了\n", nickname, name, Data::ItemName[(int)item]);
			releaseItem(information);
			state = NoState;
		}
		break;
	}
}

void Pokemon::addLife(int amount, bool information)
{
	if (information)
		printf("%s(%s)恢复了%d点体力\n", nickname, name, min(amount, HitPoints[0] - life));
	life += min(amount, HitPoints[0] - life);
}

int Pokemon::calculateHurt(Type attackType, Type defendType1, Type defendType2, int &hurt)
{
	int t1 = modulus[attackType][defendType1];
	int t2 = modulus[attackType][defendType2];
	if (!t1 || !t2)
	{
		hurt = 0;
		return 0;
	}
	switch (t1 + t2)
	{
	case 8://4+4
		hurt = hurt << 2;
		return 4;
		break;
	case 6://4+2
		hurt = hurt << 1;
		return 2;
		break;
	case 3://1+2
		hurt = hurt >> 1;
		return -2;
		break;
	case 2://1+1
		hurt = hurt >> 2;
		return -4;
		break;
	default://2+2,1+4
		return 1;
	}
}

void Pokemon::setConfused(bool information)
{
	if (ability != OwnTempo && !confused)
	{
		if (information)
			printf("%(%s)混乱了\n", nickname, name);
		confused = true;
	}
	else if (confused)
	{
		if (information)
			printf("%(%s)已经混乱了\n", nickname, name);
	}
	else
	{
		if (information)
			printf("%(%s)的特性%s防止了被混乱\n", nickname, name, Data::AbilityName[(int)ability]);
	}
}

void Pokemon::setCharmed(bool information)
{
	if (ability != Oblivious && !charmed)
	{
		if (information)
			printf("%(%s)被魅惑了\n", nickname, name);
		charmed = true;
	}
	else if (charmed)
	{
		if (information)
			printf("%(%s)已经被魅惑了\n", nickname, name);
	}
	else
	{
		if (information)
			printf("%(%s)的特性%s防止了被魅惑\n", nickname, name, Data::AbilityName[(int)ability]);
	}
}