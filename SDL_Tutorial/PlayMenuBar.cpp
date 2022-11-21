#include "PlayMenuBar.h"

PlayMenuBar::PlayMenuBar()
{
	m_pHighLabel = new Texture("HIGH", "emulogic.ttf", 16, { 230, 230, 230 });
	m_pHighLabel->Parent(this);
	m_pHighLabel->Position(25.0f, 0.0f);

	m_pScoreLabel = new Texture("SCORE", "emulogic.ttf", 16, { 230,230,230 });
	m_pScoreLabel->Parent(this);
	m_pScoreLabel->Position(25.0f, 32.0f);

	m_pLivesLabel = new Texture("LIVES", "emulogic.ttf", 16, { 230,230,230 });
	m_pLivesLabel->Parent(this);
	m_pLivesLabel->Position(1500.0f, 0.0f);

	m_pYourLabel = new Texture("SCORE", "emulogic.ttf", 16, { 230,230,230 });
	m_pYourLabel->Parent(this);
	m_pYourLabel->Position(1700.0f, 0.0f);

	m_pHighScoreBoard = new Scoreboard();
	m_pHighScoreBoard->Parent(this);
	m_pHighScoreBoard->Position(60.0f, 60.0f);
	m_pHighScoreBoard->Score(175544);


	m_pPlayerBoard = new Scoreboard();
	m_pPlayerBoard->Parent(this);
	m_pPlayerBoard->Position(1735.0f, 40.0f);

	
}

PlayMenuBar::~PlayMenuBar()
{

	delete m_pHighLabel;
	m_pHighLabel = nullptr;

	delete m_pScoreLabel;
	m_pScoreLabel = nullptr;

	delete m_pLivesLabel;
	m_pLivesLabel = nullptr;

	delete m_pYourLabel;
	m_pYourLabel = nullptr;

	delete m_pHighScoreBoard;
	m_pHighScoreBoard = nullptr;

	delete m_pPlayerBoard;
	m_pPlayerBoard = nullptr;
}

void PlayMenuBar::Update()
{
	
}

void PlayMenuBar::Render()
{
	m_pHighLabel->Render();
	m_pScoreLabel->Render();
	m_pLivesLabel->Render();
	m_pYourLabel->Render();
	m_pHighScoreBoard->Render();
	m_pPlayerBoard->Render();
}
