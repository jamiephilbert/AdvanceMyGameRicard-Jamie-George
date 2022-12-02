#ifndef _PLAYER_H
#define _PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Bullet.h"
#include "Timer.h"

using namespace SDLFramework;

class Player : public GameEntity
{
private:
	static const int MAX_BULLETS = 4;
	Bullet* m_pBullets[MAX_BULLETS];

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	bool mVisible;
	bool mAnimating;
	bool misMoving;

	int mScore;
	int mLives;

	Texture* m_pShip;
	Texture* m_pShipThrusters;
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

	void Update() override;
	void Render() override;

private:
	void HandleMovement();
	void HandleFire();
	void PlayerCheckBounds();
	void ShipPhysics();

	bool ShipThrusters();

};

#endif // !_PLAYER_H