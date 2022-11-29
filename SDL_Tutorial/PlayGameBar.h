#ifndef _PLAYGAMEBAR_H
#define _PLAYGAMEBAR_H
#include "ScoreBoard.h"
#include "AsteroidRock.h"
#include "Timer.h"
#include "AudioManager.h"
#include "Player.h"


class PlayGameBar : public GameEntity
{
private:
	static const int MAX_SHIP_TEXTURES = 5;

	Timer* m_pTimer;
	AudioManager* m_pAudio;

	Texture* m_pHighLabel;
	Texture* m_pScoreLabel;
	Texture* m_pYourLabel;
	Texture* m_pLivesLabel;

	//Texture* m_pShipLives[MAX_SHIP_TEXTURES];
	Texture* m_pShipLives;
	Texture* m_pShipLives2;
	Texture* m_pShipLives3;
	Player* m_pLives;

	Scoreboard* m_pHighScoreBoard;
	Scoreboard* m_pPlayerBoard;
	Scoreboard* m_pLivesBoard;

	

public:
	PlayGameBar();
	~PlayGameBar();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYGAMEBAR_H