#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	m_pPlayGameBar = new PlayGameBar();
	m_pPlayGameBar->Parent(this);
	m_pPlayGameBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);
	

	for (int i = 0; i < MAX_ASTEROIDZ; i++) {
		m_pBigAsteroid[i] = new AsteroidPlay();
		if (i > 7) {
			m_pSmallAsteroid[i] = new SmallAsteroidRock("SmallAsteroidRock1.png");
		}
		else if (i > 5)
		{

			m_pSmallAsteroid[i] = new SmallAsteroidRock("SmallAsteroidRock3.png");
		}
		else if (i > 3) {
			m_pSmallAsteroid[i] = new SmallAsteroidRock("SmallAsteroidRock2.png");
		}
		else {
			m_pSmallAsteroid[i] = new SmallAsteroidRock("SmallAsteroidRock4.png");
		}
	}

}

PlayScreen::~PlayScreen()
{
	delete m_pPlayGameBar;
	m_pPlayGameBar = nullptr;


		m_pTimer = nullptr;

		for (int i = 0; i < MAX_ASTEROIDZ; i++) {
			delete m_pBigAsteroid[i];
			delete m_pSmallAsteroid[i];
			m_pBigAsteroid[i] = nullptr;
			m_pSmallAsteroid[i] = nullptr;
		}
}

void PlayScreen::Update()
{
	m_pPlayGameBar->Update();

	for (int i = 0; i < MAX_ASTEROIDZ; i++) {
		m_pBigAsteroid[i]->Update();
		m_pSmallAsteroid[i]->Update();
	}

}

void PlayScreen::Render()
{
	for (int i = 0; i < MAX_ASTEROIDZ; i++) {
		m_pBigAsteroid[i]->Render();
		m_pSmallAsteroid[i]->Render();
	}
	
	m_pPlayGameBar->Render();
}
