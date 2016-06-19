#ifndef YELLOW
#define YELLOW
#include"bird.h"
#endif // YELLOW

class Yellow : public Bird
{
  public:
    Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

    void show();
};
