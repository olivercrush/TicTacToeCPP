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
		void addMark(bool xPlayer, int x, int y);
		Case** getBoard();
		void printBoard();

	private :
		void initializeBoard();
		void initializeBoard(Board const& other);
		Case** board;

};