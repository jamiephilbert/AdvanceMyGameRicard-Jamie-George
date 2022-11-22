#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "GameEntity.h"
#include "AssetManager.h"

namespace SDLFramework {
	class Texture : public GameEntity
	{
	private:

		

	protected:
		SDL_Rect m_pRenderRect;
		SDL_Texture* m_pTex;
		Graphics* m_pGraphics;

		int mWidth;
		int mHeight;

		bool mClipped;
		SDL_Rect mSourceRect;
		SDL_Rect mDestinationRect;

	public:
		Texture(std::string filename);
		Texture(std::string filename, bool managed = false);	// <--------Full image
		Texture(std::string filename, int x, int y, int w, int h, bool managed = false); // <--Sliced image(no animation)
		Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);	// <----Fonts
		~Texture();

		Vector2 ScaledDimenstion();
		void SetSourceRect(SDL_Rect* sourceRect);
		void Render();
	};

}
#endif // !_TEXTURE_H