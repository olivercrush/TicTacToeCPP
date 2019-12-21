#pragma once
#include "Board.h"
#include <iostream>

class Game
{
	public:
		Game();
		~Game();
		void startGame();

	private:
		Board* board;
		bool gameOver;
		void initGame();
		void doMove(bool xPlayer, int x, int y);
		void verifyGameOver();
};