#include "Board.h"

Board::Board() 
{
	initBoard();
}

Board::Board(Board const& other)
{
	initBoard(other);
}

Board::~Board()
{
	for (int i = 0; i < 3; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

bool Board::addMark(bool xPlayer, int x, int y)
{
	if (board[x][y] != Case::EMPTY) 
	{
		return false;
	}

	board[x][y] = xPlayer ? Case::X : Case::O;
	return true;
}

Case** Board::getBoard()
{
	return board;
}

void Board::printBoard()
{
	std::cout << "  -------------" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "  |";
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
			switch (board[i][j])
			{
				case Case::X:
					std::cout << "X";
					break;

				case Case::O:
					std::cout << "O";
					break;

				case Case::EMPTY:
				default:
					std::cout << " ";
					break;
			}
			std::cout << " |";
		}
		std::cout << std::endl;
		std::cout << "  -------------" << std::endl;
	}
	std::cout << std::endl;
}

void Board::initBoard()
{
	board = new Case*[3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new Case[3];
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = Case::EMPTY;
		}
	}
}

void Board::initBoard(Board const& other)
{
	board = new Case*[3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new Case[3];
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = other.board[i][j];
		}
	}
}