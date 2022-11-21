#ifndef _PLAYMENUBAR_H
#define _PLAYMENUBAR_H
#include "Scoreboard.h"
#include "AsteroidRock.h"



class PlayMenuBar : public GameEntity
{
private:
	Texture* m_pHighLabel;
	Texture* m_pScoreLabel;
	Texture* m_pYourLabel;
	Texture* m_pLivesLabel;

	Scoreboard* m_pHighScoreBoard;
	Scoreboard* m_pPlayerBoard;
	Scoreboard* m_pLivesBoard;

	

public:
	PlayMenuBar();
	~PlayMenuBar();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYMENUBAR_H