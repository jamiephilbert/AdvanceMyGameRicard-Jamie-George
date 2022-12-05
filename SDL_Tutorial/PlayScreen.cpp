#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();
	m_pInputManager = InputManager::Instance();

	m_pPlayGameBar = new PlayGameBar();
	m_pPlayGameBar->Parent(this);
	m_pPlayGameBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);

	m_pStartLabel = new Texture("START", "Starzone.ttf", 30, { 255,180,0 });
	m_pStartLabel->Parent(this);
	m_pStartLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	m_pPlayer = new Player();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mAsteroidCount = 0;
	mSmallAsteroidCount = 0;
	mUFOCount = 0;

	m_pGame = nullptr;
	mGameStarted = false;
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

	delete m_pPlayer;
	m_pPlayer = nullptr;

	for (auto e : m_pBigAsteroid) {
		delete e;
	}

	m_pBigAsteroid.clear();

	for (auto f : m_pSmallAsteroid) {
		delete f;
	}
	m_pSmallAsteroid.clear();

	for (auto g : m_pEnemy) {
		delete g;
	}
	m_pEnemy.clear();
}

void PlayScreen::StartNewGame()
{
	mGameStarted = true;
	mAsteroidDelay = 1.0f;
	mAsteroidTimer = 0.0f;
	delete m_pPlayer;
	m_pPlayer = new Player();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	m_pPlayer->Active(false);

	m_pPlayGameBar->SetHighScore(197672);
	m_pPlayGameBar->SetShips(m_pPlayer->Lives());
	m_pPlayGameBar->SetPlayerScore(m_pPlayer->Score());

	mGameStartTimer = 0.0f;

	

}

bool PlayScreen::GameOver()
{
	return false;
}

void PlayScreen::Update()
{
	m_pPlayGameBar->Update();
	m_pPlayer->Update();

	m_pPlayGameBar->Update();
	for (auto e : m_pBigAsteroid) {
		e->Update();
	}
	for (auto f : m_pSmallAsteroid) {
		f->Update();
	}
	for (auto g : m_pEnemy) {
		g->Update();
	}

	StartNewGame();
	GenNewAsteroid();
	GenNewUFO();
	WasDestroyed();
}

void PlayScreen::Render()
{
	m_pPlayGameBar->Render();
	m_pPlayer->Render();

	
	for (auto e : m_pBigAsteroid) {
		e->Render();
	}
	for (auto f : m_pSmallAsteroid) {
		f->Render();
	}
	for (auto g : m_pEnemy) {
		g->Render();
	}
	m_pPlayGameBar->Render();

	//BigAsteroid.insert(BigAsteroid.begin() + 5, new AsteroidPlay);
	//m_pBigAsteroid.erase(m_pBigAsteroid.begin() + 5);
	//m_pBigAsteroid.pop_back();

}

void PlayScreen::GenNewAsteroid()
{
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P) && mAsteroidCount < MAX_ASTEROIDS) {
		m_pBigAsteroid.push_back(new AsteroidPlay(0, mAsteroidCount++));
	}
	
}

void PlayScreen::GenNewUFO()
{
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I) && mUFOCount < MAX_UFO) {
		m_pEnemy.push_back(new Enemy);
		mUFOCount += 1;
		
	
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_J)) {
		m_pEnemy.pop_back();
		mUFOCount = 0;
	}
}

void PlayScreen::WasDestroyed()
{/*
	mAsteroidTimer += m_pTimer->DeltaTime();*/
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O) && mAsteroidCount > 0) {
		for (auto e : m_pBigAsteroid) {
			m_pBigAsteroid.pop_back();
			m_pPlayer->AddScore(500);
			mAsteroidCount = 0;
			if (mSmallAsteroidCount < MAX_SMALLASTEROIDS) {
				m_pSmallAsteroid.push_back(new SmallAsteroidRock("SmallAsteroidRock3.png"));
				m_pSmallAsteroid.push_back(new SmallAsteroidRock("SmallAsteroidRock1.png"));
				mSmallAsteroidCount += 2;
			}
		}
	}
	if(InputManager::Instance()->KeyPressed(SDL_SCANCODE_K) && mSmallAsteroidCount > 0) {
			for (auto f : m_pSmallAsteroid) {
				mSmallAsteroidCount -= 1;
				m_pSmallAsteroid.pop_back();

			}
	}
	
}