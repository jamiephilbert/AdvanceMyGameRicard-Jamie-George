#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"
#include "AnimatedTextures.h"
#include "InputManager.h"
#include "AudioManager.h"

namespace SDLFramework {
	class GameManager
	{
	private:
		const int FRAME_RATE = 60;

	private:
		static GameManager* sInstance;
		bool mQuit;
		Graphics* m_pGraphics;
		AssetManager* m_pAssetManager;
		Texture* m_pTexture;
		SDL_Event mEvent;
		Timer* m_pTimer;
		GameEntity* mParent;
		GameEntity* mChild;
		InputManager* m_pInputManager;
		Texture* mTextTwo;
		Texture* m_pFontTex;
		AudioManager* m_pAudioManager;

	public:
		static GameManager* Instance();
		static void Release();

		void Run();
		void Update();
		void LateUpdate();
		void Render();

		GameManager();
		~GameManager();
	};
}
#endif 