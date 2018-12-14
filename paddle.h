#ifndef PADDLE_H
#define PADDLE_H
#include "game.h"
#include "ball.h"

class paddle
{
public:
	float x, y, h, w, r, g, b;
	paddle(): x(0), y(0), h(0), w(0), r(0), g(0), b(0) {};
	paddle(float x, float y): x(x), y(y), h(0), w(0), r(0), g(0), b(0) {};
	paddle(float x, float y, float h, float w): x(x), y(y), h(h), w(w), r(0), g(0), b(0) {};
	paddle(float x, float y, float h, float w, float r, float g, float b): x(x), y(y), h(h), w(w), r(r), g(g), b(b) {};
	~paddle() {};

	bool isHit(ball* b){
        float r_top, r_bot, r_left, r_right;
		if (x == 0 && y == 0) {
			return false;
		}
		r_top = y;
		r_bot = y + (1.5 * h);
		r_left = x;
		r_right = x + w;
		return (r_top <= b->y && r_bot >= b->y && r_left <= b->x && r_right >= b->x);
	}
	void draw(){
		glBegin(GL_POLYGON);
		glColor3d(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y + h);
		glEnd();
	}

};

#endif
