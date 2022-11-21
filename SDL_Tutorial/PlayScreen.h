#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AsteroidRock.h"
#include "PlayMenuBar.h"

class PlayScreen : public GameEntity
{
private:

	PlayMenuBar* m_pPlayMenuBar;
public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H