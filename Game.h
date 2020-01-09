#pragma once
#include "Board.h"
#include "MoveGenerator.h"
#include "AI.h"
#include <iostream>

class Game
{
	public:
		Game();
		~Game();
		void startGame();

	private:
		Board* board = new Board();
		MoveGenerator* moveGen = new MoveGenerator();
		//AI* ai = new AI();
		bool gameOver = false;
		void initGame();
		bool doMove(bool xPlayer, int x, int y);
		void verifyGameOver();
};