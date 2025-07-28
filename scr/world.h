#include "box2d/box2d.h"

//Contain all logic of the game world:
//Entities + the level

class World
{
    public:
        World();
        void Update(float deltaTime);
        void Draw();
        ~World();

    private:
        b2WorldId worldId;
        int lengthUnitsPerMeter;

};