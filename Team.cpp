#include "Team.h"
#include "stdio.h"
#include "string.h"
#include "Type.h"

Team::Team(char *n)
{
	strcpy(name, n);
	name[TeamNameLength] = '\0';
	totalPokemons = 0;
	alivePokemons = 0;
	for (int i = 0; i < 6; ++i)
	{
		pokemons[i] = NULL;
	}

	stealthRock = false;
	spikes = 0;
	toxicSpikes = 0;
	stickyWeb = false;
	bind = 0;
}

Team* Team::copy()
{
	Team *tmp = new Team(name);
	tmp->totalPokemons = totalPokemons;
	tmp->alivePokemons = alivePokemons;
	tmp->stealthRock = stealthRock;
	tmp->spikes = spikes;
	tmp->toxicSpikes = toxicSpikes;
	tmp->stickyWeb = stickyWeb;
	tmp->bind = bind;
	for (int i = 0; i < 6; ++i)
	{
		if (pokemons[i])
			tmp->pokemons[i] = pokemons[i]->copy();
		else
			tmp->pokemons[i] = NULL;
	}
	return tmp;
}

Team::~Team()
{
	for (int i = 0; i < 6; ++i)
	{
		if (!pokemons[i])
		{
			delete pokemons[i];
			pokemons[i] = NULL;
		}
	}
}

void Team::showHitPoints(int pos)
{
	if (pos < 0 || pos >= totalPokemons)
		return;
	pokemons[pos]->showHitPoints();
}

void Team::showAll()
{
	printf("team:%s\n", name);
	for (int i = 0; i < totalPokemons; ++i)
	{
		pokemons[i]->showHitPoints();
		pokemons[i]->showAll();
	}
}

void Team::set(int _id, int _level, bool information, char* _nickname, Gender _gender, Nature _nature, Item _item, int _happiness)
{
	if (totalPokemons >= 6)
	{
		if (information)
			printf("队伍中精灵已达6只，不能添加精灵\n");
		return;
	}
	pokemons[totalPokemons] = new Pokemon(_id, _level, _nickname, _gender, _nature, _item, _happiness);
	++totalPokemons;
	++alivePokemons;
}

void Team::reset(int pos, bool information)
{
	if (totalPokemons <= 0 || pos >= totalPokemons)
	{
		if (information)
			printf("队伍中已没有精灵，不能重置精灵\n");
		return;
	}
	delete pokemons[pos];
	for (int i = pos; i < totalPokemons - 1; ++i)
	{
		pokemons[i] = pokemons[i + 1];
	}
	pokemons[totalPokemons - 1] = NULL;
	--totalPokemons;
	--alivePokemons;
}

void Team::move(int s, Team* rival, Game* game, bool information)
{
	if (alivePokemons <= 0 || rival->alivePokemons <= 0)
	{
		return;
	}
	switch (s)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		pokemons[0]->attack(game, rival, s, information);
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		//mega
		pokemons[0]->attack(game, rival, s - 4, information);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		pokemonSwitch(s - 7, information);
		break;
	case 13:
		//拼命
		pokemons[0]->attack(game, rival, 4, information);
		break;
	default:;
	}
}

void Team::pokemonSwitch(int pos, bool information)
{
	if (information)
	{
		if (pokemons[0]->life > 0)
			printf("%s(%s)被换下场了\n", pokemons[0]->nickname, pokemons[0]->name);
		printf("%s(%s)上场了\n", pokemons[pos]->nickname, pokemons[pos]->name);
	}

	pokemons[0]->substitute = false;
	pokemons[0]->confused = false;
	pokemons[0]->charmed = false;
	pokemons[0]->seed = false;
	pokemons[0]->curse = false;
	pokemons[0]->choice = -1;
	for (int i = 0; i < Changes; ++i)
	{
		pokemons[0]->LevelChanges[i] = 0;
	}

	Pokemon *p = pokemons[pos];
	pokemons[pos] = pokemons[0];
	pokemons[0] = p;

	bind = 0;

	if (stealthRock && p->life > 0)
	{
		int hurt = 0;
		switch (modulus[Rock][p->type[0]] + modulus[Rock][p->type[1]])
		{
		case 8: hurt = (p->HitPoints[0] >> 1); break;
		case 6: hurt = (p->HitPoints[0] >> 2); break;
		default: hurt = (p->HitPoints[0] >> 3); break;
		}
		if (information)
			printf("Stealth Rock扎伤了%s(%s)\n",p->nickname,p->name);
		p->reduceLife(hurt, information);
	}
	if (spikes > 0 && p->life > 0 && p->type[0] != Flying && p->type[1] != Flying)
	{
		int hurt = 0;
		switch (spikes)
		{
		case 1: hurt = (p->HitPoints[0] >> 3); break;
		case 2: hurt = p->HitPoints[0] / 6; break;
		default: hurt = (p->HitPoints[0] >> 2); break;
		}
		if (information)
			printf("Spikes扎伤了%s(%s)\n", p->nickname, p->name);
		p->reduceLife(hurt, information);
	}
	if (toxicSpikes > 0 && p->life > 0
		&& p->type[0] != Steel && p->type[1] != Steel
		&& p->type[0] != Flying && p->type[1] != Flying
		&& p->type[0] != Poison && p->type[1] != Poison)
	{
		switch (toxicSpikes)
		{
		case 1: p->setState(Poisoning, information); break;
		default: p->setState(HeavyPoisoning, information); break;
		}
	}
	if (stickyWeb && p->life > 0 && p->type[0] != Flying && p->type[1] != Flying)
	{
		p->levelChange(5, -1);
	}
}

int Team::chooseNextPokemon(int alive, bool randomGenerate)
{
	if (alive <= 1)
		return -1;
	if (randomGenerate)
	{
		return rand() % (alive - 1) + 1;
	}
	else
	{
		int pos = 0;
		do
		{
			scanf("%d", &pos);
		} while (pos > 0 && pos < alive);
		return pos;
	}
}

void Team::setEvs(int pos, int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed)
{
	if (pos < 0 || pos >= totalPokemons)
		return;
	pokemons[pos]->setEVs(Life, Attack, Defense, SpecialAttack, SpecialDefense, Speed);
}

void Team::setIvs(int pos, int Life, int Attack, int Defense, int SpecialAttack, int SpecialDefense, int Speed)
{
	if (pos < 0 || pos >= totalPokemons)
		return;
	pokemons[pos]->setIVs(Life, Attack, Defense, SpecialAttack, SpecialDefense, Speed);
}

void Team::setAbility(int pos, Ability _ability)
{
	if (pos < 0 || pos >= totalPokemons)
		return;
	pokemons[pos]->setAbility(_ability);
}

void Team::setSkill(int pos, int skillId)
{
	if (pos < 0 || pos >= totalPokemons)
		return;
	pokemons[pos]->setSkill(skillId);
}