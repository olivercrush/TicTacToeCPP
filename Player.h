#pragma once
struct Move { int x; int y; };

class Player
{
	public:
		virtual Move doMove() = 0;
};
