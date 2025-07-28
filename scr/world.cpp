#include "world.h"

World::World()
{
    b2WorldDef worldDef = b2DefaultWorldDef();
	worldId = b2CreateWorld(&worldDef);
}

void World::Update(float DeltaTime)
{

}

void World::Draw()
{

}

World::~World()
{
	b2DestroyWorld(worldId);
}