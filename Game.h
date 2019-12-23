#pragma once
#include "Board.h"
#include "MoveGenerator.h"
#include <iostream>

class Game
{
	public:
		Game();
		~Game();
		void startGame();

	private:
		Board* board = new Board();
		MoveGenerator* moveGen = new MoveGenerator;
		bool gameOver = false;
		void initGame();
		bool doMove(bool xPlayer, int x, int y);
		void verifyGameOver();
};