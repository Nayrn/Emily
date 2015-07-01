#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "Matrix3.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	
	m_input = GetInput();

	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	m_spritebatch->SetColumnMajor(true);

	m_texture = new Texture("./Images/box0_256.png");

	m_font = new Font("./Fonts/calibri_24px.fnt");


	position = Vector2(GetWindowWidth() / 2.0f, GetWindowHeight() / 2.0f);
	rotation = 0.0f;
	scale = 1.0f;

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)


{

	if (m_input->IsKeyDown(GLFW_KEY_A))
	{
		position += Vector2(-50.0f, 0.0f) * deltaTime;

	}

	if (m_input->IsKeyDown(GLFW_KEY_D))
	{
		position += Vector2(50.0f, 0.0f) * deltaTime;
	}

	if (m_input->IsKeyDown(GLFW_KEY_W))
	{
		position += Vector2(0.0f, -50.0f) * deltaTime;

	}

	if (m_input->IsKeyDown(GLFW_KEY_S))
	{
		position += Vector2(0.0f, 50.0f) * deltaTime;

	}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.

	m_spritebatch->DrawSprite(m_texture, position.x, position.y, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f);
	//m_spritebatch->DrawSpriteTransformed3x3(m_texture, &(trMatrix.m00));
	m_spritebatch->End();
}