#include"yellow.h"

 Yellow::Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void Yellow::show()
{
    g_body->SetLinearVelocity(b2Vec2(30,-10));
}
