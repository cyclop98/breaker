#ifndef BALL_H
#define BALL_H
#include "game.h"

class ball{
public:
	float x, y, dirX, dirY, speed, h, w, radius, r, g, b;
	ball(float x, float y, float dirX, float dirY, float speed, float h, float w, float radius, float r, float g, float b):
		x(x), y(y), dirX(dirX), dirY(dirY), speed(speed), h(h), w(w), radius(radius), r(r), g(g), b(b) {};

    void draw(){ //draws out the circle using opengl
		float i = 0;
		float tempX = (x) + radius;
		float tempY = y - 0.05;
		while (i < 2 * M_PI) {
			glBegin(GL_LINES);
			glColor3d ( r, g, b );
            glColor3d( 0, 1, 0 );
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

