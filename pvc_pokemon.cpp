// pvc_pokemon.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Type.h"
#include "Gender.h"
#include "Nature.h"
#include "Pokemon.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
#include "Team.h"
#include "Game.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	Team *teamA = new Team("TeamA");
	Team *teamB = new Team("TeamB");
	teamA->set(6, 100, true, "喷火龙", Male, Adamant, ChoiceBand);
	teamA->setEvs(0, 252, 252, 0, 0, 0, 4);
	teamA->setIvs(0, 31, 31, 31, 31, 31, 31);
	teamA->setAbility(0, Blaze);

	teamA->set(5, 100, true, "火恐龙", Male, Adamant, AirBalloon);
	teamA->setEvs(1, 252, 252, 0, 0, 0, 4);
	teamA->setIvs(1, 31, 31, 31, 31, 31, 31);
	teamA->setAbility(1, Blaze);

	teamB->set(9, 100, true, "水箭龟", Female, Quiet, ChoiceSpecs);
	teamB->setEvs(0, 0, 252, 252, 0, 0, 4);
	teamB->setIvs(0, 31, 31, 31, 31, 31, 31);
	teamB->setAbility(0, Torrent);

	teamB->set(3, 100, true, "妙蛙花", Female, Quiet, BlackSludge);
	teamB->setEvs(1, 252, 252, 0, 0, 0, 4);
	teamB->setIvs(1, 31, 31, 31, 31, 31, 31);
	teamB->setAbility(1, Overgrow);

	teamA->setSkill(0, 54);
	teamA->setSkill(0, 19);
	teamA->setSkill(0, 53);
	teamA->setSkill(0, 4);
	teamA->setSkill(1, 38);
	teamA->setSkill(1, 2);
	teamA->setSkill(1, 3);
	teamA->setSkill(1, 4);

	teamB->setSkill(0, 57);
	teamB->setSkill(0, 2);
	teamB->setSkill(0, 3);
	teamB->setSkill(0, 8);
	teamB->setSkill(1, 1);
	teamB->setSkill(1, 22);
	teamB->setSkill(1, 38);
	teamB->setSkill(1, 9);

	Game* game = new Game(teamA,teamB);
	//game->Round(0, 0, true);

	/*teamA->move(0, teamB);
	teamA->move(8, teamB);*/
	//game->autoRun();
	while (true)
	{
		printf("round = %d\n", game->getRound());
		int moveA = 0, moveB = 0;
		game->aiMoveMonteCarlo(moveA, moveB);
		bool flag = game->Round(moveA, moveB, true);
		if (!flag)
			break;
	}

	teamA->showAll();
	teamB->showAll();
	
	delete teamA;
	delete teamB;
	delete game;

	/*char s[20];
	strcpy(s, "123456");
	char ss[20];
	strcpy(ss, s);
	printf("%s\n",ss);*/

	system("pause");
	return 0;
}

