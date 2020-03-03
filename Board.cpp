#include "Board.h"

Board::Board() 
{
	initBoard();
}

Board::~Board()
{
	for (int i = 0; i < 3; i++)
	{
		delete[] m_board[i];
	}
	delete[] m_board;
}

Cell** Board::getBoard()
{
	return m_board;
}

void Board::printBoard()
{
	for (int y = 0; y < 3; y++)
	{
		std::cout << "-------------" << std::endl;

		for (int x = 0; x < 3; x++)
		{
			std::cout << "| ";

			switch (m_board[x][y])
			{
				case Cell::O:
					std::cout << "O";
					break;

				case Cell::X:
					std::cout << "X";
					break;

				case Cell::EMPTY:
					std::cout << " ";
					break;
			}

			std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}

	std::cout << "-------------" << std::endl;
}

bool Board::fillCell(int x, int y, Cell cell)
{
	if (m_board[x][y] != Cell::EMPTY)
		return false;

	m_board[x][y] = cell;
	return true;
}

void Board::emptyCell(int x, int y)
{
	m_board[x][y] = Cell::EMPTY;
}

bool Board::isGameOver()
{
	for (int x = 0; x < 3; x++) {
		if (m_board[x][0] == m_board[x][1] && m_board[x][1] == m_board[x][2] && m_board[x][0] != Cell::EMPTY)
			return true;
	}

	for (int y = 0; y < 3; y++) {
		if (m_board[0][y] == m_board[1][y] && m_board[1][y] == m_board[2][y] && m_board[0][y] != Cell::EMPTY)
			return true;
	}

	if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[0][0] != Cell::EMPTY)
		return true;

	if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[0][2] != Cell::EMPTY)
		return true;

	return false;
}

void Board::initBoard()
{
	m_board = new Cell*[3];
	for (int i = 0; i < 3; i++)
	{
		m_board[i] = new Cell[3];
		for (int j = 0; j < 3; j++)
		{
			m_board[i][j] = Cell::EMPTY;
		}
	}
}