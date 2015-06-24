
#include "Game1.h"


int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(840, 640, false, "NewGame");
	pGame->RunGame();
	delete pGame;

	return 0;
};