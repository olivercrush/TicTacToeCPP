#include "MoveGenerator.h"

MoveGenerator::MoveGenerator()
{

}

MoveGenerator::~MoveGenerator()
{

}

std::vector<int*> MoveGenerator::generateMoves(Board board)
{
	std::vector<int*> moves;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.getBoard()[i][j] == Case::EMPTY)
			{
				moves.push_back(new int[2]{ i, j });
			}
		}
	}

	return moves;
}