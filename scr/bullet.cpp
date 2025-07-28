#include "bullet.h"

Bullet::Bullet(b2WorldId worldId, Vector2 position, Vector2 direction, float speed)
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = (b2Vec2){position.x, position.y};
    bodyId = b2CreateBody(worldId, &bodyDef);
    b2ShapeDef circleDef = b2DefaultShapeDef();
    b2Circle circle = (b2Circle){(b2Vec2){0, 0}, 1};
    b2ShapeId circleId = b2CreateCircleShape(bodyId, &circleDef, &circle);

    this->direction = direction;
    this->speed = speed;
}

Bullet::~Bullet()
{
    
}

void Bullet::Update(float deltaTime)
{
    b2Body_SetLinearVelocity(bodyId, b2Vec2{direction.x, direction.y} * speed);
}

void Bullet::Draw()
{
    DrawCircle(GetPosition().x, GetPosition().y, 1, BLACK);
}

Vector2 Bullet::GetPosition()
{
    b2Vec2 b2Pos = b2Body_GetPosition(bodyId);
}