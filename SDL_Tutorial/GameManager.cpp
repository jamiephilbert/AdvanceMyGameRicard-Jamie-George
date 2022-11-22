#include "GameManager.h"

namespace SDLFramework {
	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() {
		while (!mQuit) {
			m_pTimer->Update();
			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (m_pTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				m_pTimer->Reset();
				Update();
				LateUpdate();
				Render();
			}
		}
	}

	void GameManager::Update() {
		m_pInputManager->Update();
		m_pScreenManager->Update();
	}

	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
	}

	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer();	// <----- call this one first
		m_pScreenManager->Render();
		m_pGraphics->Render();	// <----- call this on last
	}

	GameManager::GameManager() : mQuit(false) {
		m_pGraphics = Graphics::Instance();
		m_pTimer = Timer::Instance();
		if (!Graphics::Initialized()) {
			mQuit = true;
		}

		m_pAssetManager = AssetManager::Instance();
		m_pInputManager = InputManager::Instance();
		m_pAudioManager = AudioManager::Instance();
		m_pScreenManager = ScreenManager::Instance();

	}

	GameManager::~GameManager() {
		Graphics::Release();
		Timer::Release();
		m_pGraphics = nullptr;
		m_pTimer = nullptr;

		AssetManager::Release();
		m_pAssetManager = nullptr;

		InputManager::Release();
		m_pInputManager = nullptr;

		AudioManager::Release();
		m_pAudioManager = nullptr;

		ScreenManager::Release();
		m_pScreenManager = nullptr;

		SDL_Quit();
	}
}