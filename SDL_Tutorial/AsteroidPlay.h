#ifndef _ASTROIDPLAY_H
#define _ASTROIDPLAY_H
#include "Texture.h"
#include "Random.h"
#include "PhysicsManager.h"
#include "CircleCollider.h"

using namespace SDLFramework;

class AsteroidPlay : public PhysEntity
{
private:
	Random* m_pRandom2;

	Texture* m_pTexture;
	int XPos;
	int YPos;

	void CheckScreenBounds();

public:
	AsteroidPlay(int asteroid, int count);
	~AsteroidPlay();

	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;
};

#endif // !_ASTROIDROCK_H