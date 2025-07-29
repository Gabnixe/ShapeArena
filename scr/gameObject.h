#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "world.h"

class GameObject
{
    public:
        GameObject(World *world);
        ~GameObject();

        void Update(float deltaTime);
        void Draw();
    
    protected:
        World *world;
};

#endif

