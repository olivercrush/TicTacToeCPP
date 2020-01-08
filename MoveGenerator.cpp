#include "MoveGenerator.h"

MoveGenerator::MoveGenerator()
{

}

MoveGenerator::~MoveGenerator()
{

}

std::vector<Move> MoveGenerator::generateMoves(Board board)
{
	std::vector<Move> moves;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.getBoard()[i][j] == Case::EMPTY)
			{
				Move move = Move();
				move.row = i;
				move.col = j;
				moves.push_back(move);
			}
		}
	}

	return moves;
}