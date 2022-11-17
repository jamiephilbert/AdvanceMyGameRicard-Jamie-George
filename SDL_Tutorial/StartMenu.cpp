#include "StartMenu.h"

StartMenu::StartMenu() {
	m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	m_pHiScore = new Texture("Hi Score", "ARCADE.TTF", 18, { 230, 230, 230 });
}