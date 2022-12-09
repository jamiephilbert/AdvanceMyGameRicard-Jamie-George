//#include "ShipThrusters.h"
//
//ShipThrusters::ShipThrusters()
//{
//	m_pTimer = Timer::Instance();
//
//	m_pShipThrusters = new Texture("ShipThrusters.png", 0, 0, 18, 17);
//	m_pShipThrusters->Parent(this);
//	m_pShipThrusters->Position(0.0f, 21.0f);
//}
//
//ShipThrusters::~ShipThrusters()
//{
//	m_pTimer = nullptr;
//
//	delete m_pShipThrusters;
//	m_pShipThrusters = nullptr;
//}
//
//void ShipThrusters::Thrusters(Vector2 pos, float rotation)
//{
//	Position(pos);
//	Rotation(rotation);
//	Active(true);
//}
//
//void ShipThrusters::Update()
//{
//	if (Active()) {
//		Translate(-Vec2_Up * m_pTimer->DeltaTime());
//
//		Vector2 pos = Position();
//	}
//}
//
//void ShipThrusters::Render()
//{
//	if (Active()) {
//		m_pShipThrusters->Render();
//	}
//}
