#ifndef _MINIASTEROIDROCK_H
#define _MINIASTEROIDROCK_H
#include "AsteroidRock.h"

using namespace SDLFramework;

class MiniAsteroidRockA : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	MiniAsteroidRockA();
	~MiniAsteroidRockA();

	void Update() override;
	void Render() override;
};

#endif // !_MINIASTEROIDROCK_H