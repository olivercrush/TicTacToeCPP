#pragma once
#include "MoveGenerator.h"

class AI
{
	public:
		AI();
		~AI();
		Move findBestMove(Board board, bool playerIsX);

	private:
		int minimax(Board board, int depth, bool isMaximizingPlayer);
};

