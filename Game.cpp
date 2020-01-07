#include "Game.h"

Game::Game()
{
	initGame();
}

Game::~Game()
{
	delete(board);
}

void Game::startGame()
{
	initGame();
	board->printBoard();

	bool xFirstPlayer = (rand() % 100 >= 50);

	while (!gameOver)
	{
		int xTmp, yTmp;
		bool validMove = false;

		while (!validMove)
		{
			std::cout << (xFirstPlayer ? "X" : "O") << ", entrez votre coup (x puis y) : ";
			std::cin >> xTmp;
			std::cin >> yTmp;
			validMove = doMove(xFirstPlayer, xTmp, yTmp);
		}

		if (!gameOver)
		{
			std::vector<int*> moves = moveGen->generateMoves(*board);
			int *move = moves[rand() % moves.size()];

			validMove = false;
			while (!validMove)
			{
				//cout << (!xFirstPlayer ? "X" : "O") << ", entrez votre coup (x puis y) : ";
				//cin >> xTmp;
				//cin >> yTmp;
				validMove = doMove(!xFirstPlayer, move[0], move[1]);
			}
		}
	}

	std::cout << "Partie terminee !" << std::endl << std::endl;
}

void Game::initGame()
{
	gameOver = false;
	board = new Board();
}

bool Game::doMove(bool xPlayer, int x, int y)
{
	if (!board->addMark(xPlayer, x, y))
	{
		std::cout << "Ce coup est invalide.";
		return false;
	}

	board->printBoard();
	verifyGameOver();
	return true;
}

void Game::verifyGameOver()
{
	if (board->getBoard()[0][0] == board->getBoard()[0][1] && board->getBoard()[0][0] == board->getBoard()[0][2] && board->getBoard()[0][0] != Case::EMPTY ||
		board->getBoard()[1][0] == board->getBoard()[1][1] && board->getBoard()[1][0] == board->getBoard()[1][2] && board->getBoard()[1][0] != Case::EMPTY ||
		board->getBoard()[2][0] == board->getBoard()[2][1] && board->getBoard()[2][0] == board->getBoard()[2][2] && board->getBoard()[2][0] != Case::EMPTY ||

		board->getBoard()[0][0] == board->getBoard()[1][0] && board->getBoard()[0][0] == board->getBoard()[2][0] && board->getBoard()[0][0] != Case::EMPTY ||
		board->getBoard()[0][1] == board->getBoard()[1][1] && board->getBoard()[0][1] == board->getBoard()[2][1] && board->getBoard()[0][1] != Case::EMPTY ||
		board->getBoard()[0][2] == board->getBoard()[1][2] && board->getBoard()[0][2] == board->getBoard()[2][2] && board->getBoard()[0][2] != Case::EMPTY ||

		board->getBoard()[0][0] == board->getBoard()[1][1] && board->getBoard()[0][0] == board->getBoard()[2][2] && board->getBoard()[0][0] != Case::EMPTY ||
		board->getBoard()[0][2] == board->getBoard()[1][1] && board->getBoard()[0][2] == board->getBoard()[2][0] && board->getBoard()[0][2] != Case::EMPTY)
	{
		gameOver = true;
	}
}