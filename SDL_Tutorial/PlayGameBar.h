#ifndef _PLAYGAMEBAR_H
#define _PLAYGAMEBAR_H
#include "ScoreBoard.h"
#include "AsteroidRock.h"


class PlayGameBar : public GameEntity
{
private:
	Texture* m_pHighLabel;
	Texture* m_pYourLabel;
	Texture* m_pLivesLabel;

	Texture* m_pShipLives;
	Texture* m_pShipLives2;
	Texture* m_pShipLives3;

	Scoreboard* m_pHighScoreBoard;
	Scoreboard* m_pPlayerBoard;

	

public:
	PlayGameBar();
	~PlayGameBar();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYGAMEBAR_H