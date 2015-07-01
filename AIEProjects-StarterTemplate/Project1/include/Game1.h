
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "Vector2.h"
#include "Matrix3.h"


class SpriteBatch;
class Font;
class Texture;
class Input;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;

	Texture *m_texture;

	Font *m_font;

	Input *m_input;

	Vector2 position;

	float rotation;

	float scale;

	Matrix3 trMatrix;
private:


};

#endif