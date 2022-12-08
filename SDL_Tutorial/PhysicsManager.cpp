#include "PhysicsManager.h"

PhysicsManager * PhysicsManager::s_pInstance = nullptr;

PhysicsManager * PhysicsManager::Instance() {
	if (s_pInstance == nullptr) {
		s_pInstance = new PhysicsManager();
	}

	return s_pInstance;
}

void PhysicsManager::Release() {
	delete s_pInstance;
	s_pInstance = nullptr;
}

void PhysicsManager::SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags) {
	mLayerMasks[static_cast<unsigned int>(layer)] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(flags));
}

unsigned long PhysicsManager::RegisterEntity(PhysEntity * entity, CollisionLayers layer) {
	m_pCollisionLayers[static_cast<unsigned int>(layer)].push_back(entity);
	mLastId++;
	return mLastId;
}

void PhysicsManager::UnregisterEntity(unsigned long id) {
	bool found = false;

	for (int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers) && !found; i++) {
		for (int j = 0; j < m_pCollisionLayers[i].size() && !found; j++) {
			if (m_pCollisionLayers[i][j]->GetId() == id) {
				m_pCollisionLayers[i].erase(m_pCollisionLayers[i].begin() + j);
				found = true;
			}
		}
	}
}

void PhysicsManager::Update() {
	for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++) {
		for (unsigned int j = 0; j < static_cast<unsigned int>(CollisionLayers::MaxLayers); j++) {
			if (mLayerMasks[i].test(j) && i <= j) {
				for (unsigned int k = 0; k < m_pCollisionLayers[i].size(); k++) {
					for (unsigned int l = 0; l < m_pCollisionLayers[j].size(); l++) {
						if (m_pCollisionLayers[i][k]->CheckCollision(m_pCollisionLayers[j][l])) {
							m_pCollisionLayers[i][k]->Hit(m_pCollisionLayers[j][l]);
							m_pCollisionLayers[j][l]->Hit(m_pCollisionLayers[i][k]);
						}
					}
				}
			}
		}
	}
}

PhysicsManager::PhysicsManager() {
	mLastId = 0;

	for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); i++) {
		mLayerMasks[i] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(CollisionFlags::None));
	}
}

PhysicsManager::~PhysicsManager() {
	for (auto l : m_pCollisionLayers) {
		l.clear();
	}
}
