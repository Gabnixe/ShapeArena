#include "world.h"

World::World()
{
    b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity.y = 9.8f * lengthUnitsPerMeter;
	worldId = b2CreateWorld(&worldDef);
}