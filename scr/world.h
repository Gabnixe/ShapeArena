#ifndef WORLD_H
#define WORLD_H

#include <vector>
using std::vector;

#include "box2d/box2d.h"

class GameObject;

//Contain all logic of the game world:
//Entities + the level

class World
{
    public:
        World();
        void Update(float deltaTime);
        void Draw();
        ~World();

        GameObject* AddGameObject(GameObject *gameObject);
        void RemoveGameObject(GameObject *gameObject);

        b2WorldId GetB2WorldId();

    private:
        b2WorldId worldId;
        vector<GameObject*> gameObjects;
};

#endif