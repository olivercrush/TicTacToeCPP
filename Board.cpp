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
	this->board[y][x] = xPlayer ? Case::X : Case::O;
}

Case** Board::getBoard()
{
	return this->board;
}

void Board::printBoard()
{
	cout << "  -------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "  |";
		for (int j = 0; j < 3; j++)
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
					cout << " ";
					break;
			}
			cout << " |";
		}
		cout << endl;
		cout << "  -------------" << endl;
	}
}

void Board::initializeBoard()
{
	this->board = new Case*[3];
	for (int i = 0; i < 3; i++)
	{
		this->board[i] = new Case[3];
		for (int j = 0; j < 3; j++)
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