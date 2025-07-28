#include "world.h"

#include "const.h"

#include "player.h"
#include "wall.h"

Player *player;
Wall *wall;

World::World()
{
	//Init Box2D
	b2SetLengthUnitsPerMeter(LENGHT_UNITS_PER_METER);
    b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity.y = 0;
	worldId = b2CreateWorld(&worldDef);

	Vector2 screenCenter;
	screenCenter.x = screenWidth/2;
	screenCenter.y = screenHeight/2;

	player = new Player(worldId, screenCenter);
	Rectangle rectangle = Rectangle{screenCenter.x - 200, screenCenter.y + 100, 400, 100};
	wall = new Wall(worldId, rectangle);
}

void World::Update(float deltaTime)
{
	player->Update(deltaTime);

	b2World_Step(worldId, deltaTime, 4);
}

void World::Draw()
{
	player->Draw();
	wall->Draw();
}

World::~World()
{
	delete(player);
	delete(wall);
	b2DestroyWorld(worldId);
}