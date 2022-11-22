#include "SmallAsteroidRock.h"

void SmallAsteroidRock::CheckScreenBounds()
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

SmallAsteroidRock::SmallAsteroidRock(std::string filename) :Texture("SmallAsteroidRock1.png", 0, 0, 26, 28)
{
	m_pTex = AssetManager::Instance()->GetTexture(filename);

	m_pRandom = Random::Instance();
	int randomStartPosition = m_pRandom->RandomRange(0, 3);
	//int randomStartPosition = 3;
	int rx = 0;
	int ry = 0;
	switch (randomStartPosition)
	{
	case 0:// Asteroids spawns from left of screen
		rx = -10;
		ry = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(rx, ry);
		randVelocityX = m_pRandom->RandomRange(1.0f, 5.0f);
		randVelocityY = m_pRandom->RandomRange(-5.0f, 5.0f);
		break;
	case 1:// Asteroids spawns from right of screen
		rx = Graphics::SCREEN_WIDTH + 10;
		ry = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(rx, ry);
		randVelocityX = m_pRandom->RandomRange(-5.0f, -1.0f);
		randVelocityY = m_pRandom->RandomRange(-5.0f, 5.0f);
		break;
	case 2:// Asteroids spawns from top of screen
		rx = m_pRandom->RandomRange(0, Graphics::SCREEN_WIDTH);
		ry = -10;
		Position(rx, ry);
		randVelocityX = m_pRandom->RandomRange(-5.0f, 5.0f);
		randVelocityY = m_pRandom->RandomRange(1.0f, 5.0f);
		break;
	case 3:// Asteroids spawns from the bottom screen
		rx = m_pRandom->RandomRange(0, Graphics::SCREEN_WIDTH);
		ry = Graphics::SCREEN_HEIGHT + 10;
		Position(rx, ry);
		randVelocityX = m_pRandom->RandomRange(-5.0f, 5.0f);
		randVelocityY = m_pRandom->RandomRange(-5.0f, -1.0f);
		break;
	default:
		break;
	}
}

SmallAsteroidRock::~SmallAsteroidRock()
{
	m_pRandom = nullptr;
}

void SmallAsteroidRock::Update()
{
	Translate(Vector2(randVelocityX, randVelocityY), GameEntity::World);
	CheckScreenBounds();
}

void SmallAsteroidRock::Render()
{
	Texture::Render();
}