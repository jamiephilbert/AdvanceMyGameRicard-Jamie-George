//#include "Enemy.h"
//
//
//Enemy::Enemy()
//{
//	m_pTimer = Timer::Instance();
//	m_pUFO = new Texture("UFOSprite1.png", 0, 0, 42, 32);
//	mCurrentState = Spawn;
//	mCoinFlipped = 0;
//	mMoveUFO = false;
//	mVisible = true;
//
//	mSpeed = 0;
//}
//
//
//void Enemy::HandleSpawnState()
//{
//	mCoinFlipped = rand() % 2;
//	if (mCoinFlipped == 0) {
//		Position()
//	}
//	if (mCoinFlipped == 1) {
//
//	}
//
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
//
//void Enemy::RenderSpawnState()
//{
//}
//
//void Enemy::RenderPathTakenState()
//{
//}
//
//void Enemy::RenderDeadState()
//{
//}
//
//void Enemy::RenderStates()
//{
//
//	switch (mCurrentState) {
//	case Spawn:
//		RenderSpawnState();
//		break;
//
//	case PathTaken:
//		RenderPathTakenState();
//		break;
//	case Dead:
//		RenderDeadState();
//		break;
//
//	}
//}
//
//
//
//
//Enemy::~Enemy()
//{
//	m_pTimer = nullptr;
//
//	delete m_pUFO;
//	m_pUFO = nullptr;
//}
//
//void Enemy::Visible(bool visible)
//{
//}
//
//void Enemy::WasHit()
//{
//}
//
//bool Enemy::IsAnimated()
//{
//	return false;
//}
//
//Enemy::States Enemy::CurrentState()
//{
//	return mCurrentState;
//}
//
//void Enemy::Update()
//{
//	if (Active()) {
//		HandleStates();
//	}
//}
//
//void Enemy::Render()
//{
//	if (Active()) {
//		m_pUFO->Render();
//		RenderStates();
//	}
//}
