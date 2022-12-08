#include "SmallAsteroidPlay.h"

void SmallAsteroidPlay::CheckScreenBounds()
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

SmallAsteroidPlay::SmallAsteroidPlay()
{
	m_pTexture = new Texture("SmallAsteroidRock2.png", 0, 0, 26, 28);
	m_pTexture->Parent(this);
	/*m_pTexture->Position(m_pBigAsteroid->Position());*/
	m_pRandom = Random::Instance();
	int randomStartPosition = m_pRandom->RandomRange(0, 3);
	
	//int randomStartPosition = 3;
	
	switch (randomStartPosition)
	{
	case 0:// Asteroids spawns from left of screen
		randVelocityX = m_pRandom->RandomRange(1.0f, 5.0f);
		randVelocityY = m_pRandom->RandomRange(-5.0f, 5.0f);
		break;
	case 1:// Asteroids spawns from right of screen
		randVelocityX = m_pRandom->RandomRange(-5.0f, -1.0f);
		randVelocityY = m_pRandom->RandomRange(-5.0f, 5.0f);
		break;
	case 2:// Asteroids spawns from top of screen
		randVelocityX = m_pRandom->RandomRange(-5.0f, 5.0f);
		randVelocityY = m_pRandom->RandomRange(1.0f, 5.0f);
		break;
	case 3:// Asteroids spawns from the bottom screen
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

SmallAsteroidPlay::~SmallAsteroidPlay()
{
	m_pRandom = nullptr;
}

bool SmallAsteroidPlay::IgnoreCollisions()
{
	return false;
}

void SmallAsteroidPlay::Hit(PhysEntity* other)
{
	Parent(nullptr);

}

void SmallAsteroidPlay::Update()
{
	Translate(Vector2(randVelocityX, randVelocityY), GameEntity::World);
	CheckScreenBounds();
}

void SmallAsteroidPlay::Render()
{
	m_pTexture->Render();
	PhysEntity::Render();
}