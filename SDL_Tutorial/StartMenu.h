#ifndef _STARTMENU_H
#define _STARTMENU_H
//#include "Scoreboard.h"
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "AsteroidRock.h"
#include "SmallAsteroidRock.h"
#include "SmallAsteroidRockB.h"
#include "SmallAsteroidRockC.h"
#include "SmallAsteroidRockD.h"
#include "MiniAsteroidRockA.h"

using namespace SDLFramework;

class StartMenu : public GameEntity {
public:
	const static int MAX_ASTEROIDS = 10;
	const static int MAX_SMALLASTEROIDS1 = 10;
	const static int MAX_SMALLASTEROIDS2 = 10;
	const static int MAX_SMALLASTEROIDS3 = 10;
	const static int MAX_SMALLASTEROIDS4 = 10;

private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;

	/*GameEntity* m_pTopBar;
	Texture* m_pPlayer;
	Texture* m_pHighScore;*/
	//Scoreboard* m_pPlayerScore;
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
	SmallAsteroidRock* m_pSmallRocks1[MAX_SMALLASTEROIDS1];
	SmallAsteroidRockB* m_pSmallRocks2[MAX_SMALLASTEROIDS2];
	SmallAsteroidRockC* m_pSmallRocks3[MAX_SMALLASTEROIDS3];
	SmallAsteroidRockD* m_pSmallRocks4[MAX_SMALLASTEROIDS4];

public:
	StartMenu();
	~StartMenu();

	void ChangeSelectedMode(int change);

	int SelectedMode();

	void Update() override;
	void Render() override;
};


#endif // !_STARTMENU_H