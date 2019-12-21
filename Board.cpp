#include "Board.h"

using namespace std;

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

void Board::addMark(bool xPlayer, int x, int y)
{
	board[x][y] = xPlayer ? Case::X : Case::O;
}

Case** Board::getBoard()
{
	return board;
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
			switch (board[i][j])
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
	cout << endl;
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