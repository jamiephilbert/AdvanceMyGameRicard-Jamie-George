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
		//m_pTexture->Update();
		//This is how we check which key is pressed on the keyboard or mouse
		//Try to remember how this works!!!!!!!!!
		/*if (m_pInputManager->KeyDown(SDL_SCANCODE_W)) {
			m_pTexture->Translate(Vector2(0, -100.0f) * m_pTimer->DeltaTime(), GameEntity::World);
		}
		if (m_pInputManager->KeyDown(SDL_SCANCODE_S)) {
			m_pTexture->Translate(Vector2(0, 100.0f) * m_pTimer->DeltaTime(), GameEntity::World);
		}
		if (m_pInputManager->KeyDown(SDL_SCANCODE_A)) {
			m_pTexture->Translate(Vector2(-150.0, 0.0f) * m_pTimer->DeltaTime(), GameEntity::World);
		}
		if (m_pInputManager->KeyDown(SDL_SCANCODE_D)) {
			m_pTexture->Translate(Vector2(150.0, 0.0f) * m_pTimer->DeltaTime(), GameEntity::World);
		}

		if (m_pInputManager->KeyDown(SDL_SCANCODE_SPACE)) {
			m_pTexture->Rotate(5.0f);
		}
		else if (m_pInputManager->KeyDown(SDL_SCANCODE_LSHIFT)) {
			m_pTexture->Rotate(-5.0f);
		}

		if (m_pInputManager->KeyPressed(SDL_SCANCODE_SPACE)) {
			std::cout << "Space pressed!" << std::endl;
		}

		if (m_pInputManager->KeyReleased(SDL_SCANCODE_SPACE)) {
			std::cout << "Space released!" << std::endl;
		}

		if (m_pInputManager->MouseButtonPressed(InputManager::Left)) {
			std::cout << "Left mouse button pressed!" << std::endl;
		}

		if (m_pInputManager->MouseButtonReleased(InputManager::Left)) {
			std::cout << "Left mouse button released!" << std::endl;
		}

		if (m_pInputManager->KeyDown(SDL_SCANCODE_1)) {
			m_pAudioManager->PlaySFX("SFX/coin_credit.wav", 0, 0);
		}*/

		/*std::cout << "Delta time: " << m_pTimer->DeltaTime() << std::endl;*/
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

		//m_pTex = new Texture("AsteroidsSpriteSheet.png");
		//m_pTex->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5));
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