// TicTacToe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include "Game.h"

//#include "Board.h"
//#include "BoardEvaluation.h"

int main()
{
	/*Board board = Board();
	board.addMark(true, 0, 0);
	board.addMark(true, 0, 1);
	board.addMark(false, 0, 2);
	board.addMark(false, 1, 2);
	board.addMark(false, 2, 2);

	std::cout << std::endl;
	board.printBoard();

	BoardEvaluation evaluation = BoardEvaluation();
	std::cout << evaluation.evaluateBoard(board, true);*/


	std::cout << "__________________________________________________________________________" << std::endl;
	std::cout << "_____________________________ TIC TAC TOE ________________________________" << std::endl << std::endl;

	Game game = Game();
	game.startGame();


}