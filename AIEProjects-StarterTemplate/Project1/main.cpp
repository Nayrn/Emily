
#include "Game1.h"



int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(840, 640, false, "NewGame");
	pGame->RunGame();
	pGame->Draw();
	float deltaTime;
	pGame->Update(deltaTime);
	delete pGame;

	return 0;
};