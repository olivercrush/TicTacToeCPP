// TicTacToe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
//#include "HumanPlayer.h"
#include "Board.h"

int main()
{
	/*Player* player = new HumanPlayer();
	Move move = player->doMove();

	std::cout << "Your move was (" << move.x << ";" << move.y << ")";
	delete player;*/

	Board* board = new Board();
	board->fillCell(1, 0, Cell::X);
	board->fillCell(1, 1, Cell::X);
	board->fillCell(1, 2, Cell::X);
	board->printBoard();

	if (board->isGameOver())
		std::cout << "Termine" << std::endl;

	delete board;
}