#ifndef _STARTMENU_H
#define _STARTMENU_H
#include "AnimatedTextures.h"

using namespace SDLFramework;

class StartMenu :public GameEntity {
private:
	GameEntity* m_pTopBar;
	Texture* m_pHighScore;

public:
	StartMenu();
	~StartMenu();

	void Update() override;
	void Render() override;
};
#endif // !_STARTMENU_H

