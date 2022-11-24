#ifndef _GAME_H
#define _GAME_H
#include "PlayGameBar.h"
#include "Player.h"
//#include "Enemy.h"

class Game : public GameEntity
{
public:
	enum GameState { Running, Finished, GameOver };

private:
	Timer* m_pTimer;
	PlayGameBar* m_pGameBar;

	//Enemy* m_pEnemy;

	int mGame;
	bool mGameStarted;

	float mLabelTimer;

	Texture* m_pGameLabel;
	Scoreboard* m_pGameNumber;
	float mGameLabelOnScreen;
	float mGameLabelOffScreen;

	Texture* m_pReadyLabel;
	float mReadyLabelOnScreen;
	float mReadyLabelOffScreen;

	Player* m_pPlayer;

	bool mPlayerHit;
	float mRespawnDelay;
	float mRespawnTimer;
	float mRespawnLabelOnScreen;

	Texture* m_pGameOverLabel;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;

	GameState mCurrentState;

private:
	void StartGame();

	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();

public:
	Game(int stage, PlayGameBar* sidebar, Player* player);
	~Game();

	GameState State();

	void Update() override;
	void Render() override;
};

#endif // !_GAME_H