#ifndef _BULLET_H
#define _BULLET_H
#include "Texture.h"
#include "Timer.h"

using namespace SDLFramework;

class Bullet : public GameEntity
{
private:
	static const int OFFSCREEN_BUFFER = 10;

	Timer* m_pTimer;
	Texture* m_pTexture;

	float mBulletSpeed;

public:
	Bullet();
	~Bullet();

	void Fire(Vector2 pos, float rotation);
	void Reload();

	void Update() override;
	void Render() override;
};

#endif // !_BULLET_H