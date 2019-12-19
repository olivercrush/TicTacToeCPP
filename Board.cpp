#include "Board.h"

using namespace std;

Board::Board() 
{
	this->initializeBoard();
}

Board::Board(Board const& other)
{
	this->initializeBoard(other);
}

Board::~Board()
{
	delete(this->board);
}

void Board::addMark(bool xPlayer, int x, int y)
{

}

Case** Board::getBoard()
{

}

void Board::printBoard()
{

}

void Board::initializeBoard()
{

	for (int i = 0; i < sizeof(this->board); i++)
	{
		for (int j = 0; j < sizeof(this->board[i]); j++)
		{
			this->board[i][j] = Case::EMPTY;
		}
	}
}

void Board::initializeBoard(Board const& other)
{
	for (int i = 0; i < sizeof(this->board); i++)
	{
		for (int j = 0; j < sizeof(this->board[i]); j++)
		{
			this->board[i][j] = other.board[i][j];
		}
	}
}