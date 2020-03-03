#pragma once
#include "Player.h";

class AIPlayer: public Player
{
	public:
		Move doMove();

	private:
		Move findBestMove();
		int minimax();
		int evaluateBoard();
};

