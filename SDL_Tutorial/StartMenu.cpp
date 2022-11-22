#include "StartMenu.h"

StartMenu::StartMenu()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	// Top Bar Entities
	/*m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	m_pPlayer = new Texture("1UP", "emulogic.ttf", 32, { 200,0,0 });
	m_pHighScore = new Texture("HIGH SCORE", "emulogic.ttf", 32, { 200,0,0 });*/
	//m_pPlayerScore = new Scoreboard;
	//m_pTopScore = new Scoreboard;

	//// Play Mode Entities
	m_pPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	m_pPlayGame = new Texture("Play Game", "Starzone.ttf", 50, { 255,180,0 });
	m_pHighScoreMenu = new Texture("High Score", "Starzone.ttf", 50, { 255,180,0 });
	m_pCursor = new Texture(">", "Starzone.ttf", 60, { 255,180,0 });

	// Bottom Bar Entities
	m_pBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	m_pAtari = new Texture("ATARI", "ARCADE.TTF", 80, { 200,0,0 });
	m_pDates = new Texture("1979 ATARI LTD.", "AtariClassic.ttf", 40, { 230,230,230 });
	m_pRights = new Texture("ALL RIGHTS RESERVED", "AtariClassic.ttf", 40, { 230,230,230 });

	// Logo Entities
	m_pLogo = new Texture("AsteroidsLogo.png", 0, 0, 478, 153);
	m_pLogo->Parent(this);
	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.31f);

	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		m_pRocks[i] = new AsteroidRock(); {
			for (int a = 0; a < MAX_SMALLASTEROIDS1; a++)
				m_pSmallRocks1[a] = new SmallAsteroidRock(); {
				for (int b = 0; b < MAX_SMALLASTEROIDS2; b++)
					m_pSmallRocks2[b] = new SmallAsteroidRockB(); {
					for (int c = 0; c < MAX_SMALLASTEROIDS3; c++)
						m_pSmallRocks3[c] = new SmallAsteroidRockC(); {
						for (int d = 0; d < MAX_SMALLASTEROIDS4; d++)
							m_pSmallRocks4[d] = new SmallAsteroidRockD(); {
							for (int a = 0; a < MAX_MINIASTEROIDSA; a++)
								m_pMiniRocks1[a] = new MiniAsteroidRockA(); {
								for (int b = 0; b < MAX_MINIASTEROIDSB; b++)
									m_pMiniRocks2[b] = new MiniAsteroidRockB(); {
									for (int c = 0; c < MAX_MINIASTEROIDSC; c++)
										m_pMiniRocks3[c] = new MiniAsteroidRockC(); {
										for (int d = 0; d < MAX_MINIASTEROIDSD; d++)
											m_pMiniRocks4[d] = new MiniAsteroidRockD();
									}
								}
							}
						}
					}
				}
			}
		}
	}



	//// Top Bar Entities
	//m_pTopBar->Parent(this);
	//m_pPlayer->Parent(m_pTopBar);
	//m_pHighScore->Parent(m_pTopBar);
	//m_pPlayerScore->Parent(m_pTopBar);
	//m_pTopScore->Parent(m_pTopBar);

	//// Play Mode Entities
	m_pPlayModes->Parent(this);
	m_pPlayGame->Parent(m_pPlayModes);
	m_pHighScoreMenu->Parent(m_pPlayModes);
	m_pCursor->Parent(m_pPlayModes);


	//// Bottom Bar Entities
	m_pBottomBar->Parent(this);
	m_pAtari->Parent(m_pBottomBar);
	m_pDates->Parent(m_pBottomBar);
	m_pRights->Parent(m_pBottomBar);

	//// Top Bar Entities
	//m_pPlayer->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	//m_pHighScore->Position(-0.0f, 0.0f);
	//m_pPlayerScore->Position(-Graphics::SCREEN_WIDTH * 0.35f, 40.0f);
	//m_pTopScore->Position(Graphics::SCREEN_WIDTH * 0.07f, 40.0f);
	//m_pTopScore->Score(645987);

	//// Play Mode Entities
	m_pPlayGame->Position(0.0f, -35.0f);
	m_pHighScoreMenu->Position(0.0f, 35.0f);
	m_pCursor->Position(-230.f, -25.9f);

	//// Bottom Bar Entities
	m_pAtari->Position(Vec2_Zero);
	m_pDates->Position(0.0f, 90.0f);
	m_pRights->Position(0.0f, 170.0f);

	//mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
	//mAnimationEndPos = Vec2_Zero;
	//mAnimationTotalTime = 5.0f;
	//mAnimationTimer = 0.0f;
	//mAnimationDone = false;

	//Position(mAnimationStartPos);

	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0; 

	/*m_pStars = BackgroundStars::Instance();
	m_pStars->Scroll(true);*/
}

