#include "Team.h"
#include "Game.h"
#include "stdio.h"
#include "Constants.h"
#include "MonteCarloNode.h"
#include "windows.h"
#include "time.h"
#include "Team.h"

int Team::generateLegalMove(int *moves, Team* rivalTeam)
{
	int cnt = 0;
	Pokemon *p = pokemons[0];
	if (!p)
		return 0;
	if (p->choice != -1)
	{
		if (p->skills[p->choice] && p->skills[p->choice]->pp > 0)
		{
			moves[cnt++] = p->choice;
		}	
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (p->skills[i] && p->skills[i]->pp > 0)
			{
				moves[cnt++] = i;
			}	
		}
	}

	if (false)//mega
	{
		if (p->choice != -1)
		{
			if (p->skills[p->choice] && p->skills[p->choice]->pp > 0)
			{
				moves[cnt++] = p->choice + 4;
			}
		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				if (p->skills[i] && p->skills[i]->pp > 0)
				{
					moves[cnt++] = i + 4;
				}
			}
		}
	}
	if (bind == 0)
	{
		for (int i = 1; i < 6; ++i)
		{
			if (pokemons[i] && pokemons[i]->life > 0)
				moves[cnt++] = i + 7;
		}
	}
	if (cnt == 0)
	{
		moves[cnt++] = 13;
	}
	return cnt;
}

int Team::aiMoveRandom(int *moves, int movesCnt)
{
	return moves[rand() % movesCnt];
}

int Team::aiMove(int *moves, int movesCnt)
{
	int move = aiMoveRandom(moves, movesCnt);
	return move;
}

int Game::autoRun()
{
	try
	{
		int moveA[MovesMax];
		int moveB[MovesMax];
		int round = 0;
		while (true)
		{
			++round;
			
			int moveAcnt = teams[0]->generateLegalMove(moveA, teams[1]);
			int moveBcnt = teams[1]->generateLegalMove(moveB, teams[0]);

			int aiMoveA = teams[0]->aiMoveRandom(moveA, moveAcnt);
			int aiMoveB = teams[1]->aiMoveRandom(moveB, moveBcnt);

			bool flag = Round(aiMoveA, aiMoveB, false);
			if (!flag)
				break;
		}
		if (teams[0]->alivePokemons <= 0)
			return 1;
		else
			return 0;
	}
	catch (int e)
	{
		printf("error\n");
		return -1;
	}
}

void Game::aiMoveMonteCarlo(int &move0, int &move1)
{
	clock_t startTime = clock();
	int legalMoves0[MovesMax];
	int legalMovesCnt0 = teams[0]->generateLegalMove(legalMoves0, teams[1]);
	int legalMoves1[MovesMax];
	int legalMovesCnt1 = teams[1]->generateLegalMove(legalMoves1, teams[0]);

	MonteCarloNode** nodes = new MonteCarloNode*[legalMovesCnt0*legalMovesCnt1];
	for (int i = 0; i < legalMovesCnt0; ++i)
	{
		for (int j = 0; j < legalMovesCnt1; ++j)
		{
			nodes[i*legalMovesCnt1 + j] = new MonteCarloNode(legalMoves0[i], legalMoves1[j]);
		}
	}
	while (clock() - startTime < TimeLimit)
	{
		try
		{
			Team *tmpTeam0 = teams[0]->copy();
			Team *tmpTeam1 = teams[1]->copy();
			Game *tmpGame = new Game(tmpTeam0, tmpTeam1);
			tmpGame->weather = weather;
			tmpGame->weatherCnt = weatherCnt;

			int pos = rand() % (legalMovesCnt0*legalMovesCnt1);
			tmpGame->Round(nodes[pos]->selfMove, nodes[pos]->rivalMove, false);
			int result = tmpGame->autoRun();
			if (result != -1)
			{
				if (result == 0)
				{
					nodes[pos]->totalGames++;
					nodes[pos]->winGames++;
				}
				else
					nodes[pos]->totalGames++;
			}

			delete tmpTeam0;
			delete tmpTeam1;
			delete tmpGame;
		}
		catch (...)
		{
			break;
		}
	}
	int resultTotal0[MovesMax];
	int resultWin0[MovesMax];
	int resultTotal1[MovesMax];
	int resultWin1[MovesMax];
	for (int i = 0; i < legalMovesCnt0; ++i)
	{
		resultTotal0[i] = 0;
		resultWin0[i] = 0;
	}
	for (int i = 0; i < legalMovesCnt1; ++i)
	{
		resultTotal1[i] = 0;
		resultWin1[i] = 0;
	}

	for (int i = 0; i < legalMovesCnt0*legalMovesCnt1; ++i)
	{
		int s0 = i / legalMovesCnt1;
		int s1 = i % legalMovesCnt1;
		if (resultTotal0[s0] == 0 || nodes[i]->winGames*resultTotal0[s0] < nodes[i]->totalGames*resultWin0[s0])
		{
			resultTotal0[s0] = nodes[i]->totalGames;
			resultWin0[s0] = nodes[i]->winGames;
		}
		if (resultTotal1[s0] == 0 || (nodes[i]->totalGames - nodes[i]->winGames)*resultTotal1[s0] < nodes[i]->totalGames*resultWin1[s0])
		{
			resultTotal1[s0] = nodes[i]->totalGames;
			resultWin1[s0] = nodes[i]->totalGames - nodes[i]->winGames;
		}
	}
	int sign0 = 0;
	int sign1 = 0;
	for (int i = 1; i < legalMovesCnt0; ++i)
	{
		if (resultTotal0[i] != 0 && resultWin0[i] * resultTotal0[sign0] > resultWin0[sign0] * resultTotal0[i])
			sign0 = i;
	}
	for (int i = 1; i < legalMovesCnt1; ++i)
	{
		if (resultTotal1[i] != 0 && resultWin1[i] * resultTotal1[sign1] > resultWin1[sign1] * resultTotal1[i])
			sign1 = i;
	}
	
	move0 = legalMoves0[sign0];
	move1 = legalMoves1[sign1];
	for (int i = 0; i < legalMovesCnt0*legalMovesCnt1; ++i)
		delete nodes[i];
	delete[]nodes;
}