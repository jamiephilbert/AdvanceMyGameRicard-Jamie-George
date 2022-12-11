#include "Enemy.h"


Enemy::Enemy()
{
	/*mPathChangeTimer = 0.0f;
	mPathCount = 1.0f;
	m_pTimer->DeltaTime();*/
	m_pUFO = new Texture("UFOSprite1.png", 0, 0, 42, 32);
	m_pUFO->Parent(this);

	m_pRandom = Random::Instance();
	m_pTimer = Timer::Instance();
	UFOX = 0;
	UFOY = 0;
	mCoinFlipped = 0;
	

	mCoinFlipped = m_pRandom->RandomRange(0, 10);
	if (mCoinFlipped < 5) {
		ux = -10;
		uy = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		m_pUFO->Position(ux, uy);
		UFOX = m_pRandom->RandomRange(1.0f, 5.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);

	}
	else
	{
		ux = Graphics::SCREEN_WIDTH + 10;
		uy = m_pRandom->RandomRange(0, Graphics::SCREEN_HEIGHT);
		m_pUFO->Position(ux, uy);
		UFOX = m_pRandom->RandomRange(-5.0f, -1.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);
	}

	AddCollider(new CircleCollider(23, false));
	m_pColliders[0]->Parent(m_pUFO);
	m_pColliders[0]->Position(0.0f, 0.0f);
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);
	

	mUFODirectionDelay = 2.0f;
	mUFODirectionTimer = 0.0f;
	/*mCurrentState = Spawn;*/
	
	/*mMoveUFO = false;
	mVisible = true;
	mSpeed = 0;*/
}


//void Enemy::HandleSpawnState()
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
	if (m_pUFO->Position().x < -11) {
		m_pUFO->Position(Graphics::SCREEN_WIDTH + 10, m_pUFO->Position().y);
	}
	if (m_pUFO->Position().x > Graphics::SCREEN_WIDTH + 11) {
		m_pUFO->Position(-10, m_pUFO->Position().y);
		
	}
	if (m_pUFO->Position().y < -11) {
		m_pUFO->Position(m_pUFO->Position().x, Graphics::SCREEN_HEIGHT + 10);
	}
	if (m_pUFO->Position().y > Graphics::SCREEN_HEIGHT + 11) {
		m_pUFO->Position(m_pUFO->Position().x, -10);
	}
}

//void Enemy::RenderStates()
//{

	/*switch (mCurrentState) {
	case Spawn:
		RenderSpawnState();
		break;
	case Dead:
		RenderDeadState();
		break;

	}*/
//}




Enemy::~Enemy()
{
	delete m_pUFO;
	m_pUFO = nullptr;

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
	mUFODirectionTimer += m_pTimer->DeltaTime();
	m_pUFO->Translate(Vector2(UFOX, UFOY), GameEntity::World);
	CheckScreenBounds();
	if (mUFODirectionTimer >= mUFODirectionDelay) {
		mUFODirectionTimer = 0.0f;
		if (mCoinFlipped < 5) {
		UFOX =  m_pRandom->RandomRange(1.0f, 5.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);
		}
		else
		{
		UFOX = m_pRandom->RandomRange(-5.0f, -1.0f);
		UFOY = m_pRandom->RandomRange(-5.0f, 5.0f);
		}
	}
}

void Enemy::Render()
{
	m_pUFO->Render();
	PhysEntity::Render();
}