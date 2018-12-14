#ifndef PADDLE_H
#define PADDLE_H
#include "game.h"
#include "ball.h"

class paddle
{
public:
	float x, y, h, w, r, g, b;
	paddle(float x, float y, float h, float w, float r, float g, float b): x(x), y(y), h(h), w(w), r(r), g(g), b(b) {};
	
	bool ifHit(ball* b){
        float top, bot, left, right;
		if (x == 0 && y == 0) {
			return false;
		}
        
		top = y;
		bot = y + (1.0 * h);
		left = x;
		right = x + w;
		return (top <= b->y && bot >= b->y && left <= b->x && right >= b->x);
	}
	void draw(){ //draws out the paddle that hits the ball
		glBegin(GL_POLYGON);
		glColor3d(r, g, b);
        glColor3d(1, 1, 0);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y + h);
		glEnd();
	}

};

#endif
