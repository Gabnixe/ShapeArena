#include "box2d/box2d.h"

class World
{
    public:
        World();
        void Update(float DeltaTime);
        void Draw();
        ~World();

    private:
        b2WorldId worldId;
        int lengthUnitsPerMeter;

};