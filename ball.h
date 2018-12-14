#ifndef BALL_H
#define BALL_H
#include "game.h"

class ball
{
public:
	float x, y, dirX, dirY, speed, h, w, radius, r, g, b;
	ball():
		x(0), y(0), dirX(0), dirY(0), speed(0), h(0), w(0), radius(0), r(0), g(0), b(0) {};

	ball(float x, float y):
		x(x), y(y), dirX(0), dirY(0), speed(0), h(0), w(0), radius(0), r(0), g(0), b(0) {};

	ball(float x, float y, float dirX, float dirY, float speed, float h, float w, float radius):
		x(x), y(y), dirX(dirX), dirY(dirY), speed(speed), h(h), w(w), radius(radius), r(0), g(0), b(0) {};

	ball(float x, float y, float dirX, float dirY, float speed, float h, float w, float radius, float r, float g, float b):
		x(x), y(y), dirX(dirX), dirY(dirY), speed(speed), h(h), w(w), radius(radius), r(r), g(g), b(b) {};

	~ball() {};

	void drawRect(){
		glBegin(GL_POLYGON);
		glColor3d(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y + h);
		glEnd();
	}

	void draw(){
		float i = 0;
		float tempX = (x) + radius;
		float tempY = y - 0.05;
		while (i < 2 * M_PI) {
			glBegin(GL_LINES);
			glColor3d ( r, g, b );
			glVertex2d (tempX, tempY);
			tempX = x + radius * (cos(i));
			tempY = y + radius * (sin(i));
			glVertex2d (tempX, tempY);
			glEnd();
			i += M_PI / 180;
		}
	}

};

#endif

