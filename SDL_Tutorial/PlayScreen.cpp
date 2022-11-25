#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	m_pPlayGameBar = new PlayGameBar();
	m_pPlayGameBar->Parent(this);
	m_pPlayGameBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_pStartLabel = new Texture("START", "Starzone.ttf", 30, { 255,180,0 });
	m_pStartLabel->Parent(this);
	m_pStartLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pGame = nullptr;
	mGameStarted = false;

	//m_pPlayer = nullptr;
}

PlayScreen::~PlayScreen()
{
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pPlayGameBar;
	m_pPlayGameBar = nullptr;

	delete m_pStartLabel;
	m_pStartLabel = nullptr;

	delete m_pGame;
	m_pGame = nullptr;

	//delete m_pPlayer;
	//m_pPlayer = nullptr;
}

void PlayScreen::StartNewGame()
{
	//delete m_pPlayer;
	//m_pPlayer = new Player();
	//m_pPlayer->Parent(this);
	//m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	//m_pPlayer->Active(false);

	//m_pPlayGameBar->HighestScore(30000);
	//m_pPlayGameBar->SetShips(m_pPlayer->Lives());
	//m_pPlayGameBar->PlayerScore(m_pPlayer->Score());
	//m_pPlayGameBar->SetLevel(0);

	mGameStarted = false;
	mGameStartTimer = 0.0f;
	m_pAudio->PlayMusic("MUS/GameStart.wav", 0);
}

bool PlayScreen::GameOver()
{
	return false;
}

void PlayScreen::Update()
{
	m_pPlayGameBar->Update();
}

void PlayScreen::Render()
{
	m_pPlayGameBar->Render();
}
