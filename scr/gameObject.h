#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    public:
        GameObject();
        ~GameObject();

        void Update(float deltaTime);
        void Draw();
};

#endif

