#include "PlayScreen.h"

PlayScreen::PlayScreen()
{

	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pPlayGameBar = new PlayGameBar();
	m_pPlayGameBar->Parent(this);
	m_pPlayGameBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);


	mAsteroidCount = 0;
	mSmallAsteroidCount = 0;
	mUFOCount = 0;

	//BigAsteroid.insert(BigAsteroid.begin() + 5, new AsteroidPlay);
	//m_pBigAsteroid.erase(m_pBigAsteroid.begin() + 5);
	//m_pBigAsteroid.pop_back();

}

void PlayScreen::StartnewGame()
{
	mGameStarted = true;
	mAsteroidDelay = 1.0f;
	mAsteroidTimer = 0.0f;
}

void PlayScreen::GenNewAsteroid()
{
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P) && mAsteroidCount < MAX_ASTEROIDS) {
		m_pBigAsteroid.push_back(new AsteroidPlay(0, mAsteroidCount++));
	}
	
}

void PlayScreen::GenNewUFO()
{
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O)/* && mUFOCount <= MAX_UFO*/) {
		/*m_pEnemy.push_back(new Enemy);*/
		/*mUFOCount += 1;*/
	}
}

void PlayScreen::WasDestroyed()
{/*
	mAsteroidTimer += m_pTimer->DeltaTime();*/
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_L) && mAsteroidCount > 0) {
		for (auto e : m_pBigAsteroid) {
			m_pBigAsteroid.pop_back();
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

PlayScreen::~PlayScreen()
		{
			m_pTimer = nullptr;

			delete m_pPlayGameBar;
			m_pPlayGameBar = nullptr;


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

		void PlayScreen::Update()
		{
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

			GenNewAsteroid();
			GenNewUFO();
			WasDestroyed();

		}

		void PlayScreen::Render()
		{

			for (auto e : m_pBigAsteroid) {
				e->Render();
				/*	for (int i = 0; i < MAX_SMALLASTEROIDS; i++) {
					m_pSmallAsteroid[i]->Render();
				}*/
			}
			for (auto f : m_pSmallAsteroid) {
				f->Render();
			}
			for (auto g : m_pEnemy) {
				g->Render();
			}
			m_pPlayGameBar->Render();
		}

