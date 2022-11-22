#ifndef _SMALLASTEROIDROCK_H
#define _SMALLASTEROIDROCK_H
//#include "Texture.h"
//#include "Random.h"
#include "AsteroidRock.h"

using namespace SDLFramework;

class SmallAsteroidRock : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	SmallAsteroidRock();
	~SmallAsteroidRock();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCK_H