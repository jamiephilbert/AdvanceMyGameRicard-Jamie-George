#ifndef _ASTROIDPLAY_H
#define _ASTROIDPLAY_H
#include "Texture.h"
#include "Random.h"

using namespace SDLFramework;

class AsteroidPlay : public Texture
{
private:
	Random* m_pRandom2;

	int XPos;
	int YPos;

	void CheckScreenBounds();

public:
	AsteroidPlay(int asteroid, int count);
	~AsteroidPlay();

	void Update() override;
	void Render() override;
};

#endif // !_ASTROIDROCK_H