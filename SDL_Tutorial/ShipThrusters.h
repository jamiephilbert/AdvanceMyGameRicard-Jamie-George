#ifndef _SHIPTHRUSTERS
#define _SHIPTHRUSTERS
#include "Player.h"

class ShipThrusters : public Texture
{
public:
	ShipThrusters();
	~ShipThrusters();

	void CheckScreenBounds();

	void Update() override;
	void Render() override;
};

#endif // !_SHIPTHRUSTERS