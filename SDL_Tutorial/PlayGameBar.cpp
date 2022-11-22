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
	m_pHighScoreBoard->Score(19721979);

	m_pPlayerBoard = new Scoreboard();
	m_pPlayerBoard->Parent(this);
	m_pPlayerBoard->Position(1750.0f, 30.0f);

	m_pShipLives = new Texture("RedShip.png", 0, 0, 23, 31);
	m_pShipLives->Parent(m_pLivesLabel);
	m_pShipLives->Position(0.0f, 30.0f);

	m_pShipLives2 = new Texture("RedShip.png", 0, 0, 23, 31);
	m_pShipLives2->Parent(m_pLivesLabel);
	m_pShipLives2->Position(30.0f, 30.0f);

	m_pShipLives3 = new Texture("RedShip.png", 0, 0, 23, 31);
	m_pShipLives3->Parent(m_pLivesLabel);
	m_pShipLives3->Position(-30.0f, 30.0f);

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

	delete m_pShipLives;
	m_pShipLives = nullptr;

	delete m_pShipLives2;
	m_pShipLives2 = nullptr;

	delete m_pShipLives3;
	m_pShipLives3 = nullptr;
}

void PlayGameBar::Update()
{
	
}

void PlayGameBar::Render()
{
	m_pHighLabel->Render();
	m_pLivesLabel->Render();
	m_pShipLives->Render();
	m_pShipLives2->Render();
	m_pShipLives3->Render();
	m_pYourLabel->Render();
	m_pHighScoreBoard->Render();
	m_pPlayerBoard->Render();
}
