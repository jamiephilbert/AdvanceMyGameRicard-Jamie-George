#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AsteroidPlay.h"
#include "SmallAsteroidRock.h"
#include "PlayGameBar.h"
#include "Timer.h"
#include "InputManager.h"

using namespace SDLFramework;

class PlayScreen : public GameEntity
{
public:
	const static int MAX_ASTEROIDZ = 10;
	const static int MAX_SMALLASTEROIDZ = 10;


private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;
	PlayGameBar* m_pPlayGameBar;
	AsteroidPlay* m_pBigAsteroid[MAX_ASTEROIDZ];
	SmallAsteroidRock* m_pSmallAsteroid[MAX_SMALLASTEROIDZ];
	float mSpeed;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H