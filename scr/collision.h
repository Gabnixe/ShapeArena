#include "raylib.h"

#define CUTE_C2_IMPLEMENTATION
#include "cute_c2.h"

namespace Collision
{
    c2v Vector2Toc2V(Vector2 vector) {return c2V(vector.x, vector.y);}
    c2Circle CircleToc2Circle(Vector2 circlePosition, float circleRadius) {return { Vector2Toc2V(circlePosition), circleRadius };}
    c2AABB RectangleToc2AABB(Rectangle rectangle) {return { c2V(rectangle.x, rectangle.y), c2V(rectangle.x + rectangle.width, rectangle.y + rectangle.height) };}

    bool CircleToRectangleCollision(Vector2 circlePosition, float circleRadius, Rectangle rectangle)
    {
        c2Circle circle = CircleToc2Circle(circlePosition, circleRadius);
        c2AABB AABB = RectangleToc2AABB(rectangle);
        return c2CircletoAABB(circle, AABB);
    }

    c2TOIResult CircleCastToRectangle(Vector2 circlePosition, float circleRadius, Vector2 circleVelocity, Rectangle rectangle, Vector2 rectangleVelocity)
    {
        c2Circle circle = CircleToc2Circle(circlePosition, circleRadius);
        c2AABB AABB = RectangleToc2AABB(rectangle);
        return c2TOI(&circle, C2_TYPE_CIRCLE, NULL, Vector2Toc2V(circleVelocity), &AABB, C2_TYPE_AABB, NULL, Vector2Toc2V(rectangleVelocity), circleRadius);
    }
};