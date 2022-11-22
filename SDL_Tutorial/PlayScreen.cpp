#include "PlayScreen.h"

PlayScreen::PlayScreen()
{


	m_pPlayGameBar = new PlayGameBar();
	m_pPlayGameBar->Parent(this);
	m_pPlayGameBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);
}

PlayScreen::~PlayScreen()
{
	delete m_pPlayGameBar;
	m_pPlayGameBar = nullptr;
}

void PlayScreen::Update()
{
	m_pPlayGameBar->Update();
}

void PlayScreen::Render()
{
	m_pPlayGameBar->Render();
}
