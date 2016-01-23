#include "MonteCarloNode.h"

MonteCarloNode::MonteCarloNode(int s, int r)
{
	selfMove = s;
	rivalMove = r;
	totalGames = 0;
	winGames = 0;
}