#ifndef _PLAYGAMEBAR_H
#define _PLAYGAMEBAR_H
#include "ScoreBoard.h"
#include "AsteroidRock.h"
#include "Timer.h"
#include "AudioManager.h"


class PlayGameBar : public GameEntity
{
private:
	static const int MAX_SHIP_TEXTURES = 3;

	Timer* m_pTimer;
	AudioManager* m_pAudio;

	Texture* m_pHighLabel;
	Texture* m_pScoreLabel;
	Texture* m_pYourLabel;
	Texture* m_pLivesLabel;

	GameEntity* m_pShips;
	Texture* m_pShipTextures[MAX_SHIP_TEXTURES];
	Scoreboard* m_pTotalShipsLabel;
	Scoreboard* m_pHighScoreBoard;
	Scoreboard* m_pPlayerBoard;
	Scoreboard* m_pLivesBoard;

	int mTotalShips;
	

public:
	PlayGameBar();
	~PlayGameBar();

	void SetHighScore(int score);
	void SetPlayerScore(int score);
	void SetShips(int ships);


	void Update() override;
	void Render() override;
};

#endif // !_PLAYGAMEBAR_H