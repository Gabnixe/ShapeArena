#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "world.h"

class GameObject
{
    public:
        GameObject(World *world);
        ~GameObject();

        virtual void Update(float deltaTime);
        virtual void Draw();
    
    protected:
        World *world;
};

#endif

