#include "BoardEvaluation.h"

BoardEvaluation::BoardEvaluation()
{

}

int BoardEvaluation::evaluateBoard(Board board, bool xFirstPlayer)
{
	Case** cases = board.getBoard();

	// Check rows
	for (int i = 0; i < 3; i++)
	{
		if (cases[i][0] == cases[i][1] && cases[i][0] == cases[i][2])
		{
			if (cases[i][0] == Case::X)
			{
				return xFirstPlayer ? 10 : -10;
			}
			else if (cases[i][0] == Case::O)
			{
				return !xFirstPlayer ? 10 : -10;
			}
		}
	}

	// Check colums
	for (int i = 0; i < 3; i++)
	{
		if (cases[0][i] == cases[1][i] && cases[0][i] == cases[2][i])
		{
			if (cases[0][i] == Case::X)
			{
				return xFirstPlayer ? 10 : -10;
			}
			else if (cases[0][i] == Case::O)
			{
				return !xFirstPlayer ? 10 : -10;
			}
		}
	}

	// Check diagonals
	if (cases[0][0] == cases[1][1] && cases[0][0] == cases[2][2])
	{
		if (cases[0][0] == Case::X)
		{
			return xFirstPlayer ? 10 : -10;
		}
		else if (cases[0][0] == Case::O)
		{
			return !xFirstPlayer ? 10 : -10;
		}
	}

	if (cases[0][2] == cases[1][1] && cases[0][0] == cases[2][0])
	{
		if (cases[0][2] == Case::X)
		{
			return xFirstPlayer ? 10 : -10;
		}
		else if (cases[0][2] == Case::O)
		{
			return !xFirstPlayer ? 10 : -10;
		}
	}

	return 0;
}