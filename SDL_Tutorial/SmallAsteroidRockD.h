#ifndef _SMALLASTEROIDROCKD_H
#define _SMALLASTEROIDROCKD_H
#include "AsteroidRock.h"

using namespace SDLFramework;

class SmallAsteroidRockD : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	SmallAsteroidRockD();
	~SmallAsteroidRockD();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCKD_H