#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"

void PhysEntity::AddCollider(Collider* collider, Vector2 localPos) {
	collider->Parent(this);
	collider->Position(localPos);
	m_pColliders.push_back(collider);

	if (m_pColliders.size() > 1 || m_pColliders[0]->GetType() != Collider::ColliderType::Circle) {
		float furthestDistance = m_pColliders[0]->GetFurthestPoint().Magnitude();
		float dist = 0.0f;

		for (int i = 1; i < m_pColliders.size(); i++) {
			dist = m_pColliders[i]->GetFurthestPoint().Magnitude();

			if (dist > furthestDistance) {
				furthestDistance = dist;
			}
		}

		delete m_pBroadPhaseCollider;
		m_pBroadPhaseCollider = new CircleCollider(furthestDistance, true);
		m_pBroadPhaseCollider->Parent(this);
		m_pBroadPhaseCollider->Position(localPos.x * 1.5f, localPos.y * 3.0f); //<---- You may have to change this to Vec2_Zero
	};
}

bool PhysEntity::IgnoreCollisions() {
	return false;
}

PhysEntity::PhysEntity() {
	m_pBroadPhaseCollider = nullptr;
	mId = 0;
}

PhysEntity::~PhysEntity() {
	for (auto c : m_pColliders) {
		delete c;
	}
	m_pColliders.clear();

	delete m_pBroadPhaseCollider;

	if (mId != 0) {
		PhysicsManager::Instance()->UnregisterEntity(mId);
	}
}

unsigned long PhysEntity::GetId() {
	return mId;
}

bool PhysEntity::CheckCollision(PhysEntity* other)
{
	if (IgnoreCollisions() || other->IgnoreCollisions()) {
		return false;
	}

	if (m_pBroadPhaseCollider && other->m_pBroadPhaseCollider) {
		narrowPhaseCheck = ColliderVsColliderCheck(m_pBroadPhaseCollider, other->m_pBroadPhaseCollider);
	}
	else {
		narrowPhaseCheck = true;
	}

	if (narrowPhaseCheck) {
		for (int i = 0; i < m_pColliders.size(); i++) {
			for (int j = 0; j < other->m_pColliders.size(); j++) {
				if (ColliderVsColliderCheck(m_pColliders[i], other->m_pColliders[j])) {
					return true;
				}
			}
		}
	}
	return false;


	//return ColliderVsColliderCheck(m_pBroadPhaseCollider, other->m_pBroadPhaseCollider);
}

void PhysEntity::Render() {
	for (auto c : m_pColliders) {
		c->Render();
	}

	if (m_pBroadPhaseCollider) {
		m_pBroadPhaseCollider->Render();
	}
}
