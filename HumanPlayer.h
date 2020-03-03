#pragma once
#include "Player.h";
#include <iostream>

class HumanPlayer: public Player
{

	public:
		Move doMove();
};

