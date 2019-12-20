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
	//delete(this->board);
}

void Board::addMark(bool xPlayer, int x, int y)
{

}

Case** Board::getBoard()
{
	return NULL;
}

void Board::printBoard()
{
	for (int i = 0; i < sizeof(this->board); i++)
	{
		for (int j = 0; j < sizeof(this->board[i]); j++)
		{
			cout << " ";
			switch (this->board[i][j])
			{
				case Case::X:
					cout << "X";
					break;

				case Case::O:
					cout << "O";
					break;

				case Case::EMPTY:
				default:
					cout << "E";
					break;
			}
			cout << " |";
		}
		cout << endl;
		cout << "------------" << endl;
	}
}

void Board::initializeBoard()
{
	this->board = new Case*[3];
	for (int i = 0; i < sizeof(this->board); i++)
	{
		this->board[i] = new Case[3];
		for (int j = 0; j < sizeof(this->board[i]); j++)
		{
			this->board[i][j] = Case::EMPTY;
		}
	}
}

void Board::initializeBoard(Board const& other)
{
	this->board = new Case*[3];
	for (int i = 0; i < sizeof(this->board); i++)
	{
		this->board[i] = new Case[3];
		for (int j = 0; j < sizeof(this->board[i]); j++)
		{
			this->board[i][j] = other.board[i][j];
		}
	}
}