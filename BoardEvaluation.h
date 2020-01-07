#pragma once

#include "Board.h"

class BoardEvaluation
{
	public:
		BoardEvaluation();
		int evaluateBoard(Board board, bool xFirstPlayer);
};

