#include "wall.h"

Wall::Wall(World *world, Rectangle startingRectangle) : GameObject(world)
{
    rectangle = startingRectangle;

    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = (b2Vec2){rectangle.x + rectangle.width/2, rectangle.y + rectangle.height/2};
    b2BodyId bodyId = b2CreateBody(world->GetB2WorldId(), &bodyDef);
    b2ShapeDef rectangleDef = b2DefaultShapeDef();
    b2Polygon rectanglePolygon = b2MakeBox(rectangle.width/2, rectangle.height/2);
    b2ShapeId rectangleId = b2CreatePolygonShape(bodyId, &rectangleDef, &rectanglePolygon);
}

void Wall::Draw()
{
    DrawRectangleRec(rectangle, WHITE);
    DrawRectangleLinesEx(rectangle, 2, BLACK);

    //Horizontal Shadows
    DrawLine(rectangle.x + 2, rectangle.y, rectangle.x + rectangle.width + 2, rectangle.y, BLACK);
    DrawLine(rectangle.x + 4, rectangle.y - 1, rectangle.x + rectangle.width + 2, rectangle.y - 1, BLACK);

    //Vertical Shadows
    DrawLine(rectangle.x + rectangle.width + 1, rectangle.y, rectangle.x + rectangle.width + 1, rectangle.y + rectangle.height - 2, BLACK);
    DrawLine(rectangle.x + rectangle.width + 2, rectangle.y, rectangle.x + rectangle.width + 2, rectangle.y + rectangle.height - 4, BLACK);
}