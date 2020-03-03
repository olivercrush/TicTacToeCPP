#pragma once
#include <iostream>

enum Cell { X, O, EMPTY };

class Board
{
	public:
		Board();
		~Board();
		Cell** getBoard();
		void printBoard();
		bool fillCell(int x, int y, Cell cell);
		void emptyCell(int x, int y);
		bool isGameOver();

	private:
		Cell** m_board;
		void initBoard();

};

