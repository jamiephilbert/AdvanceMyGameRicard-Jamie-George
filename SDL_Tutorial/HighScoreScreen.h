#ifndef _HIGHSCORESCREEN_H
#define _HIGHSCORESCREEN_H
#include "PlayScreen.h"
#include "Scoreboard.h"

class HighScoreScreen : public GameEntity
{

public:
	HighScoreScreen();
	~HighScoreScreen();

	GameEntity* m_pScoreBar;
	Texture* m_pLogo;

	Texture* m_pPosTitle;
	Texture* m_pNameTitle;
	Texture* m_pScoreTitle;

	Texture* m_pTopScoreName;
	Texture* m_pSecondScoreName;
	Texture* m_pThirdScoreName;

	Texture* m_pTopScorePos;
	Texture* m_pSecondScorePos;
	Texture* m_pThirdScorePos;

	Scoreboard* m_pTopScore;
	Scoreboard* m_pSecondScore;
	Scoreboard* m_pThirdScore;


	void Update() override;
	void Render() override;
};

#endif
