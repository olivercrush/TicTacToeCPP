#include "AI.h"

AI::AI()
{

}

AI::~AI()
{

}

Move AI::findBestMove(Board board, bool playerIsX)
{
	int bestValue = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	std::vector<Move> moves = moveGenerator->generateMoves(board);
	for (int i = 0; i < moves.size(); i++)
	{
		board.addMark(!playerIsX, moves[i].row, moves[i].col);
		int moveValue = minimax(board, 0, false);
		board.removeMark(moves[i].row, moves[i].col);

		if (moveValue > bestValue)
		{
			bestMove = moves[i];
			bestValue = moveValue;
		}
	}

	return bestMove;
}

int AI::minimax(Board board, int depth, bool isMaximizingPlayer)
{
	int score = boardEvaluation->evaluateBoard(board, true);

	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (moveGenerator->isBoardComplete(board))
		return 0;

	if (isMaximizingPlayer)
	{
		int best = -1000;
		
		std::vector<Move> moves = moveGenerator->generateMoves(board);
		for (int i = 0; i < moves.size(); i++)
		{
			board.addMark(isMaximizingPlayer, moves[i].row, moves[i].col);
			int minimaxValue = minimax(board, depth + 1, !isMaximizingPlayer);

			if (minimaxValue > best)
				best = minimaxValue;

			board.removeMark(moves[i].row, moves[i].col);
		}

		return best;
	}
	else 
	{
		int best = 1000;

		std::vector<Move> moves = moveGenerator->generateMoves(board);
		for (int i = 0; i < moves.size(); i++)
		{
			board.addMark(!isMaximizingPlayer, moves[i].row, moves[i].col);
			int minimaxValue = minimax(board, depth + 1, isMaximizingPlayer);

			if (minimaxValue < best)
				best = minimaxValue;

			board.removeMark(moves[i].row, moves[i].col);
		}

		return best;
	}
}