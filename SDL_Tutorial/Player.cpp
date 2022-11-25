#include "Player.h"

Player::Player()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;

	mScore = 0;
	mLives = 3;

	m_pShip = new Texture("RedShip.png", 0, 0, 22, 30);
	m_pShip->Parent(this);
	m_pShip->Position(0.0f, 0.0f);

	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);

	m_pDeathAnimation = new AnimatedTexture("PlayerExplosion.png", 0, 0, 150, 34, 3, 1.0f, AnimatedTexture::Horizontal);
	m_pDeathAnimation->Parent(this);
	m_pDeathAnimation->Position(Vec2_Zero);
	m_pDeathAnimation->SetWrapMode(AnimatedTexture::Once);

	for (int i = 0; i < MAX_BULLETS; i++) {
		m_pBullets[i] = new Bullet();
	}
}

Player::~Player()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pDeathAnimation;
	m_pDeathAnimation = nullptr;

	delete m_pShip;
	m_pShip = nullptr;

	for (int i = 0; i < MAX_BULLETS; i++) {
		delete m_pBullets[i];
		m_pBullets[i] = nullptr;
	}
}

void Player::Visible(bool visible)
{
	mVisible = visible;
}

bool Player::IsAnimating()
{
	return mAnimating;
}

int Player::Lives()
{
	return mLives;
}

int Player::Score()
{
	return mScore;
}

void Player::AddScore(int change)
{
	mScore += change;
}

void Player::WasHit()
{
	mLives -= 1;
	mAnimating = true;
	m_pDeathAnimation->ResetAnimation();
	m_pAudio->PlaySFX("SFX/PlayerExplosion.wav", 0, -1);
}

void Player::Update()
{
	m_pShip->Update();
	HandleMovement();

	if (mAnimating) {
		m_pDeathAnimation->Update();
		mAnimating = m_pDeathAnimation->IsAnimating();
	}
	else {
		if (Active()) {
			HandleMovement();
			HandleFire();
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		m_pBullets[i]->Update();
	}
}

void Player::Render()
{
	m_pShip->Render();
	HandleMovement();

	if (mVisible) {
		if (mAnimating) {
			m_pDeathAnimation->Render();
		}
		else {
			m_pShip->Render();
		}
	}

	for (int i = 0; i < MAX_BULLETS; i++) {
		m_pBullets[i]->Render();
	}
}

void Player::HandleMovement()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
		Rotate(5.0f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		Rotate(-5.0f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_W)) {
		Translate(-Vec2_Up * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_S)) {
		Translate(Vec2_Up * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
}

void Player::HandleFire()
{
	if (m_pInput->KeyPressed(SDL_SCANCODE_SPACE)) {
		//-------------OBJECT POOL-----------------//
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (!m_pBullets[i]->Active()) {
				m_pBullets[i]->Fire(Position());
				m_pAudio->PlaySFX("SFX/Fire.wav", 0, -1);
				break;
			}
		}
	}
}