StartMenu::~StartMenu()
{
	/*delete m_pTopBar;
	m_pTopBar = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pHighScore;*/

	m_pTimer = nullptr;
	m_pInputManager = nullptr;

	delete m_pPlayModes;
	m_pPlayModes = nullptr;

	delete m_pPlayGame;
	m_pPlayGame = nullptr;

	delete m_pCursor;
	m_pCursor = nullptr;

	delete m_pBottomBar;
	m_pBottomBar = nullptr;

	delete m_pAtari;
	m_pAtari = nullptr;

	delete m_pDates;
	m_pDates = nullptr;

	delete m_pRights;
	m_pRights = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		delete m_pRocks[i];
		m_pRocks[i] = nullptr;
	}
	
	for (int a = 0; a < MAX_SMALLASTEROIDS1; a++) {
		delete m_pSmallRocks1[a];
		m_pSmallRocks1[a] = nullptr;
	}

	for (int b = 0; b < MAX_SMALLASTEROIDS2; b++) {
		delete m_pSmallRocks2[b];
		m_pSmallRocks2[b] = nullptr;
	}

	for (int c = 0; c < MAX_SMALLASTEROIDS3; c++) {
		delete m_pSmallRocks3[c];
		m_pSmallRocks3[c] = nullptr;
	}

	for (int d = 0; d < MAX_SMALLASTEROIDS4; d++) {
		delete m_pSmallRocks4[d];
		m_pSmallRocks4[d] = nullptr;
	}

	for (int a = 0; a < MAX_MINIASTEROIDS1; a++) {
		delete m_pMiniRocks1[a];
		m_pMiniRocks1[a] = nullptr;
	}

	for (int b = 0; b < MAX_MINIASTEROIDS2; b++) {
		delete m_pMiniRocks2[b];
		m_pMiniRocks2[b] = nullptr;
	}

	for (int c = 0; c < MAX_MINIASTEROIDS3; c++) {
		delete m_pMiniRocks3[c];
		m_pMiniRocks3[c] = nullptr;
	}

	for (int d = 0; d < MAX_MINIASTEROIDS4; d++) {
		delete m_pMiniRocks4[d];
		m_pMiniRocks4[d] = nullptr;
	}

	delete m_pHighScoreMenu;
	m_pHighScoreMenu = nullptr;


	//delete m_pPlayerScore;
	//m_pPlayerScore = nullptr;

	//delete m_pTopScore;
	//m_pTopScore = nullptr;
}

void StartMenu::ChangeSelectedMode(int change)
{
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	m_pCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

int StartMenu::SelectedMode()
{
    return mSelectedMode;
}

void StartMenu::Update()
{
	if (m_pInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
		ChangeSelectedMode(1);
	}
	else if (m_pInputManager->KeyPressed(SDL_SCANCODE_UP)) {
		ChangeSelectedMode(-1);
	}

	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		m_pRocks[i]->Update();
	}

	for (int a = 0; a < MAX_SMALLASTEROIDS1; a++) {
		m_pSmallRocks1[a]->Update();
	}

	for (int b = 0; b < MAX_SMALLASTEROIDS2; b++) {
		m_pSmallRocks2[b]->Update();
	}

	for (int c = 0; c < MAX_SMALLASTEROIDS3; c++) {
		m_pSmallRocks3[c]->Update();
	}

	for (int d = 0; d < MAX_SMALLASTEROIDS4; d++) {
		m_pSmallRocks4[d]->Update();
	}
}

void StartMenu::Render()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		m_pRocks[i]->Render();
	}

	for (int a = 0; a < MAX_SMALLASTEROIDS1; a++) {
		m_pSmallRocks1[a]->Render();
	}

	for (int b = 0; b < MAX_SMALLASTEROIDS2; b++) {
		m_pSmallRocks2[b]->Render();
	}
	
	for (int c = 0; c < MAX_SMALLASTEROIDS3; c++) {
		m_pSmallRocks3[c]->Render();
	}

	for (int d = 0; d < MAX_SMALLASTEROIDS4; d++) {
		m_pSmallRocks4[d]->Render();
	}

	/*m_pPlayer->Render();
	m_pHighScore->Render();*/
	m_pPlayGame->Render();
	m_pHighScoreMenu->Render();
	m_pCursor->Render();
	m_pAtari->Render();
	m_pDates->Render();
	m_pRights->Render();
	m_pLogo->Render();
}