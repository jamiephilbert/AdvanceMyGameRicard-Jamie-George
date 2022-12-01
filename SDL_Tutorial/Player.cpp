#include "Player.h"

Player::Player()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	misMoving = false;

	mScore = 0;
	mLives = 3;

	m_pShip = new Texture("RedShip.png", 0, 0, 22, 30);
	m_pShip->Parent(this);
	m_pShip->Position(0.0f, 0.0f);

	mCurrentSpeed = 0.0f;
	mMoveSpeed = 0.0f;
	mMaxSpeed = 200.0f;
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
	if (m_pInput->KeyPressed(SDL_SCANCODE_Q)) {
		mLives -= 1;
	}
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
	ShipPhysics();

	//if (misMoving == false) {
	//	mCurrentSpeed -= 20.0f * m_pTimer->DeltaTime();
	//	if (mCurrentSpeed < 0.0f) {
	//		mCurrentSpeed = 0.0f;
	//		mMoveSpeed = 0.0f;
	//	}
	//}

	if (mAnimating) {
		m_pDeathAnimation->Update();
		mAnimating = m_pDeathAnimation->IsAnimating();
	}
	else {
		if (Active()) {
			HandleMovement();
			ShipPhysics();
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
		Rotate(2.0f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		Rotate(-2.0f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_W)) {
		misMoving = true;
		Translate(-Vec2_Up * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()),  World));
		ShipPhysics();
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_W)) {
		misMoving = false;
		Translate(-Vec2_Up * (mCurrentSpeed + mMoveSpeed) * (std::cos(Rotation()), std::sin(Rotation()), World));
		ShipPhysics();
	}

	PlayerCheckBounds();

	//Vector2 direction(std::cos(Rotation()), std::sin(Rotation()));
}

void Player::HandleFire()
{
	if (m_pInput->KeyPressed(SDL_SCANCODE_SPACE)) {
		//if (m_pInput->KeyDown(SDL_SCANCODE_D) || m_pInput->KeyDown(SDL_SCANCODE_A)) {
		//	Translate(-Vec2_Up * ((std::cos(Active()), std::sin(Active()), (-Vec2_Up * mMoveSpeed * m_pTimer->DeltaTime(), World))));
		//}

		//-------------OBJECT POOL-----------------//
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (!m_pBullets[i]->Active()) {
				m_pBullets[i]->Fire(Position(), Rotation());
				m_pAudio->PlaySFX("SFX/fire.wav", 0, -1);
				break;
			}
		}
	}
}

void Player::PlayerCheckBounds()
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

void Player::ShipPhysics()
{
	if (misMoving == true) {
		mCurrentSpeed += 20.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed > mMaxSpeed) {
			mCurrentSpeed = mMaxSpeed;
		}
	}

	if (misMoving == false) {
		mCurrentSpeed -= 20.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed < 0.0f) {
			mCurrentSpeed = 0.0f;
			mMoveSpeed = 0.0f;
		}
	}
}
