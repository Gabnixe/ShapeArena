#include "raylib.h"
#include "box2d/box2d.h"

class Wall
{
    public:
        Wall(b2WorldId worldId, Rectangle startingRectangle);
        
        void Draw();

        Rectangle rectangle;
    private:

};