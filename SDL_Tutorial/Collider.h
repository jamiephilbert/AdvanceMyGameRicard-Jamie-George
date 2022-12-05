#ifndef _COLLIDER_H
#define _COLLIDER_H
#include "Texture.h"

using namespace SDLFramework;

class Collider : public GameEntity {
public:
	enum class ColliderType { Box, Circle }; // type safety

protected:
	ColliderType mType;

	static const bool DEBUG_COLLIDERS = true;
	Texture* m_pDebugTexture;

	void SetDebugTexture(Texture* tex);

public:
	Collider(ColliderType type);
	virtual ~Collider();

	virtual Vector2 GetFurthestPoint() = 0;

	ColliderType GetType();

	virtual void Render() override;
};
#endif