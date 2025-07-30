#include "gameObject.h"

GameObject::GameObject(World *world)
{
    world->AddGameObject(this);
    this->world = world;
}

GameObject::~GameObject()
{
    world->RemoveGameObject(this);
}

void GameObject::Update(float deltaTime)
{

}

void GameObject::Draw()
{

}