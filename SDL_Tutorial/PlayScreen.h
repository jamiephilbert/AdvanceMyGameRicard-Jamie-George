#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AsteroidRock.h"
#include "SmallAsteroidRock.h"
#include "PlayGameBar.h"
//#include "Game.h"
#include "Player.h"

class PlayScreen : public GameEntity
{
private:

	PlayGameBar* m_pPlayGameBar;

	Game* m_pGame;
	bool mGameStarted;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H