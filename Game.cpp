#include "Game.h"

using namespace std;

Game::Game()
{
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

		cout << (xFirstPlayer ? "X" : "O") << ", entrez votre coup (x puis y) : ";
		cin >> xTmp;
		cin >> yTmp;
		doMove(xFirstPlayer, xTmp, yTmp);

		if (!gameOver)
		{
			cout << (!xFirstPlayer ? "X" : "O") << ", entrez votre coup (x puis y) : ";
			cin >> xTmp;
			cin >> yTmp;
			doMove(!xFirstPlayer, xTmp, yTmp);
		}
	}

	cout << "Partie terminee !" << endl << endl;
}

void Game::initGame()
{
	gameOver = false;
	board = new Board();
}

void Game::doMove(bool xPlayer, int x, int y)
{
	board->addMark(xPlayer, x, y);
	board->printBoard();
	verifyGameOver();
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