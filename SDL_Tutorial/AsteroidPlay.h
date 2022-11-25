#ifndef _ASTROIDPLAY_H
#define _ASTROIDPLAY_H
#include "Texture.h"
#include "Random.h"

using namespace SDLFramework;

class AsteroidPlay : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

public:
	AsteroidPlay();
	~AsteroidPlay();

	void MoveAsteroid();

	void Update() override;
	void Render() override;
};

#endif // !_ASTROIDROCK_H