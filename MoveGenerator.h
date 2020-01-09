#pragma once
#include <vector>
#include "Board.h"

struct Move
{
	int row, col;
};

class MoveGenerator
{
	public:
		MoveGenerator();
		~MoveGenerator();
		std::vector<Move> generateMoves(Board board);
		bool isBoardComplete(Board board);

	private:
};

