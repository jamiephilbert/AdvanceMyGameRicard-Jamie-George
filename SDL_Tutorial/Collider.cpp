#include "Collider.h"

void Collider::SetDebugTexture(Texture* tex) {
	delete m_pDebugTexture;
	m_pDebugTexture = tex;
	m_pDebugTexture->Parent(this);
}

Collider::Collider(ColliderType type) : mType(type) {
	m_pDebugTexture = nullptr;
}

Collider::~Collider() {
	delete m_pDebugTexture;
	m_pDebugTexture = nullptr;
}


Collider::ColliderType Collider::GetType() {
	return mType;
}

void Collider::Render() {
	if (DEBUG_COLLIDERS) {
		m_pDebugTexture->Render();
	}
}
