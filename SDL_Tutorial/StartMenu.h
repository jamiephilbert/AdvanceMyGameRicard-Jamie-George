#ifndef _STARTMENU_H
#define _STARTMENU_H
//#include "Scoreboard.h"
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "AsteroidRock.h"
#include "SmallAsteroidRock.h"
#include "MiniAsteroidRockA.h"

using namespace SDLFramework;

class StartMenu : public GameEntity {
public:
	const static int MAX_ASTEROIDS = 10;
	const static int MAX_SMALLASTEROIDS = 10;

private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;
;
	//Scoreboard* m_pTopScore;

	// Play Mode Entities
	GameEntity* m_pPlayModes;
	Texture* m_pPlayGame;
	Texture* m_pHighScoreMenu;
	Texture* m_pCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	// Bottom Bar Entities
	GameEntity* m_pBottomBar;
	Texture* m_pAtari;
	Texture* m_pDates;
	Texture* m_pRights;

	// Logo Entities
	Texture* m_pLogo;

	// screen animation variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	AsteroidRock* m_pRocks[MAX_ASTEROIDS];
	SmallAsteroidRock* m_pSmallRocks[MAX_SMALLASTEROIDS];

public:
	StartMenu();
	~StartMenu();

	void ChangeSelectedMode(int change);

	int SelectedMode();

	void Update() override;
	void Render() override;
};


#endif // !_STARTMENU_H