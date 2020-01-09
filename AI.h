#pragma once
#include "MoveGenerator.h"
#include "BoardEvaluation.h"

class AI
{
	public:
		AI();
		~AI();
		Move findBestMove(Board board, bool playerIsX);

	private:
		MoveGenerator* moveGenerator = new MoveGenerator();
		BoardEvaluation* boardEvaluation = new BoardEvaluation();
		int minimax(Board board, int depth, bool isMaximizingPlayer);
};

