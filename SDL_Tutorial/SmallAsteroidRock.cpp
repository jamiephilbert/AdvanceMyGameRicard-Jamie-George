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

SmallAsteroidRock::SmallAsteroidRock()
{
	m_pTexture = new Texture("SmallAsteroidRock2.png", 0, 0, 26, 28);
	m_pTexture->Parent(this);
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

	AddCollider(new CircleCollider(13, false));
	m_pColliders[0]->Parent(this);
	m_pColliders[0]->Position(10.0f, 15.0f);
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);
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
	m_pTexture->Render();
	PhysEntity::Render();
}