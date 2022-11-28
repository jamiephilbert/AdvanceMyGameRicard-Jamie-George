#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance()
{
    if (sInstance == nullptr) {
        sInstance = new ScreenManager();
    }
    return sInstance;
}

void ScreenManager::Release()
{
    delete sInstance;
    sInstance = nullptr;
}

ScreenManager::ScreenManager()
{
    m_pInput = InputManager::Instance();
    m_pStartScreen = new StartMenu();
    m_pPlayScreen = new PlayScreen();
    m_pHighScoreScreen = new HighScoreScreen();
    ScreenChoice = 0;

    mCurrentScreen = Start;
}

ScreenManager::~ScreenManager()
{
    m_pInput = nullptr;


    delete m_pStartScreen;
    m_pStartScreen = nullptr;

    delete m_pPlayScreen;
    m_pPlayScreen = nullptr;

    delete m_pHighScoreScreen;
    m_pHighScoreScreen = nullptr;
}

void ScreenManager::Update()
{

    switch (mCurrentScreen) {
    case Start:
        m_pStartScreen->Update();


        if (m_pInput->KeyPressed(SDL_SCANCODE_DOWN)) {
            ScreenChoice -= 1;
        }
        if (m_pInput->KeyPressed(SDL_SCANCODE_UP)) {
            ScreenChoice += 1;
        }
        if (ScreenChoice < 0) {
            ScreenChoice = 1;
        }
        else if (ScreenChoice > 1) {
            ScreenChoice = 0;
        }

        if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN) && ScreenChoice == 0) {

            mCurrentScreen = Play;
        }

        if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN) && ScreenChoice == 1) {

            mCurrentScreen = High;
        }
        break;

    case Play:
        m_pPlayScreen->Update();
        break;

    case High:
        if (m_pInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            mCurrentScreen = Start;
        }
        break;
    }
}

void ScreenManager::Render()
{

    switch (mCurrentScreen) {
    case Start:
        m_pStartScreen->Render();
        break;

    case Play:
        m_pPlayScreen->Render();
        break;

    case High:
        m_pHighScoreScreen->Render();
        break;
    }

}