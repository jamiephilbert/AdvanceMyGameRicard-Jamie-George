#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include "StartMenu.h"
#include "HighScoreScreen.h"
class ScreenManager
{
private:
	static ScreenManager* sInstance;
public:
	static ScreenManager* Instance();
	static void Release();

private:
	ScreenManager();
	~ScreenManager();
private:
	enum Screens { Start, Play, High };
	Screens mCurrentScreen;
	InputManager* m_pInput;
	StartMenu* m_pStartScreen;
	ScreenManager* m_pScreenManager;
	PlayScreen* m_pPlayScreen;
	HighScoreScreen* m_pHighScoreScreen;

	int ScreenChoice;

public:
	void Update();
	void Render();
};


#endif // !_SCREENMANAGER_H