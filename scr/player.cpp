#include "player.h"

#include <stdio.h> 
#include "raymath.h"

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
}

void Player::Update(float deltaTime, Wall *wall)
{
    Vector2 movement = GetMovement();
    float frameAdjustedSpeed = speed * deltaTime;
    movement *= frameAdjustedSpeed;

    Vector2 newPosition = position + movement;
    position = newPosition;

    aimAngle = Vector2Angle(Vector2{1,0}, GetMousePosition() - position);
}

void Player::Draw()
{
    //Draw Player
    DrawCircle(GetPosition().x, GetPosition().y, 10, color);
    DrawCircleLines(GetPosition().x, GetPosition().y, 10, BLACK);
    DrawCircleLines(GetPosition().x, GetPosition().y, 9, BLACK);

    //Draw Aiming Reticle
    DrawLineEx(GetPosition(), GetPosition() + Vector2Rotate(Vector2{15,0}, aimAngle), 2, BLACK);
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
    printf("%4.2f %4.2f\n", position.x, position.y);
    return (Vector2){b2Pos.x, b2Pos.y};
}
