#include "Texture.h"

namespace SDLFramework {
	Texture::Texture(std::string filename) {

		m_pGraphics = Graphics::Instance();

		m_pTex = AssetManager::Instance()->GetTexture(filename);

		SDL_QueryTexture(m_pTex, nullptr, nullptr, &mWidth, &mHeight);

		m_pRenderRect.w = mWidth;
		m_pRenderRect.h = mHeight;
	}

	Texture::Texture(std::string filename, bool managed) {
		m_pGraphics = Graphics::Instance(); // <- using the Graphics singleton to grab the Graphics object

		m_pTex = AssetManager::Instance()->GetTexture(filename, managed);
		SDL_QueryTexture(m_pTex, nullptr, nullptr, &mWidth, &mHeight);

		mClipped = false;
		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;
	}

	Texture::Texture(std::string filename, int x, int y, int w, int h, bool managed) {
		m_pGraphics = Graphics::Instance();
		m_pTex = AssetManager::Instance()->GetTexture(filename, managed);

		mWidth = w;
		mHeight = h;

		mClipped = true;
		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;

		mSourceRect.x = x;
		mSourceRect.y = y;
		mSourceRect.w = mWidth;
		mSourceRect.h = mHeight;
	}

	Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed) {
		m_pGraphics = Graphics::Instance();
		m_pTex = AssetManager::Instance()->GetText(text, fontPath, size, color, managed);
		mClipped = false;

		SDL_QueryTexture(m_pTex, nullptr, nullptr, &mWidth, &mHeight);

		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;
	}

	Texture::~Texture() {
		AssetManager::Instance()->DestroyTexture(m_pTex);
		m_pTex = nullptr;
		m_pGraphics = nullptr;
	}

	Vector2 Texture::ScaledDimensions() {
		Vector2 scaledDimensions = Scale();
		scaledDimensions.x* mWidth;
		scaledDimensions.y *= mHeight;

		return scaledDimensions;
	}

	void Texture::SetSourceRect(SDL_Rect* sourceRect) {
		mSourceRect = *sourceRect;
	}

	void Texture::Render() {
		Vector2 position = Position(World);
		m_pRenderRect.x = (int)(position.x - mWidth * 0.5);
		m_pRenderRect.y = (int)(position.y - mHeight * 0.5);

		//m_pGraphics->DrawTexture(m_pTex, &m_pRenderRect);

		Vector2 pos = Position(World);
		Vector2 scale = Scale(World);
		mDestinationRect.x = (int)(pos.x - mWidth * 0.5f);
		mDestinationRect.y = (int)(pos.y - mHeight * 0.5f);
		mDestinationRect.w = (int)(mWidth * scale.x);
		mDestinationRect.h = (int)(mHeight * scale.y);

		m_pGraphics->DrawTexture(m_pTex, &m_pRenderRect, mClipped ? &mSourceRect : nullptr, &mDestinationRect, Rotation(World));
	}
}