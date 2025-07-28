#include "raylib.h"
#include "box2d/box2d.h"

#include "const.h"
#include "debug.h"

#include "world.h"

void Init();
void Update(float DeltaTime);
void Draw();
void Clear();


World *world;

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
}

void Update(float deltaTime)
{
	world->Update(deltaTime);
}
	
void Draw()
{
	BeginDrawing();
		ClearBackground(RAYWHITE);
		
		world->Draw();

		drawDebug();
	EndDrawing();
}

void Clear()
{
	delete(world);
}
