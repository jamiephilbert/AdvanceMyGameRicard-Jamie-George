#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AsteroidPlay.h"
#include "SmallAsteroidRock.h"
#include "PlayGameBar.h"
#include "Game.h"
#include "Player.h"
#include "Timer.h"
#include "InputManager.h"
#include "Enemy.h"
#include <vector>

using namespace SDLFramework;

class PlayScreen : public GameEntity
{
public:

	const static int MAX_ASTEROIDS = 5;
	const static int MAX_SMALLASTEROIDS = 20;
	const static int MAX_UFO = 1;
private:
	
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	Texture* m_pTexture;
	InputManager* m_pInputManager;
	PlayGameBar* m_pPlayGameBar;
	std::vector<AsteroidPlay*> m_pBigAsteroid;
	std::vector<SmallAsteroidRock*> m_pSmallAsteroid;
	std::vector<Enemy*> m_pEnemy;
	int mAsteroidCount;
	int mSmallAsteroidCount;
	int mUFOCount;

	float mAsteroidTimer;
	float mAsteroidDelay;

	Player* m_pPlayer;

	Texture* m_pStartLabel;

	float mGameStartTimer;

	Game* m_pGame;
	bool mGameStarted;

public:
	PlayScreen();
	~PlayScreen();

	void StartNewGame();

	bool GameOver();

	void GenNewAsteroid();
	void GenNewUFO();
	void WasDestroyed();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H