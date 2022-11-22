#ifndef _SMALLASTEROIDROCKB_H
#define _SMALLASTEROIDROCKB_H
#include "AsteroidRock.h"

using namespace SDLFramework;

class SmallAsteroidRockB : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	SmallAsteroidRockB();
	~SmallAsteroidRockB();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCKB_H