#pragma once

class MonteCarloNode{
public:
	int selfMove;
	int rivalMove;
	int totalGames;
	//指s赢的次数
	int winGames;
	MonteCarloNode(int s, int r);
};