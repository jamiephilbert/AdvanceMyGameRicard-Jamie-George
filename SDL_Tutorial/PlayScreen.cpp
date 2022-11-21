#include "PlayScreen.h"

PlayScreen::PlayScreen()
{


	m_pPlayMenuBar = new PlayMenuBar();
	m_pPlayMenuBar->Parent(this);
	m_pPlayMenuBar->Position(Graphics::SCREEN_WIDTH * 0.05f, Graphics::SCREEN_HEIGHT * 0.05f);
}

PlayScreen::~PlayScreen()
{
	delete m_pPlayMenuBar;
	m_pPlayMenuBar = nullptr;
}

void PlayScreen::Update()
{
	m_pPlayMenuBar->Update();
}

void PlayScreen::Render()
{
	m_pPlayMenuBar->Render();
}
