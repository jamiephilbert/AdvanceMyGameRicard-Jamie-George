#ifndef _STARTMENU_H
#define _STARTMENU_H
#include "AnimatedTextures.h"

using namespace SDLFramework;

class StartMenu :public GameEntity {
private:
	Texture* m_pTopBar;
	Texture* m_pHiScore;

public:
	StartMenu();
	~StartMenu();

	void Update() override;
	void Render() override;
};
#endif // !_STARTMENU_H

