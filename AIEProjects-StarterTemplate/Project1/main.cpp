
#include "Game1.h"



int main(int argc, char **argv)
{
	Game1 *pGame = new Game1(840, 640, false, "NewGame");
	pGame->RunGame();
	pGame->Draw();
	float deltaTime;
	pGame->Update(deltaTime);
	delete pGame;

	Matrix3 matrix1;
	Matrix3 matrix2;

	matrix1 + matrix2;
	matrix1.operator+(matrix2);
};