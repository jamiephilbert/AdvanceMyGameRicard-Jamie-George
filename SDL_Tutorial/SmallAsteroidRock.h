#ifndef _SMALLASTEROIDROCK_H
#define _SMALLASTEROIDROCK_H
#include "AsteroidRock.h"
#include <string>

using namespace SDLFramework;

class SmallAsteroidRock : public Texture
{
private:
	Random* m_pRandom;

	int randVelocityX;
	int randVelocityY;

	void CheckScreenBounds();

	std::string filename;

public:
	SmallAsteroidRock(std::string filename);
	~SmallAsteroidRock();

	void Update() override;
	void Render() override;
};

#endif // !_SMALLASTEROIDROCK_H