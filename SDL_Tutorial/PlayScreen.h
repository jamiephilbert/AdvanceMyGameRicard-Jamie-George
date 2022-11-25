#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AsteroidRock.h"
#include "SmallAsteroidRock.h"
#include "PlayGameBar.h"
#include "Game.h"
#include "Player.h"

class PlayScreen : public GameEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	PlayGameBar* m_pPlayGameBar;

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

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H