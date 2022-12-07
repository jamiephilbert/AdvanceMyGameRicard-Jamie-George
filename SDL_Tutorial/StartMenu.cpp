#include "StartMenu.h"

StartMenu::StartMenu()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

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

	//Background Entities
	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		m_pRocks[i] = new AsteroidRock();
		if (i > 7) {
			m_pSmallRocks[i] = new SmallAsteroidRock();
		}
		else if (i > 5)
		{
			m_pSmallRocks[i] = new SmallAsteroidRock();
		}
		else if (i > 3)
		{
			m_pSmallRocks[i] = new SmallAsteroidRock();
		}
		else {
			m_pSmallRocks[i] = new SmallAsteroidRock();
		}
	}
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

	//// Play Mode Entities
	m_pPlayGame->Position(0.0f, -35.0f);
	m_pHighScoreMenu->Position(0.0f, 35.0f);
	m_pCursor->Position(-230.f, -25.9f);
	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;

	//// Bottom Bar Entities
	m_pAtari->Position(Vec2_Zero);
	m_pDates->Position(0.0f, 90.0f);
	m_pRights->Position(0.0f, 170.0f);

}

StartMenu::~StartMenu()
{

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
		delete m_pSmallRocks[i];
		m_pRocks[i] = nullptr;
		m_pSmallRocks[i] = nullptr;
	}

	delete m_pHighScoreMenu;
	m_pHighScoreMenu = nullptr;

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
		m_pSmallRocks[i]->Update();
	}
}

void StartMenu::Render()
{
	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		m_pRocks[i]->Render();
		m_pSmallRocks[i]->Render();
	}

	m_pPlayGame->Render();
	m_pHighScoreMenu->Render();
	m_pCursor->Render();
	m_pAtari->Render();
	m_pDates->Render();
	m_pRights->Render();
	m_pLogo->Render();
}