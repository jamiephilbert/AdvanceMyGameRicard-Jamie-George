#ifndef _ASTROIDROCK_H
#define _ASTROIDROCK_H
#include "Texture.h"
#include "Random.h"

using namespace SDLFramework;

class AsteroidRock : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();
public:
	AsteroidRock();
	~AsteroidRock();

	void Update() override;
	void Render() override;
};

#endif // !_ASTROIDROCK_H