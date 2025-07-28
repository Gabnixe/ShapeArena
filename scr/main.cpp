#include "raylib.h"
#include "box2d/box2d.h"

#include "world.h"
#include "player.h"

#include <stdio.h>

void Init();
void Update(float DeltaTime);
void Draw();
void Clear();

const int screenWidth = 720;
const int screenHeight = 480;

b2WorldId worldId;

World *world;

Player *player;
Wall *wall;

int main ()
{
	SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "Arena Shooter");
	SetTargetFPS(60);

	//Game Loop
	Init();
	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}
	Clear();

	CloseWindow();

	return 0;
}

void Init()
{
	world = new World();

	Vector2 screenCenter;
	screenCenter.x = screenWidth/2;
	screenCenter.y = screenHeight/2;

	//Box2D init
	float lengthUnitsPerMeter = 10.0f;
	b2SetLengthUnitsPerMeter(lengthUnitsPerMeter);

	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity.y = 0;
	worldId = b2CreateWorld(&worldDef);

	player = new Player(worldId, screenCenter);
	Rectangle rectangle = Rectangle{screenCenter.x - 200, screenCenter.y + 100, 400, 100};
	wall = new Wall(worldId, rectangle);
}

void Update(float deltaTime)
{
	world->Update(deltaTime);
	player->Update(deltaTime);

	b2World_Step(worldId, deltaTime, 4);
}
	
void Draw()
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		world->Draw();

		player->Draw();
		wall->Draw();


		char buffer[100];
		sprintf(buffer, "%.0f FPS", 1 / GetFrameTime());
		DrawText(buffer, 0, 0, 20, BLACK);
	EndDrawing();
}

void Clear()
{
	delete(world);
 	delete(player);
	delete(wall);
	b2DestroyWorld(worldId);
}
