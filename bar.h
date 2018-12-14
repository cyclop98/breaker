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
    
    bar(float x, float y, int health, int special):
    x(x), y(y), h(15), w(45), r(0), g(1), b(0), health(health), special(special) {};
    
    bar(float x, float y, float h, float w, int health, int special):
    x(x), y(y), h(h), w(w), r(0), g(1), b(0), health(health), special(special) {};
    
    bar(float x, float y, float h, float w, float r, float g, float b, int health, int special):
    x(x), y(y), h(h), w(w), r(r), g(g), b(b), health(health), special(special) {};
    
    ~bar() {};
    
    bool isHit(ball* b)
    {
        float r_top, r_bot, r_left, r_right;
        if (x == 0 && y == 0) {
            return false;
        }
        r_top = y - h;
        r_bot = y;
        r_left = x;
        r_right = x + w;
        return (r_top <= b->y && r_bot >= b->y && r_left <= b->x && r_right >= b->x);
    }
    
    void draw()
    {
        glBegin(GL_POLYGON);
        glVertex2d(x, y);
        glVertex2d((x + w), y);
        glVertex2d((x + w), (y - h));
        glVertex2d(x, (y - h));
        glEnd();
    }
    
    void draw(float offsetX, float offsetY)
    {
        glBegin(GL_POLYGON);
        glVertex2d(x + offsetX, y + offsetY);
        glVertex2d((x + offsetX + w), y + offsetY);
        glVertex2d((x + offsetX + w), (y + offsetY - h));
        glVertex2d(x + offsetX, (y + offsetY - h));
        glEnd();
    }
};

#endif
