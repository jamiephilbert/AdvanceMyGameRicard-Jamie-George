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
		//std::cout << "Delta time: " << m_pTimer->DeltaTime() << std::endl;
		/*mTextTwo->Update();*/
		m_pInputManager->Update();
		m_pTexture->Update();
		if (m_pInputManager->KeyDown(SDL_SCANCODE_W)) {
			m_pTexture->Translate(Vector2(0, -40.f) * m_pTimer->DeltaTime(), GameEntity::World);
		}
		else if (m_pInputManager->KeyDown(SDL_SCANCODE_S)) {
			m_pTexture->Translate(Vector2(0, 40.f) * m_pTimer->DeltaTime(), GameEntity::World);
		}

		if (m_pInputManager->KeyDown(SDL_SCANCODE_A)) {
			m_pTexture->Translate(Vector2(-40.f, 0) * m_pTimer->DeltaTime(), GameEntity::World);
		}
		else if (m_pInputManager->KeyDown(SDL_SCANCODE_D)) {
			m_pTexture->Translate(Vector2(40.f, 0) * m_pTimer->DeltaTime(), GameEntity::World);
		}

		/*if (m_pInputManager->KeyPressed(SDL_SCANCODE_E)) {
			m_pTexture->Rotate(20.0f);
		}*/
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
			std::cout << "Left mouse button Released!" << std::endl;
		}

		if (m_pInputManager->KeyDown(SDL_SCANCODE_1)) {
			m_pAudioManager->PlaySFX("SFX/coin_credit.wav", 0, 0);
		}
	}
	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
	}

	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer(); // call this one first
		m_pFontTex->Render();
		m_pTexture->Render();
		/*mTextTwo->Render();*/
		m_pGraphics->Render(); //call this one last
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

		m_pTexture = new AnimatedTextures("GalagaSpriteSheet.png", 204,45,40,38,4,0.5f, AnimatedTextures::Horizontal); //1st is the position left to right. 2nd is the position up and down.3rd is the width. 4th is the height.
		/*mTextTwo = new AnimatedTextures("GalagaSpriteSheet.png", 182,71,20,33,1,0.5f, AnimatedTextures::Horizontal); */    //5th is the number of pictures shown.6th is the smoothness in which its displayed
		/*mTextTwo->Position(Vector2(Graphics::SCREEN_WIDTH * 0.8f,
			Graphics::SCREEN_HEIGHT * 0.8f));*/
		m_pTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f,
			Graphics::SCREEN_HEIGHT * 0.5f));
		//mParent = new GameEntity(100.0f, 400.0f);
		//mChild = new GameEntity(100.0f, 500.0f);

		////print local position of mChild with no parent set
		//printf("Child local pos: (%f, %f)\n",
		//	mChild->Position(GameEntity::Local).x,
		//	mChild->Position(GameEntity::Local).y);

		////Set parent of mChild to mParent
		//mChild->Parent(mParent);

		//printf("Child local pos: (%f, %f)\n",
		//	mChild->Position(GameEntity::Local).x,
		//	mChild->Position(GameEntity::Local).y);

		//Adding a font texture to the game window
		m_pFontTex = new Texture("Hello World!", "Arcade.TTF", 72, { 255,0,0 });
		//Setting the position for the text
		m_pFontTex->Position(Vector2(400, 200));
	}

	GameManager::~GameManager() {
		Graphics::Release();
		Timer::Release();
		m_pGraphics = nullptr;
		m_pTimer = nullptr;
		delete m_pTexture;
		m_pTexture = nullptr;
		/*mTextTwo = nullptr;*/
		AssetManager::Release();
		m_pAssetManager = nullptr;
		InputManager::Release();
		m_pInputManager = nullptr;
		delete m_pFontTex;
		m_pFontTex = nullptr;
		AudioManager::Release();
		m_pAudioManager = nullptr;

		SDL_Quit();
	}
}
