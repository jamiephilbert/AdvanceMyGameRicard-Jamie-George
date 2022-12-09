#ifndef _PLAYER_H
#define _PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Bullet.h"
#include "Timer.h"
#include "PhysEntity.h" 
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class Player : public PhysEntity
{
private:
	static const int MAX_BULLETS = 4;
	//static const int MAX_THRUSTERS = 9999999;
	Bullet* m_pBullets[MAX_BULLETS];

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	bool mVisible;
	bool mAnimating;
	bool misMoving;
	bool mWasHit;
	//bool mShipThrusters;

	int mScore;
	int mLives;

	Texture* m_pShip;
	Texture* m_pShipThrusters;
	//ShipThrusters* m_pShipThrusters[MAX_THRUSTERS];
	AnimatedTexture* m_pDeathAnimation;

	float mCurrentSpeed;
	float mMoveSpeed;
	float mMaxSpeed;
	Vector2 mMoveBounds;

public:
	Player();
	~Player();

	void Visible(bool visible);
	bool IsAnimating();

	int Score();
	int Lives();

	void AddScore(int change);

	void WasHit();
	void WasHit(bool hit);

	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;

private:
	void HandleMovement();
	void HandleFire();
	//void HandleThrusters();
	void PlayerCheckBounds();
	void ShipPhysics();

	//void ShipThrusters();

};

#endif // !_PLAYER_H