#include "gameObject.h"

#include "raylib.h"
#include "box2d/box2d.h"

class Wall : public GameObject
{
    public:
        Wall(World *world, Rectangle startingRectangle);
        
        void Draw();

    private:
        Rectangle rectangle;
};