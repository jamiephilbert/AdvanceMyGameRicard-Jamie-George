#include "AsteroidPlay.h"

void AsteroidPlay::CheckScreenBounds()
{
	if (Position().x < -11) {
		Position(Graphics::SCREEN_WIDTH + 10, Position().y);
	}
	if (Position().x > Graphics::SCREEN_WIDTH + 11) {
		Position(-10, Position().y);
	}
	if (Position().y < -11) {
		Position(Position().x, Graphics::SCREEN_HEIGHT + 10);
	}
	if (Position().y > Graphics::SCREEN_HEIGHT + 11) {
		Position(Position().x, -10);
	}
}

AsteroidPlay::AsteroidPlay(int asteroid, int count) :Texture("Asteroid.png", 0, 0, 80, 70)
{
	XPos = 0;
	YPos = 0;
	m_pRandom2 = Random::Instance();
	int randomStartPosition = m_pRandom2->RandomRange(0, 3);
	int rx = 0;
	int ry = 0;
	switch (randomStartPosition)
	{
	case 0:// Asteroids spawns from left of screen
		rx = -10;
		ry = m_pRandom2->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(rx, ry);
		XPos = m_pRandom2->RandomRange(1.0f, 5.0f);
		YPos = m_pRandom2->RandomRange(-5.0f, 5.0f);
		break;
	case 1:// Asteroids spawns from right of screen
		rx = Graphics::SCREEN_WIDTH + 10;
		ry = m_pRandom2->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(rx, ry);
		XPos = m_pRandom2->RandomRange(-5.0f, -1.0f);
		YPos = m_pRandom2->RandomRange(-5.0f, 5.0f);
		break;
	case 2:// Asteroids spawns from top of screen
		rx = m_pRandom2->RandomRange(0, Graphics::SCREEN_WIDTH);
		ry = -10;
		Position(rx, ry);
		XPos = m_pRandom2->RandomRange(-5.0f, 5.0f);
		YPos = m_pRandom2->RandomRange(1.0f, 5.0f);
		break;
	case 3:// Asteroids spawns from the bottom screen
		rx = m_pRandom2->RandomRange(0, Graphics::SCREEN_WIDTH);
		ry = Graphics::SCREEN_HEIGHT + 10;
		Position(rx, ry);
		XPos = m_pRandom2->RandomRange(-5.0f, 5.0f);
		YPos = m_pRandom2->RandomRange(-5.0f, -1.0f);
		break;
	default:
		break;
	}
}

AsteroidPlay::~AsteroidPlay()
{
	m_pRandom2 = nullptr;
}



void AsteroidPlay::Update()
{
	Translate(Vector2(XPos, YPos), GameEntity::World);
	CheckScreenBounds();
}

void AsteroidPlay::Render()
{
	Texture::Render();
}
