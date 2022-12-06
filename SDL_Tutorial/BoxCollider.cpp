#include "BoxCollider.h"

void BoxCollider::AddVert(int index, Vector2 pos) {
	m_pVerts[index] = new GameEntity(pos);
	m_pVerts[index]->Parent(this);
}

BoxCollider::BoxCollider(Vector2 size) : Collider(ColliderType::Box) {
	AddVert(0, Vector2(-0.5f*size.x,-0.5f*size.y));
	AddVert(1, Vector2( 0.5f*size.x,-0.5f*size.y));
	AddVert(2, Vector2(-0.5f*size.x, 0.5f*size.y));
	AddVert(3, Vector2( 0.5f*size.x, 0.5f*size.y));

	if (DEBUG_COLLIDERS) {
		SetDebugTexture(new Texture("BoxCollider.png"));
		m_pDebugTexture->Scale(size);
	}
}

BoxCollider::~BoxCollider() {
	for (auto v : m_pVerts) {
		delete v;
	}
}

Vector2 BoxCollider::GetFurthestPoint() {
	Vector2 localPos = Position(GameEntity::Local);

	int furthestIndex = 0;
	float dist = (localPos + m_pVerts[0]->Position(GameEntity::Local)).Magnitude();
	float otherDist = 0.0f;

	for (int i = 0; i < MAX_VERTS; i++) {
		otherDist = (localPos + m_pVerts[i]->Position(GameEntity::Local)).MagnitudeSqr();
		if (otherDist > dist) {
			furthestIndex = i;
			dist = otherDist;
		}
	}

	return localPos + m_pVerts[furthestIndex]->Position(GameEntity::Local);
}

Vector2 BoxCollider::GetVertexPos(int index) {
	return m_pVerts[index]->Position();
}

