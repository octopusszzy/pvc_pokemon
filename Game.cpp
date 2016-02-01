#include "Game.h"
#include "Team.h"
#include "stdio.h"

Game::Game(Team* team0, Team* team1)
{
	teams[0] = team0;
	teams[1] = team1;
	weather = NoWeather;
	weatherCnt = 0;
	round = 0;
}

Game::~Game(){}

int Game::getRound()
{
	return round + 1;
}

bool Game::Round(int move0, int move1, bool information)
{
	Team *team = NULL;
	++round;
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
		if (p0->state == Paralysis)
			speed0 = (speed0 >> 2);
		int speed1 = p1->calculateLevelChange(p1->HitPoints[5], p1->LevelChanges[5]);
		if (p1->state == Paralysis)
			speed1 = (speed1 >> 2);
		switch (weather)
		{
		case Rainy:
			if (p0->ability == SwiftSwim)
				speed0 = (speed0 << 1);
			if (p1->ability == SwiftSwim)
				speed1 = (speed1 << 1);
			break;
		case Shiny:
			if (p0->ability == Chlorophyll)
				speed0 = (speed0 << 1);
			if (p1->ability == Chlorophyll)
				speed1 = (speed1 << 1);
		}
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

	if (round == 1)
	{
		Pokemon *p = teams[first]->pokemons[0];
		if (p->life > 0)
		{
			switch (p->ability)
			{
			case Intimidate:
				if (information)
					printf("%s(%s)威吓了对手\n", p->nickname, p->name);
				teams[1 - first]->pokemons[0]->levelChange(1, -1, teams[1 - first], information);
				break;
			case Drizzle:
				if (weather != Rainy)
				{
					int rainTime = 5;
					weather = Rainy;
					weatherCnt = rainTime + 1;
					if (information)
						printf("%s(%s)引起了沙暴\n", p->nickname, p->name);
				}
				break;
			case Sandstorm:
				if (weather != Sandstorm)
				{
					int lastTime = 5;
					weather = Sandstorm;
					weatherCnt = lastTime;
					if (information)
						printf("%s(%s)引起了沙暴\n", p->nickname, p->name);
				}
				break;
			default:;
			}
		}
		p = teams[1 - first]->pokemons[0];
		if (p->life > 0)
		{
			switch (p->ability)
			{
			case Intimidate:
				if (information)
					printf("%s(%s)威吓了对手\n", p->nickname, p->name);
				teams[first]->pokemons[0]->levelChange(1, -1, teams[first], information);
				break;
			case Drizzle:
				if (weather != Rainy)
				{
					int rainTime = 5;
					weather = Rainy;
					weatherCnt = rainTime + 1;
					if (information)
						printf("%s(%s)引起了沙暴\n", p->nickname, p->name);
				}
				break;
			case Drought:
				if (weather != Shiny)
				{
					int rainTime = 5;
					weather = Shiny;
					weatherCnt = rainTime + 1;
					if (information)
						printf("%s(%s)引起了干旱\n", p->nickname, p->name);
				}
				break;
			case Sandstorm:
				if (weather != Sandstorm)
				{
					int lastTime = 5;
					weather = Sandstorm;
					weatherCnt = lastTime;
					if (information)
						printf("%s(%s)引起了沙暴\n", p->nickname, p->name);
				}
				break;
			default:;
			}
		}
	}

	teams[first]->pokemons[0]->afraid = false;
	teams[first]->pokemons[0]->protectMode = 0;
	teams[1 - first]->pokemons[0]->afraid = false;
	teams[1 - first]->pokemons[0]->protectMode = 0;

	if (teams[first]->pokemons[0]->life > 0)
		teams[first]->move(moves[first], teams[1 - first], this, information);
	if (teams[1 - first]->pokemons[0]->life > 0)
		teams[1 - first]->move(moves[1 - first], teams[first], this, information);

	if (teams[first]->mist > 0)
	{
		--teams[first]->mist;
		if (teams[first]->mist == 0 && information)
			printf("%s的白雾消失了\n", teams[first]->name);
	}
	if (teams[1 - first]->mist > 0)
	{
		--teams[1 - first]->mist;
		if (teams[1 - first]->mist == 0 && information)
			printf("%s的白雾消失了\n", teams[1 - first]->name);
	}

	if (weatherCnt > 0)
	{
		--weatherCnt;
		if (weatherCnt == 0)
		{
			if (information)
				printf("天气消失了\n");
			weather = NoWeather;
		}
	}
	Pokemon* pokemon = teams[first]->pokemons[0];
	if (pokemon->state == Sleeping)
	{
		++pokemon->sleepCnt;
	}
	if (pokemon->disableSkill != -1)
	{
		--pokemon->disableSkillCnt;
		if (pokemon->disableSkillCnt == 0)
		{
			pokemon->disableSkill = -1;
			if (information)
				printf("%s(%s)受到的封印消失了\n", pokemon->nickname, pokemon->name);
		}
	}
	pokemon = teams[1 - first]->pokemons[0];
	if (pokemon->state == Sleeping)
	{
		++pokemon->sleepCnt;
	}
	if (pokemon->disableSkill != -1)
	{
		--pokemon->disableSkillCnt;
		if (pokemon->disableSkillCnt == 0)
		{
			pokemon->disableSkill = -1;
			if (information)
				printf("%s(%s)受到的封印消失了\n", pokemon->nickname, pokemon->name);
		}
	}

	switch (weather)
	{
	case Rainy:
		if (information)
			printf("正在下大雨\n");
		break;
	case Shiny:
		if (information)
			printf("艳阳高照\n");
		break;
	case Sandstorm:
	{
		if (information)
			printf("正在刮沙暴\n");
		Pokemon* p = teams[first]->pokemons[0];
		team = teams[first];
		if (p->life > 0 && p->type[0] != Rock && p->type[1] != Rock
			&& p->type[0] != Ground && p->type[1] != Ground
			&& p->type[0] != Steel && p->type[1] != Steel
			&& p->ability != CloudNine)
		{
			if (information)
				printf("沙暴对%s(%s)造成了伤害\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), team, information);
		}
		p = teams[1 - first]->pokemons[0];
		team = teams[1 - first];
		if (p->life > 0 && p->type[0] != Rock && p->type[1] != Rock
			&& p->type[0] != Ground && p->type[1] != Ground
			&& p->type[0] != Steel && p->type[1] != Steel 
			&& p->ability != CloudNine)
		{
			if (information)
				printf("沙暴对%s(%s)造成了伤害\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), team, information);
		}
		break;
	}
	case Hailstone:
	{
		if (information)
			printf("正在刮冰雹\n");
		Pokemon* p = teams[first]->pokemons[0];
		team = teams[first];
		if (p->life > 0 && p->type[0] != Ice && p->type[1] != Ice
			&& p->ability != CloudNine)
		{
			if (information)
				printf("冰雹对%s(%s)造成了伤害\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), team, information);
		}
		p = teams[1 - first]->pokemons[0];
		team = teams[1 - first];
		if (p->life > 0 && p->type[0] != Ice && p->type[1] != Ice
			&& p->ability != CloudNine)
		{
			if (information)
				printf("冰雹对%s(%s)造成了伤害\n", p->nickname, p->name);
			p->reduceLife((p->HitPoints[0] >> 4), team, information);
		}
		break;
	}
	default:;
	}

	pokemon = teams[first]->pokemons[0];
	team = teams[first];
	//状态
	if (pokemon->life > 0)
	{
		if (pokemon->ability == ShedSkin && pokemon->state != NoState)
		{
			if (pokemon->generateRandom(30))
			{
				if (information)
					printf("%s(%s)因为蜕皮治愈了自己的异常状态\n", pokemon->nickname, pokemon->name);
				pokemon->state = NoState;
			}
		}
		switch(pokemon->state)
		{
		case Burn:
			if (information)
				printf("%s(%s)因为烧伤损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), team, information);
			break;
		case Poisoning:
			if (information)
				printf("%s(%s)因为中毒损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), team, information);
			break;
		case HeavyPoisoning:
			if (information)
				printf("%s(%s)因为中剧毒损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife(pokemon->calculateHeavyPoisoning(), team, information);
			++pokemon->heavyPoisoningCnt;
			break;
		default:;
		}
	}

	pokemon = teams[1-first]->pokemons[0];
	team = teams[1 - first];
	if (pokemon->life > 0)
	{
		if (pokemon->ability == ShedSkin && pokemon->state != NoState)
		{
			if (pokemon->generateRandom(30))
			{
				if (information)
					printf("%s(%s)因为蜕皮治愈了自己的异常状态\n", pokemon->nickname, pokemon->name);
				pokemon->state = NoState;
			}
		}
		switch (pokemon->state)
		{
		case Burn:
			if (information)
				printf("%s(%s)因为烧伤损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), team, information);
			break;
		case Poisoning:
			if (information)
				printf("%s(%s)因为中毒损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife((pokemon->HitPoints[0] >> 3), team, information);
			break;
		case HeavyPoisoning:
			if (information)
				printf("%s(%s)因为中剧毒损失了体力\n", pokemon->nickname, pokemon->name);
			pokemon->reduceLife(pokemon->calculateHeavyPoisoning(), team, information);
			++pokemon->heavyPoisoningCnt;
			break;
		default:;
		}
	}
	//寄生种子
	if (teams[first]->pokemons[0]->life > 0 && teams[1 - first]->pokemons[0]->life > 0)
	{
		if (teams[first]->pokemons[0]->seed)
		{
			if (information)
				printf("%s(%s)被寄生种子吸取了体力\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
			teams[first]->pokemons[0]->reduceLife((teams[first]->pokemons[0]->HitPoints[0] >> 3), teams[first], information);
			if (teams[first]->pokemons[0]->ability != LiquidOoze)
			{
				if (teams[1 - first]->pokemons[0]->life < teams[1 - first]->pokemons[0]->HitPoints[0])
				{
					teams[1 - first]->pokemons[0]->addLife((teams[first]->pokemons[0]->HitPoints[0] >> 3), information);
					if (information)
						printf("寄生种子回复了%s(%s)的体力\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
				}
			}
			else
			{
				if (information)
					printf("%s(%s)吸收了毒液\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
				teams[1 - first]->pokemons[0]->reduceLife((teams[first]->pokemons[0]->HitPoints[0] >> 3), teams[1 - first], information);
			}
		}
	}
	if (teams[first]->pokemons[0]->life > 0 && teams[1 - first]->pokemons[0]->life > 0)
	{
		if (teams[1 - first]->pokemons[0]->seed)
		{
			if (information)
				printf("%s(%s)被寄生种子吸取了体力\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
			teams[1 - first]->pokemons[0]->reduceLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 3), teams[1 - first], information);
			if (teams[1 - first]->pokemons[0]->ability != LiquidOoze)
			{
				if (teams[first]->pokemons[0]->life < teams[first]->pokemons[0]->HitPoints[0])
				{
					teams[first]->pokemons[0]->addLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 3), information);
					if (information)
						printf("寄生种子回复了%s(%s)的体力\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
				}
			}
			else
			{
				if (information)
					printf("%s(%s)吸收了毒液\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
				teams[first]->pokemons[0]->reduceLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 3), teams[first], information);
			}
		}
	}
	//诅咒
	if (teams[first]->pokemons[0]->life > 0 && teams[first]->pokemons[0]->curse)
	{
		if (information)
			printf("%s(%s)因为诅咒受到了伤害\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
		teams[first]->pokemons[0]->reduceLife((teams[first]->pokemons[0]->HitPoints[0] >> 2), teams[first], information);
	}
	if (teams[1 - first]->pokemons[0]->life > 0 && teams[1 - first]->pokemons[0]->curse)
	{
		if (information)
			printf("%s(%s)因为诅咒受到了伤害\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
		teams[1 - first]->pokemons[0]->reduceLife((teams[1 - first]->pokemons[0]->HitPoints[0] >> 2), teams[1 - first], information);
	}
	//束缚技能
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
			if (information)
				printf("%s(%s)被束缚住了受到伤害\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
			teams[first]->pokemons[0]->reduceLife(hurt, teams[first], information);
			++teams[first]->bind;
			if (teams[first]->bind == bindTime)
			{
				if (rand() % 100 < 50)
					teams[first]->bind = 0;
			}
			else if (teams[first]->bind > bindTime)
				teams[first]->bind = 0;
			if (teams[first]->bind == 0 && information)
				printf("%s(%s)挣脱了束缚\n", teams[first]->pokemons[0]->nickname, teams[first]->pokemons[0]->name);
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
			if (information)
				printf("%s(%s)被束缚住了受到伤害\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
			teams[1 - first]->pokemons[0]->reduceLife(hurt, teams[1 - first], information);
			++teams[1 - first]->bind;
			if (teams[1 - first]->bind == bindTime)
			{
				if (rand() % 100 < 50)
					teams[1 - first]->bind = 0;
			}
			else if (teams[1 - first]->bind > bindTime)
				teams[1 - first]->bind = 0;
			if (teams[1 - first]->bind == 0 && information)
				printf("%s(%s)挣脱了束缚\n", teams[1 - first]->pokemons[0]->nickname, teams[1 - first]->pokemons[0]->name);
		}
	}
	pokemon = teams[first]->pokemons[0];
	team = teams[first];
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
						printf("%s(%s)因为%s恢复了体力\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
				}
			}
			else
			{
				pokemon->reduceLife((pokemon->HitPoints[0] >> 4), team, false);
				if (information)
					printf("%s(%s)因为%s损失了体力\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
			}
			break;
		default:;
		}
	}
	
	pokemon = teams[1 - first]->pokemons[0];
	team = teams[1 - first];
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
						printf("%s(%s)因为%s恢复了体力\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
				}
			}
			else
			{
				pokemon->reduceLife((pokemon->HitPoints[0] >> 4), team, false);
				if (information)
					printf("%s(%s)因为%s损失了体力\n", pokemon->nickname, pokemon->name, Data::ItemName[(int)pokemon->item]);
			}
			break;
		default:;
		}
	}

	pokemon = teams[first]->pokemons[0];
	team = teams[first];
	if (pokemon->life > 0)
	{
		switch (pokemon->ability)
		{
		case SpeedBoost:
			if (information)
				printf("%s(%s)加速了\n", pokemon->nickname, pokemon->name);
			pokemon->levelChange(5, 1, team, information);
			break;
		case RainDish:
			if (weather == Rainy)
			{
				if (information)
					printf("%s(%s)因为接雨盘回复了体力\n", pokemon->nickname, pokemon->name);
				pokemon->addLife((pokemon->HitPoints[0] >> 4), information);
			}
			break;
		default:;
		}
	}
	pokemon = teams[1 - first]->pokemons[0];
	team = teams[1 - first];
	if (pokemon->life > 0)
	{
		switch (pokemon->ability)
		{
		case SpeedBoost:
			if (information)
				printf("%s(%s)加速了\n", pokemon->nickname, pokemon->name);
			pokemon->levelChange(5, 1, team, information);
			break;
		case RainDish:
			if (weather == Rainy)
			{
				if (information)
					printf("%s(%s)因为接雨盘回复了体力\n", pokemon->nickname, pokemon->name);
				pokemon->addLife((pokemon->HitPoints[0] >> 4), information);
			}
			break;
		default:;
		}
	}

	if (teams[first]->pokemons[0]->life <= 0)
	{
		Pokemon *p = teams[first]->pokemons[0];
		if (information)
			printf("%s(%s)倒下了\n",p->nickname,p->name);
		--teams[first]->alivePokemons;
		if (teams[first]->alivePokemons <= 0)
		{
			if (information)
				printf("%s获胜\n",teams[1 - first]->name);
			return false;
		}
		int t = teams[first]->chooseNextPokemon(teams[first]->alivePokemons + 1, true);
		if (t > 0)
		{
			teams[first]->pokemonSwitch(t, teams[1 - first]->pokemons[0], this, information);
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
			printf("%s(%s)倒下了\n",p->nickname,p->name);
		--teams[1 - first]->alivePokemons;
		if (teams[1 - first]->alivePokemons <= 0)
		{
			if (information)
				printf("%s获胜\n", teams[first]->name);
			return false;
		}
		int t = teams[1 - first]->chooseNextPokemon(teams[1 - first]->alivePokemons + 1, true);
		if (t > 0)
		{
			teams[1 - first]->pokemonSwitch(t, teams[first]->pokemons[0], this, information);
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
		if (!p->skills[move - 4])
			return -1;
		priority = Data::SkillData[p->skills[move - 4]->skillId][7];
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
				printf("%s(%s)吃掉了%s，技能优先度+1\n", p->nickname, p->name, Data::ItemName[(int)p->item]);
			++priority;
		}
		break;
	
	default:;
	}
	return priority;
}