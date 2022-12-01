#include "PlayGameBar.h"

PlayGameBar::PlayGameBar()
{
	m_pHighLabel = new Texture("HIGH SCORE", "Starzone.ttf", 30, { 255,180,0 });
	m_pHighLabel->Parent(this);
	m_pHighLabel->Position(50.0f, 0.0f);

	m_pLivesLabel = new Texture("LIVES", "Starzone.ttf", 30, { 255,180,0 });
	m_pLivesLabel->Parent(this);
	m_pLivesLabel->Position(1500.0f, 0.0f);

	m_pYourLabel = new Texture("SCORE", "Starzone.ttf", 30, { 255,180,0 });
	m_pYourLabel->Parent(this);
	m_pYourLabel->Position(1700.0f, 0.0f);

	m_pHighScoreBoard = new Scoreboard();
	m_pHighScoreBoard->Parent(this);
	m_pHighScoreBoard->Position(150.0f, 30.0f);

	m_pPlayerBoard = new Scoreboard();
	m_pPlayerBoard->Parent(this);
	m_pPlayerBoard->Position(1750.0f, 30.0f);


	m_pShips = new GameEntity();
	m_pShips->Parent(m_pLivesLabel);
	m_pShips->Position(0.0f, -0.5f);

	for (int i = 0; i < MAX_SHIP_TEXTURES; i++) {
		m_pShipTextures[i] = new Texture("RedShip.png", 0, 0, 22, 30);
		m_pShipTextures[i]->Parent(m_pShips);
		m_pShipTextures[i]->Position(62.0f * (i % 3), 70.0f * (i / 3));
	}

	m_pTotalShipsLabel = new Scoreboard();
	m_pTotalShipsLabel->Parent(this);
	m_pTotalShipsLabel->Position(140.0f, 80.0f);

	
	
}

PlayGameBar::~PlayGameBar()
{

	delete m_pHighLabel;
	m_pHighLabel = nullptr;

	delete m_pLivesLabel;
	m_pLivesLabel = nullptr;

	delete m_pYourLabel;
	m_pYourLabel = nullptr;

	delete m_pHighScoreBoard;
	m_pHighScoreBoard = nullptr;

	delete m_pPlayerBoard;
	m_pPlayerBoard = nullptr;

	delete m_pShips;
	m_pShips = nullptr;

	for (int i = 0; i < MAX_SHIP_TEXTURES; i++) {
		delete m_pShipTextures[i];
		m_pShipTextures[i] = nullptr;
	}

	delete m_pTotalShipsLabel;
	m_pTotalShipsLabel = nullptr;
}

void PlayGameBar::SetHighScore(int score)
{
	m_pHighScoreBoard->Score(score);
}

void PlayGameBar::SetPlayerScore(int score)
{
	m_pPlayerBoard->Score(score);
}

void PlayGameBar::SetShips(int ships)
{
	mTotalShips = ships;

	if (ships > MAX_SHIP_TEXTURES) {
		m_pTotalShipsLabel->Score(ships);
	}
}

void PlayGameBar::Update()
{
	
}

void PlayGameBar::Render()
{
	m_pHighLabel->Render();
	m_pLivesLabel->Render();

	for (int i = 0; i < MAX_SHIP_TEXTURES && i < mTotalShips; i++) {
		m_pShipTextures[i]->Render();
	}

	if (mTotalShips > MAX_SHIP_TEXTURES) {
		m_pTotalShipsLabel->Render();
	}
	m_pYourLabel->Render();
	m_pHighScoreBoard->Render();
	m_pPlayerBoard->Render();
}
