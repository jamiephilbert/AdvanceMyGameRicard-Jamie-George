#include "HighScoreScreen.h"

HighScoreScreen::HighScoreScreen()
{
	m_pLogo = new Texture("HighScore1.png", 0, 0, 576, 244);
	m_pLogo->Parent(this);
	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.21f);

	m_pScoreBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	m_pScoreBar->Parent(this);


	m_pTopScore = new Scoreboard;
	m_pTopScore->Parent(m_pScoreBar);
	m_pTopScore->Position(420.0f, 10.0f);
	m_pTopScore->Score(19721979);

	m_pSecondScore = new Scoreboard;
	m_pSecondScore->Parent(m_pScoreBar);
	m_pSecondScore->Position(420.0f, 110.0f);
	m_pSecondScore->Score(87825);

	m_pThirdScore = new Scoreboard;
	m_pThirdScore->Parent(m_pScoreBar);
	m_pThirdScore->Position(420.0f, 210.0f);
	m_pThirdScore->Score(13220);

	m_pTopScoreName = new Texture("BAD", "Starzone.ttf", 30, { 255,180,0 });
	m_pTopScoreName->Parent(m_pScoreBar);
	m_pTopScoreName->Position(-45.0f, 10.0f);

	m_pSecondScoreName = new Texture("TOM", "Starzone.ttf", 30, { 255,180,0 });
	m_pSecondScoreName->Parent(m_pScoreBar);
	m_pSecondScoreName->Position(-45.0f, 110.0f);

	m_pThirdScoreName = new Texture("END", "Starzone.ttf", 30, { 255,180,0 });
	m_pThirdScoreName->Parent(m_pScoreBar);
	m_pThirdScoreName->Position(-45.0f, 210.0f);

	m_pTopScorePos = new Texture("TOP:", "Starzone.ttf", 30, { 255,180,0 });
	m_pTopScorePos->Parent(m_pScoreBar);
	m_pTopScorePos->Position(-419.0f, 10.0f);

	m_pSecondScorePos = new Texture("2ND:", "Starzone.ttf", 30, { 255,180,0 });
	m_pSecondScorePos->Parent(m_pScoreBar);
	m_pSecondScorePos->Position(-419.0f, 110.0f);

	m_pThirdScorePos = new Texture("3RD:", "Starzone.ttf", 30, { 255,180,0 });
	m_pThirdScorePos->Parent(m_pScoreBar);
	m_pThirdScorePos->Position(-419.0f, 210.0f);

	m_pPosTitle = new Texture("Position", "Starzone.ttf", 40, { 255,180,0 });
	m_pPosTitle->Parent(m_pScoreBar);
	m_pPosTitle->Position(-350.0f, -100.0f);

	m_pNameTitle = new Texture("Name", "Starzone.ttf", 40, { 255,180,0 });
	m_pNameTitle->Parent(m_pScoreBar);
	m_pNameTitle->Position(0.0f, -100.0f);

	m_pScoreTitle = new Texture("Score", "Starzone.ttf", 40, { 255,180,0 });
	m_pScoreTitle->Parent(m_pScoreBar);
	m_pScoreTitle->Position(350.0f, -100.0f);
}

HighScoreScreen::~HighScoreScreen()
{
	delete m_pScoreBar;
	m_pScoreBar = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pTopScore;
	m_pTopScore = nullptr;

	delete m_pSecondScore;
	m_pSecondScore = nullptr;

	delete m_pThirdScore;
	m_pThirdScore = nullptr;

	delete m_pTopScoreName;
	m_pTopScoreName = nullptr;

	delete m_pSecondScoreName;
	m_pSecondScoreName = nullptr;

	delete m_pThirdScoreName;
	m_pThirdScoreName = nullptr;

	delete m_pTopScorePos;
	m_pTopScorePos = nullptr;

	delete m_pSecondScorePos;
	m_pSecondScorePos = nullptr;

	delete m_pThirdScorePos;
	m_pThirdScorePos = nullptr;

	delete m_pScoreTitle;
	m_pScoreTitle = nullptr;

	delete m_pNameTitle;
	m_pNameTitle = nullptr;

	delete m_pPosTitle;
	m_pPosTitle = nullptr;
}

void HighScoreScreen::Update()
{
}

void HighScoreScreen::Render()
{

	m_pLogo->Render();
	m_pScoreBar->Render();
	m_pTopScore->Render();
	m_pSecondScore->Render();
	m_pThirdScore->Render();
	m_pTopScoreName->Render();
	m_pSecondScoreName->Render();
	m_pThirdScoreName->Render();
	m_pTopScorePos->Render();
	m_pSecondScorePos->Render();
	m_pThirdScorePos->Render();
	m_pNameTitle->Render();
	m_pPosTitle->Render();
	m_pScoreTitle->Render();
}