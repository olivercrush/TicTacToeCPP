#pragma once
#include <vector>
#include "Board.h"

class MoveGenerator
{
	public:
		MoveGenerator();
		~MoveGenerator();
		std::vector<int*> generateMoves(Board board);

	private:
};

