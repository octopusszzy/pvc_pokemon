#include "Game.h"
#include "Team.h"
#include "stdio.h"

Game::Game(Team* team0, Team* team1)
{
	teams[0] = team0;
	teams[1] = team1;
	weather = NoWeather;
	weatherCnt = 0;
}

Game::~Game(){}

bool Game::Round(int move0, int move1, bool information)
{
	int moves[2] = {move0, move1};
	int priority0 = calculatePriority(move0, 0, information);
	int priority1 = calculatePriority(move1, 0, information);
	int first = -1;
	if (priority0 > priority1)
		first = 0;
	else if (priority0 < priority1)
		first = 1;
	else
	{
		Pokemon *p0 = teams[0]->pokemons[0];
		Pokemon *p1 = teams[1]->pokemons[0];
		int speed0 = p0->calculateLevelChange(p0->HitPoints[5], p0->LevelChanges[5]);
		int speed1 = p1->calculateLevelChange(p1->HitPoints[5], p1->LevelChanges[5]);
		if (speed0 > speed1)
			first = 0;
		else if (speed0 < speed1)
			first = 1;
		else
		{
			if (rand() % 100 < 50)
				first = 0;
			else 
				first = 1;
		}
	}

	if (teams[first]->pokemons[0]->life > 0)
		teams[first]->move(moves[first], teams[1 - first], this, information);
	if (teams[1 - first]->pokemons[0]->life > 0)
		teams[1 - first]->move(moves[1 - first], teams[first], this, information);

	switch (weather)
	{
	case Sandstorm:
	{
		Pokemon* p = teams[first]->pokemons[0];
		if (p->life > 0 && p->type[0] != Rock && p->type[1] != Rock
			&& p->type[0] != Ground && p->type[1] != Ground
			&& p->type[0] != Steel && p->type[1] != Steel)
		{
			if (information)
				printf("ɳ����%s(%s)������˺�\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), information);
		}
		p = teams[1 - first]->pokemons[0];
		if (p->life > 0 && p->type[0] != Rock && p->type[1] != Rock
			&& p->type[0] != Ground && p->type[1] != Ground
			&& p->type[0] != Steel && p->type[1] != Steel)
		{
			if (information)
				printf("ɳ����%s(%s)������˺�\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), information);
		}
		break;
	}
	case Hailstone:
	{
		Pokemon* p = teams[first]->pokemons[0];
		if (p->life > 0 && p->type[0] != Ice && p->type[1] != Ice)
		{
			if (information)
				printf("������%s(%s)������˺�\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), information);
		}
		p = teams[1 - first]->pokemons[0];
		if (p->life > 0 && p->type[0] != Ice && p->type[1] != Ice)
		{
			if (information)
				printf("������%s(%s)������˺�\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), information);
		}
		break;
	}
	default:;
	}

	Pokemon* pokemon = teams[first]->pokemons[0];
	//״̬
	if (pokemon->life > 0)
	{
		switch(pokemon->state)
		{
		case Burn:
			if (information)
				printf("%s(%s)��Ϊ������ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), information);
			break;
		case Poisoning:
			if (information)
				printf("%s(%s)��Ϊ�ж���ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), information);
			break;
		case HeavyPoisoning:
			if (information)
				printf("%s(%s)��Ϊ�о綾��ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife(pokemon->calculateHeavyPoisoning(), information);
			++pokemon->heavyPoisoningCnt;
			break;
		default:;
		}
	}

	pokemon = teams[1-first]->pokemons[0];

	if (pokemon->life > 0)
	{
		switch (pokemon->state)
		{
		case Burn:
			if (information)
				printf("%s(%s)��Ϊ������ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), information);
			break;
		case Poisoning:
			if (information)
				printf("%s(%s)��Ϊ�ж���ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), information);
			break;
		case HeavyPoisoning:
			if (information)
				printf("%s(%s)��Ϊ�о綾��ʧ������\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife(pokemon->calculateHeavyPoisoning(), information);
			++pokemon->heavyPoisoningCnt;
			break;
		default:;
		}
	}
	//��������
	if (teams[first]->pokemons[0]->life > 0 && teams[1 - first]->pokemons[0]->life)
	{
		if (teams[first]->pokemons[0]->seed)
		{
			if (information)
				printf("%s(%s)������������ȡ������\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
			teams[first]->pokemons[0]->reduceLife((teams[first]->pokemons[0]->HitPoints[0] >> 3), information);
			if (teams[1 - first]->pokemons[0]->life < teams[1 - first]->pokemons[0]->HitPoints[0])
			{
				teams[1 - first]->pokemons[0]->addLife((teams[first]->pokemons[0]->HitPoints[0] >> 3), information);
				if (information)
					printf("�������ӻظ���%s(%s)������\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
			}
		}
		if (teams[1 - first]->pokemons[0]->seed)
		{
			if (information)
				printf("%s(%s)������������ȡ������\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
			teams[1 - first]->pokemons[0]->reduceLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 3), information);
			if (teams[first]->pokemons[0]->life < teams[first]->pokemons[0]->HitPoints[0])
			{
				teams[first]->pokemons[0]->addLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 3), information);
				if (information)
					printf("�������ӻظ���%s(%s)������\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
			}
		}
	}
	//����
	if (teams[first]->pokemons[0]->life > 0 && teams[first]->pokemons[0]->curse)
	{
		if (information)
			printf("%s(%s)��Ϊ�����ܵ����˺�\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
		teams[first]->pokemons[0]->reduceLife((teams[first]->pokemons[0]->HitPoints[0] >> 2), information);
	}
	if (teams[1 - first]->pokemons[0]->life > 0 && teams[1 - first]->pokemons[0]->curse)
	{
		if (information)
			printf("%s(%s)��Ϊ�����ܵ����˺�\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
		teams[1 - first]->pokemons[0]->reduceLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 2), information);
	}
	//��������
	if (teams[first]->pokemons[0]->life > 0)
	{
		if (teams[first]->bind > 0)
		{
			int bindTime = 5;
			int hurt = teams[first]->pokemons[0]->HitPoints[0] >> 4;
			switch (teams[first]->pokemons[0]->item)
			{
			case BindingBand: hurt = teams[first]->pokemons[0]->HitPoints[0] >> 3; break;
			default:;
			}
			teams[first]->pokemons[0]->reduceLife(hurt, information);
			++teams[first]->bind;
			if (teams[first]->bind == bindTime)
			{
				if (rand() % 100 < 50)
					teams[first]->bind = 0;
			}
			else if (teams[first]->bind > bindTime)
				teams[first]->bind = 0;
		}
	}

	if (teams[1-first]->pokemons[0]->life > 0)
	{
		if (teams[1 - first]->bind > 0)
		{
			int bindTime = 5;
			int hurt = teams[1 - first]->pokemons[0]->HitPoints[0] >> 4;
			switch (teams[1 - first]->pokemons[0]->item)
			{
			case BindingBand: hurt = teams[1 - first]->pokemons[0]->HitPoints[0] >> 3; break;
			default:;
			}
			teams[1 - first]->pokemons[0]->reduceLife(hurt, information);
			++teams[1 - first]->bind;
			if (teams[1 - first]->bind == bindTime)
			{
				if (rand() % 100 < 50)
					teams[1 - first]->bind = 0;
			}
			else if (teams[1 - first]->bind > bindTime)
				teams[1 - first]->bind = 0;
		}
	}
	pokemon = teams[first]->pokemons[0];
	if (pokemon->life > 0)
	{
		switch (pokemon->item)
		{
		case BlackSludge:
			if (pokemon->type[0] == Poison || pokemon->type[1] == Poison)
			{
				if (pokemon->life < pokemon->HitPoints[0])
				{
					pokemon->addLife((pokemon->HitPoints[0] >> 4), false);
					if (information)
						printf("%s(%s)��Ϊ%s�ָ�������\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
				}
			}
			else
			{
				pokemon->reduceLife((pokemon->HitPoints[0] >> 4), false);
				if (information)
					printf("%s(%s)��Ϊ%s��ʧ������\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
			}
			break;
		default:;
		}
	}
	
	pokemon = teams[1 - first]->pokemons[0];
	if (pokemon->life > 0)
	{
		switch (pokemon->item)
		{
		case BlackSludge:
			if (pokemon->type[0] == Poison || pokemon->type[1] == Poison)
			{
				if (pokemon->life < pokemon->HitPoints[0])
				{
					pokemon->addLife((pokemon->HitPoints[0] >> 4), false);
					if (information)
						printf("%s(%s)��Ϊ%s�ָ�������\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
				}
			}
			else
			{
				pokemon->reduceLife((pokemon->HitPoints[0] >> 4), false);
				if (information)
					printf("%s(%s)��Ϊ%s��ʧ������\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
			}
			break;
		default:;
		}
	}

	if (teams[first]->pokemons[0]->life <= 0)
	{
		Pokemon *p = teams[first]->pokemons[0];
		if (information)
			printf("%s(%s)������\n",p->nickname,p->name);
		--teams[first]->alivePokemons;
		if (teams[first]->alivePokemons <= 0)
		{
			if (information)
				printf("%s��ʤ\n",teams[1 - first]->name);
			return false;
		}
		int t = teams[first]->chooseNextPokemon(teams[first]->alivePokemons + 1, true);
		if (t > 0)
		{
			teams[first]->pokemonSwitch(t, information);
			p = teams[first]->pokemons[t];
			for (int j = t; j < teams[first]->alivePokemons; ++j)
				teams[first]->pokemons[j] = teams[first]->pokemons[j + 1];
			teams[first]->pokemons[teams[first]->alivePokemons] = p;
		}
		else
			return false;
	}

	if (teams[1-first]->pokemons[0]->life <= 0)
	{
		Pokemon *p = teams[1 - first]->pokemons[0];
		if (information)
			printf("%s(%s)������\n",p->nickname,p->name);
		--teams[1 - first]->alivePokemons;
		if (teams[1 - first]->alivePokemons <= 0)
		{
			if (information)
				printf("%s��ʤ\n", teams[first]->name);
			return false;
		}
		int t = teams[1 - first]->chooseNextPokemon(teams[1 - first]->alivePokemons + 1, true);
		if (t > 0)
		{
			teams[1 - first]->pokemonSwitch(t, information);
			p = teams[1 - first]->pokemons[t];
			for (int j = t; j < teams[1 - first]->alivePokemons; ++j)
				teams[1 - first]->pokemons[j] = teams[1 - first]->pokemons[j + 1];
			teams[1 - first]->pokemons[teams[1 - first]->alivePokemons] = p;
		}
		else
			return false;
	}
	return true;
}

int Game::calculatePriority(int move, int team, bool information)
{
	if (team < 0 || team > 1)
		return -7;
	int priority = 0;
	Pokemon *p = teams[team]->pokemons[0];
	switch (move)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		if (!p->skills[move])
			return -1;
		priority = Data::SkillData[p->skills[move]->skillId][7];
		break;
	case 4:
	case 5:
	case 6:
	case 7:
		if (!p->skills[move - 7])
			return -1;
		priority = Data::SkillData[p->skills[move - 7]->skillId][7];
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		if (move - 7 >= teams[team]->alivePokemons)
			return -7;
		priority = 6;
		break;
	default: return -7;
	}
	switch (p->item)
	{
	case CustapBerry:
		if (p->life < (p->HitPoints[0] >> 2) && p->life > 0)
		{
			if (information)
				printf("%s(%s)�Ե���%s���������ȶ�+1\n", p->nickname, p->name, Data::ItemName[(int)p->item]);
			++priority;
		}
		break;
	
	default:;
	}
	return priority;
}