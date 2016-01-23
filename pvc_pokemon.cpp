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
	teamA->setEvs(0, 4, 252, 0, 0, 0, 252);
	teamA->setIvs(0, 31, 31, 31, 31, 31, 31);

	teamA->set(5, 100, true, "火恐龙", Male, Adamant, ChoiceBand);
	teamA->setEvs(1, 4, 252, 0, 0, 0, 252);
	teamA->setIvs(1, 31, 31, 31, 31, 31, 31);

	teamB->set(1, 100, true, "妙蛙种子", Female, Quiet, BlackSludge);
	teamB->setEvs(0, 0, 180, 0, 60, 60, 210);
	teamB->setIvs(0, 0, 31, 0, 31, 31, 31);

	teamB->set(3, 100, true, "妙蛙花", Female, Quiet, BlackSludge);
	teamB->setEvs(252, 0, 252, 0, 0, 0, 4);
	teamB->setIvs(31, 31, 31, 31, 31, 31, 31);

	teamA->setSkill(0, 1);
	teamA->setSkill(0, 2);
	teamA->setSkill(0, 3);
	teamA->setSkill(0, 4);
	teamA->setSkill(1, 1);
	teamA->setSkill(1, 2);
	teamA->setSkill(1, 3);
	teamA->setSkill(1, 4);

	teamB->setSkill(0, 1);
	teamB->setSkill(0, 2);
	teamB->setSkill(0, 3);
	teamB->setSkill(0, 4);
	teamB->setSkill(1, 1);
	teamB->setSkill(1, 2);
	teamB->setSkill(1, 3);
	teamB->setSkill(1, 4);

	Game* game = new Game(teamA,teamB);
	//game->Round(0, 0, true);

	/*teamA->move(0, teamB);
	teamA->move(8, teamB);*/
	//game->autoRun();
	int round = 0;
	while (true)
	{
		++round;
		printf("round = %d\n", round);
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

