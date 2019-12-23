// TicTacToe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Game.h"

int main()
{
	/*Board board = Board();
	board.addMark(true, 0, 0);
	board.addMark(false, 1, 1);

	std::cout << std::endl;
	board.printBoard();*/

	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "_____________________________ TIC TAC TOE ________________________________" << std::endl << std::endl;

	Game game = Game();
	game.startGame();


}