#ifndef _SMALLASTEROIDROCKC_H
#define _SMALLASTEROIDROCKC_H
#include "AsteroidRock.h"

using namespace SDLFramework;

class SmallAsteroidRockC : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	SmallAsteroidRockC();
	~SmallAsteroidRockC();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCKC_H