#include "Game.h"

void Game::StartGame() {
	mGameStarted = true;
}

Game::Game(int stage, PlayGameBar* gamebar, Player* player) {
	m_pTimer = Timer::Instance();
	m_pGameBar = gamebar;
	m_pGameBar->SetGame(stage);

	mGame = stage;
	mGameStarted = false;

	mLabelTimer = 0.0f;

	m_pGameLabel = new Texture("STAGE", "emulogic.ttf", 32, { 75, 75, 200 });
	m_pGameLabel->Parent(this);
	m_pGameLabel->Position(Graphics::SCREEN_WIDTH * 0.35f, Graphics::SCREEN_HEIGHT * 0.5f);

	//m_pStageNumber = new Scoreboard({ 75,75,200 });
	//m_pStageNumber->Score(mStage);
	//m_pStageNumber->Parent(this);
	//m_pStageNumber->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameLabelOnScreen = 0.0f;
	mGameLabelOffScreen = 1.5f;

	m_pReadyLabel = new Texture("READY", "emulogic.ttf", 32, { 150,0,0 });
	m_pReadyLabel->Parent(this);
	m_pGameLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mReadyLabelOnScreen = mGameLabelOffScreen;
	mReadyLabelOffScreen = mReadyLabelOnScreen + 3.0f;

	m_pPlayer = player;

	mPlayerHit = false;
	mRespawnDelay = 3.0f;
	mRespawnTimer = 0.0f;
	mRespawnLabelOnScreen = 2.0f;

	m_pGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, { 150,0,0 });
	m_pGameOverLabel->Parent(this);
	m_pGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;

	//m_pEnemy = new Enemy(0);
}

Game::~Game() {
	m_pTimer = nullptr;
	m_pGameBar = nullptr;
	m_pPlayer = nullptr;

	delete m_pGameOverLabel;
	m_pGameOverLabel = nullptr;

	delete m_pGameLabel;
	m_pGameLabel = nullptr;

	delete m_pGameNumber;
	m_pGameNumber = nullptr;

	delete m_pReadyLabel;
	m_pReadyLabel = nullptr;

	//delete m_pEnemy;
	//m_pEnemy = nullptr;
}

Game::GameState Game::State() {
	return mCurrentState;
}

void Game::HandleStartLabels() {
	mLabelTimer += m_pTimer->DeltaTime();
	if (mLabelTimer >= mGameLabelOffScreen) {
		if (mGame > 1) {
			StartGame();
		}
		else {
			if (mLabelTimer >= mReadyLabelOffScreen) {
				StartGame();
				m_pPlayer->Active(true);
				m_pPlayer->Visible(true);
			}
		}
	}
}

void Game::HandleCollisions() {
	if (!Game::mPlayerHit) {
		if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			m_pPlayer->WasHit();
			m_pGameBar->SetShips(m_pPlayer->Lives());

			mPlayerHit = true;
			mRespawnTimer = 0.0f;
			m_pPlayer->Active(false);
		}
	}
}

void Game::HandlePlayerDeath() {
	if (!m_pPlayer->IsAnimating()) {
		if (m_pPlayer->Lives() > 0) {
			// Respawning the player
			if (mRespawnTimer == 0.0f) {
				m_pPlayer->Visible(false);
			}

			mRespawnTimer += m_pTimer->DeltaTime();
			if (mRespawnTimer >= mRespawnDelay) {
				m_pPlayer->Active(true);
				m_pPlayer->Visible(true);
				mPlayerHit = false;
			}
		}
		else {
			// GameOver
			if (mGameOverTimer == 0.0f) {
				m_pPlayer->Visible(false);
			}

			mGameOverTimer += m_pTimer->DeltaTime();

			if (mGameOverTimer >= mGameOverDelay) {
				mCurrentState = GameOver;
			}
		}
	}
}

void Game::Update() {
	if (!mGameStarted) {
		HandleStartLabels();
	}
	else {
		//m_pEnemy->Update();
		m_pGameBar->Update();

		HandleCollisions();

		if (mPlayerHit) {
			HandlePlayerDeath();
		}
		else {
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				mCurrentState = Finished;
			}
		}
	}
}

void Game::Render() {
	if (!mGameStarted) {
		if (mLabelTimer > mGameLabelOnScreen && mLabelTimer < mGameLabelOffScreen) {
			m_pGameLabel->Render();
			m_pGameNumber->Render();
		}
		else if (mLabelTimer > mReadyLabelOnScreen && mLabelTimer < mReadyLabelOffScreen) {
			m_pReadyLabel->Render();
		}
	}
	else {
		//m_pEnemy->Render();
		if (mPlayerHit) {
			if (mRespawnTimer >= mRespawnLabelOnScreen) {
				m_pReadyLabel->Render();
			}

			if (mGameOverTimer >= mGameOverLabelOnScreen) {
				m_pGameOverLabel->Render();
			}
		}
	}
}
