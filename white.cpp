#include"white.h"

 White::White(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void White::showt()
{
    g_body->SetLinearVelocity(b2Vec2(0,-30));
    g_body->GetAngularDamping();
}

