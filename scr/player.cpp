#include "player.h"

#include <stdio.h> 
#include "raymath.h"

#include "bullet.h"

b2WorldId worldId;
Bullet *bullet;

Player::Player(b2WorldId worldId, Vector2 startingPosition, Color playerColor)
{
    position = startingPosition;
    color = playerColor;
    aimAngle = 0;

    
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = (b2Vec2){position.x, position.y};
    bodyId = b2CreateBody(worldId, &bodyDef);
    b2ShapeDef circleDef = b2DefaultShapeDef();
    b2Circle circle = (b2Circle){(b2Vec2){0, 0}, 10};
    b2ShapeId circleId = b2CreateCircleShape(bodyId, &circleDef, &circle);

    this->worldId = worldId;
}

Player::~Player()
{
    if (bullet != nullptr)
    {
        delete(bullet);
    }
}

void Player::Update(float deltaTime)
{
    Vector2 movement = GetMovement();
    b2Body_SetLinearVelocity(bodyId, b2Vec2{GetMovement().x, GetMovement().y} * speed);

    aimAngle = Vector2Angle(Vector2{1,0}, GetMousePosition() - position);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (bullet != nullptr)
        {
            delete(bullet);
        }
        bullet = new Bullet(worldId, GetPosition(), Vector2Rotate(Vector2{1,0}, aimAngle), 1000);
    }
    if (bullet != nullptr)
    {
        bullet->Update(deltaTime);
    }
}

void Player::Draw()
{
    //Draw Player
    DrawCircle(GetPosition().x, GetPosition().y, 10, color);
    DrawCircleLines(GetPosition().x, GetPosition().y, 10, BLACK);
    DrawCircleLines(GetPosition().x, GetPosition().y, 9, BLACK);

    //Draw Aiming Reticle
    DrawLineEx(GetPosition(), GetPosition() + Vector2Rotate(Vector2{15,0}, aimAngle), 2, BLACK);

    if (bullet != nullptr)
    {
        bullet->Draw();
    }
}

Vector2 Player::GetMovement()
{
    Vector2 movement = Vector2{0,0};
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) movement.x++;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) movement.x--;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) movement.y++;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) movement.y--;
    return Vector2Normalize(movement);
}

Vector2 Player::GetPosition()
{
    b2Vec2 b2Pos = b2Body_GetPosition(bodyId);
}
