#ifndef _SMALLASTEROIDROCK_H
#define _SMALLASTEROIDROCK_H
#include "AsteroidPlay.h"
#include "PhysicsManager.h"
#include <string>

using namespace SDLFramework;

class SmallAsteroidRock : public PhysEntity
{
private:
	Random* m_pRandom;
	Texture* m_pTexture;
	
	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

	std::string filename;

public:
	SmallAsteroidRock();
	~SmallAsteroidRock();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCK_H