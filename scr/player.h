#include "raylib.h"
#include "box2d/box2d.h"

#include "wall.h"

class Player
{
    public:
        Player(b2WorldId worldId, Vector2 startingPosition, Color color = WHITE);

        void Update(float deltaTime);
        void Draw();

    private:
        const float speed = 100.f;

        b2BodyId bodyId;

        Vector2 position;
        Color color;

        float aimAngle = 0.f;

        Vector2 GetMovement();
        Vector2 GetPosition();
};
