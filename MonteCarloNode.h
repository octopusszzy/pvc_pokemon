#pragma once

class MonteCarloNode{
public:
	int selfMove;
	int rivalMove;
	int totalGames;
	//ָsӮ�Ĵ���
	int winGames;
	MonteCarloNode(int s, int r);
};