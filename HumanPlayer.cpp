#include "HumanPlayer.h"

Move HumanPlayer::doMove()
{
	Move move;
	std::cout << "Enter the X value : ";
	std::cin >> move.x;
	std::cout << "Enter the Y value : ";
	std::cin >> move.y;
	std::cout << std::endl;

	return move;
}