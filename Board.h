#pragma once
#include <iostream>

enum Case : int {
	X,
	O,
	EMPTY
};

class Board
{
	public :
		Board();
		Board(Board const& other);
		~Board();
		bool addMark(bool xPlayer, int x, int y);
		void removeMark(int x, int y);
		Case** getBoard();
		void printBoard();

	private :
		void initBoard();
		void initBoard(Board const& other);
		Case** board;

};