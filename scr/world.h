#include "box2d/box2d.h"

#include "gameObject.h"

//Contain all logic of the game world:
//Entities + the level

class World
{
    public:
        World();
        void Update(float deltaTime);
        void Draw();
        ~World();

        GameObject* AddGameObject();
        void RemoveGameObject(GameObject *gameObject);

    private:
        b2WorldId worldId;
};