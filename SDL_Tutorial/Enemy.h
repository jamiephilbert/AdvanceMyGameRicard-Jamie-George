#ifndef _ENEMY_H
#define _ENEMY_H
#include "AnimatedTexture.h"
#include "Random.h"
#include "PhysEntity.h"
#include "Player.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class Enemy : public PhysEntity
{
public:
	enum States{Spawn, Dead};

	static const int MAX_BULLETS = 4;
	Bullet* m_pBullets[MAX_BULLETS];
private:

	Timer* m_pTimer;
	Texture* m_pUFO;
	States mCurrentState;
	Random* m_pRandom;
	int mCoinFlipped;
	bool mMoveUFO;
	bool mVisible;
	int UFOX;
	int UFOY;
	float ux;
	float uy;
	float mPathChangeTimer;
	float mPathCount;

	float mSpeed;

protected:
	/*virtual void HandleSpawnState();
	virtual void HandleDeadState();

	void HandleStates();

	virtual void RenderSpawnState();
	virtual void RenderDeadState();

	

	void RenderStates();*/
	void CheckScreenBounds();
public:
	Enemy();

	~Enemy();
	void Visible(bool visible);
	void WasHit();
	bool IsAnimated();
	
	States CurrentState();

	void Update();
	void Render();
};

#endif // !_ENEMY_H
