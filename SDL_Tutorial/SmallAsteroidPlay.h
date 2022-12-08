#ifndef _SMALLASTEROIDPLAY_H
#define _SMALLASTEROIDPLAY_H
#include "AsteroidPlay.h"
#include "PhysicsManager.h"
#include <string>

using namespace SDLFramework;

class SmallAsteroidPlay : public PhysEntity
{
private:
	Random* m_pRandom;
	Texture* m_pTexture;
	AsteroidPlay* m_pBigAsteroid;


	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

	std::string filename;
public:
	SmallAsteroidPlay();
	~SmallAsteroidPlay();


	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCK_H