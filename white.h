#ifndef WHITE
#define WHITE
#include"bird.h"
#endif // WHITE

class White : public Bird
{
  public:
    White(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

    void showt();
};
