//#ifndef _ENEMY_H
//#define _ENEMY_H
//#include "AnimatedTexture.h"
//
//using namespace SDLFramework;
//
//class Enemy : public GameEntity
//{
//public:
//	enum States{Spawn, PathTaken,  Dead};
//private:
//	Timer* m_pTimer;
//	Texture* m_pUFO;
//	States mCurrentState;
//	int mCoinFlipped;
//	bool mMoveUFO;
//	bool mVisible;
//
//	float mSpeed;
//
//protected:
//	virtual void HandleSpawnState();
//	virtual void HandlePathTakenState();
//	virtual void HandleDeadState();
//
//	void HandleStates();
//
//	virtual void RenderSpawnState();
//	virtual void RenderPathTakenState();
//	virtual void RenderDeadState();
//
//	void RenderStates();
//
//public:
//	Enemy();
//	~Enemy();
//	void Visible(bool visible);
//	void WasHit();
//	bool IsAnimated();
//	
//	States CurrentState();
//
//	void Update();
//	void Render();
//};
//
//#endif // !_ENEMY_H
