#ifndef _ENEMY_H
#define _ENEMY_H
#include "AnimatedTexture.h"
#include "Random.h"

using namespace SDLFramework;

class Enemy : public Texture
{
public:
	enum States{Spawn, PathTaken,  Dead};
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

	float mSpeed;

protected:
	/*virtual void HandleSpawnState();
	virtual void HandlePathTakenState();
	virtual void HandleDeadState();

	void HandleStates();

	virtual void RenderSpawnState();
	virtual void RenderPathTakenState();
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
