#ifndef BAR_H
#define BAR_H
#include "game.h"

class bar
{
public:
    float x, y, h, w, r, g, b;
    int health;
    int special;
    bar():
    x(0), y(0), h(15), w(45), r(0), g(0), b(0), health(1), special(0) {};
    
    bar(float x, float y, float h, float w, int health, int special):
    x(x), y(y), h(h), w(w), r(0), g(1), b(0), health(health), special(special) {};
    
    bool ifHit(ball* b)
    {
        float top, bot, left, right;
        if (x == 0 && y == 0) {
            return false;
        }
        top = y - h;
        bot = y;
        left = x;
        right = x + w;
        return (top <= b->y && bot >= b->y && left <= b->x && right >= b->x);
    }
    
   void draw() //draws out the bricks
    {
        glBegin(GL_POLYGON);
        glVertex2d(x, y);
        glVertex2d((x + w), y);
        glVertex2d((x + w), (y - h));
        glVertex2d(x, (y - h));
        glEnd();
    }
};

#endif
