#include "Bullet.h"
//#include "PhysicsManager.h"

Bullet::Bullet()
{
	m_pTimer = Timer::Instance();

	m_pTexture = new Texture("PlayerBullet.png", 0, 0, 4, 6);
	m_pTexture->Parent(this);
	m_pTexture->Position(Vec2_Zero);

	mBulletSpeed = 1500;

	//AddCollider(new BoxCollider(Vector2(20.0f, 30.0f)), Vector2(-10.0f, -13.0f));
	//m_pColliders[0]->Parent(this);
	//m_pColliders[0]->Position(5.0f, 0.0f);


	//mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);

	Reload();
}

Bullet::~Bullet()
{
	m_pTimer = nullptr;

	delete m_pTexture;
	m_pTexture = nullptr;
}

void Bullet::Fire(Vector2 pos, float rotation)
{
	Position(pos);
	Rotation(rotation);
	Active(true);
}

void Bullet::Reload()
{
	Active(false);
}

void Bullet::Update()
{
	if (Active()) {
		Translate(-Vec2_Up * mBulletSpeed * m_pTimer->DeltaTime());

		Vector2 pos = Position();

		if (pos.y < -OFFSCREEN_BUFFER) {
			Reload();
		}
		if (pos.y > Graphics::SCREEN_HEIGHT + OFFSCREEN_BUFFER) {
			Reload();
		}
		if (pos.x < -OFFSCREEN_BUFFER) {
			Reload();
		}
		if (pos.x > Graphics::SCREEN_WIDTH + OFFSCREEN_BUFFER) {
			Reload();
		}
	}
}

void Bullet::Render()
{
	if (Active()) {
		m_pTexture->Render();
	}

	//PhysEntity::Render();
}