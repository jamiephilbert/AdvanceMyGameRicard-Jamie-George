//#include "ShipThrusters.h"
//
//ShipThrusters::ShipThrusters() :Texture("ShipThrusters.png", 0, 0, 18, 17)
//{
//}
//
//ShipThrusters::~ShipThrusters()
//{
//}
//
//void ShipThrusters::CheckScreenBounds()
//{
//		if (Position().x < -11) {
//			Position(Graphics::SCREEN_WIDTH + 10, Position().y);
//		}
//		if (Position().x > Graphics::SCREEN_WIDTH + 11) {
//			Position(-10, Position().y);
//		}
//		if (Position().y < -11) {
//			Position(Position().x, Graphics::SCREEN_HEIGHT + 10);
//		}
//		if (Position().y > Graphics::SCREEN_HEIGHT + 11) {
//			Position(Position().x, -10);
//		}
//}
//
//void ShipThrusters::Update()
//{
//	CheckScreenBounds();
//}
//
//void ShipThrusters::Render()
//{
//	Texture::Render();
//}
