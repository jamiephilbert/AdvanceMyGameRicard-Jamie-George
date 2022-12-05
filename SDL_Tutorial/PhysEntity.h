#ifndef _PHYSENTITY_H
#define _PHYSENTITY_H
#include <vector>
#include "Collider.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

class PhysEntity : public GameEntity {
protected:
	unsigned long mId;

	std::vector<Collider*> m_pColliders;

	Collider* m_pBroadPhaseCollider;

	void AddCollider(Collider* collider, Vector2 localPos = Vec2_Zero);

	virtual bool IgnoreCollisions();

	bool narrowPhaseCheck = false;

public:
	PhysEntity();
	~PhysEntity();

	unsigned long GetId();

	bool CheckCollision(PhysEntity* other);

	virtual void Hit(PhysEntity* other) { }

	virtual void Render() override;
};
#endif