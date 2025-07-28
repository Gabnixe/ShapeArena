#include "raylib.h"
#include "box2d/box2d.h"

class Bullet
{
    public:
        Bullet(b2WorldId worldId, Vector2 position, Vector2 direction, float speed);
        ~Bullet();
        void Update(float deltaTime);
        void Draw();

    private:
        Vector2 GetPosition();
        b2BodyId bodyId;
        Vector2 direction;
        float speed;
};