#include "Enemy.h"


Enemy::Enemy() : Texture("UFOSprite1.png", 0, 0, 42, 32)
{
	m_pRandom = Random::Instance();
	m_pTimer = Timer::Instance();
	UFOX = 0;
	UFOY = 0;
	mCoinFlipped = 0;

	mCoinFlipped = m_pRandom->RandomRange(0, 10);
	if (mCoinFlipped < 5) {
		ux = -10;
		uy = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(ux, uy);
		UFOX = m_pRandom->RandomRange(1.0f, 5.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);
	}
	else
	{
		ux = Graphics::SCREEN_WIDTH + 10;
		uy = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		Position(ux, uy);
		UFOX = m_pRandom->RandomRange(-5.0f, -1.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);
	}

	
	
	/*mCurrentState = Spawn;*/
	
	/*mMoveUFO = false;
	mVisible = true;
	mSpeed = 0;*/
}


//void Enemy::HandleSpawnState()
//{
//}
//
//void Enemy::HandlePathTakenState()
//{ 
//}
//
//void Enemy::HandleDeadState()
//{
//}
//
//void Enemy::HandleStates()
//{
//	switch (mCurrentState) {
//	case Spawn:
//		HandleSpawnState();
//		break;
//
//	case PathTaken:
//		HandlePathTakenState();
//		break;
//	case Dead:
//		HandleDeadState();
//		break;
//
//	}
//}

//void Enemy::RenderSpawnState()
//{
//}
//
//void Enemy::RenderPathTakenState()
//{
//}
void Enemy::CheckScreenBounds()
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

//void Enemy::RenderStates()
//{

	/*switch (mCurrentState) {
	case Spawn:
		RenderSpawnState();
		break;

	case PathTaken:
		RenderPathTakenState();
		break;
	case Dead:
		RenderDeadState();
		break;

	}*/
//}




Enemy::~Enemy()
{
	m_pTimer = nullptr;

	/*delete m_pUFO;
	m_pUFO = nullptr;*/

}


//void Enemy::Visible(bool visible)
//{
//}

//void Enemy::WasHit()
//{
//}
//
//bool Enemy::IsAnimated()
//{
//	return false;
//}

//Enemy::States Enemy::CurrentState()
//{
//	return mCurrentState;
//}

void Enemy::Update()
{
	Translate(Vector2(UFOX, UFOY), GameEntity::World);
	CheckScreenBounds();
}

void Enemy::Render()
{
	Texture::Render();
}
