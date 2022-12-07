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

	m_pShipThrusters = new Texture("ShipThrusters.png", 0, 0, 18, 17);
	m_pShipThrusters->Parent(this);
	m_pShipThrusters->Position(0.0f, 21.0f);

	mCurrentSpeed = 0.0f;
	mMoveSpeed = 0.0f;
	mMaxSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);

	m_pDeathAnimation = new AnimatedTexture("PlayerExplosion.png", 0, 0, 150, 34, 3, 1.0f, AnimatedTexture::Horizontal);
	m_pDeathAnimation->Parent(this);
	m_pDeathAnimation->Position(Vec2_Zero);
	m_pDeathAnimation->SetWrapMode(AnimatedTexture::Once);

	for (int i = 0; i < MAX_BULLETS; i++) {
		m_pBullets[i] = new Bullet();
	}


	AddCollider(new BoxCollider(Vector2(20.0f, 30.0f)), Vector2(-10.0f, -13.0f));
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);
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

	delete m_pShipThrusters;
	m_pShipThrusters = nullptr;

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

void Player::Hit(PhysEntity* other)
{
	if (Position().y > other->Position().y) {

	}
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
	m_pShipThrusters->Update();

	if (mAnimating) {
		m_pDeathAnimation->Update();
		mAnimating = m_pDeathAnimation->IsAnimating();
	}
	else {
		if (Active()) {
			HandleMovement();
			HandleFire();
			ShipPhysics();
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
	m_pShipThrusters->Render();

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


	PhysEntity::Render();
}

void Player::HandleMovement()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
		Rotate(1.5f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		Rotate(-1.5f);
	}
	if (m_pInput->KeyDown(SDL_SCANCODE_W)) {
		misMoving = true;
		//mShipThrusters = true;
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_W)) {
		misMoving = false;
		//mShipThrusters = false;
	}

	PlayerCheckBounds();
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

bool Player::IgnoreCollisions()
{
	return !mVisible || mAnimating;
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
	Translate(-Vec2_Up * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
	if (misMoving == true) {
		mCurrentSpeed += 100.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed > mMaxSpeed) {
			mCurrentSpeed = mMaxSpeed;
		}
	}

	if (misMoving == false) {
		mCurrentSpeed -= 100.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed < 0.0f) {
			mCurrentSpeed = 0.0f;
			mMoveSpeed = 0.0f;
		}
	}
}