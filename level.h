#ifndef LEVEL_H
#define LEVEL_H
#include "game.h"
using namespace std;

class level
{
public:
	vector<bar*> bars;
	
    void addBar(bar* b){
		bars.push_back(b);
	}

	void draw(){ //changes the bricks' color 
		for (vector<bar*>::iterator i = bars.begin(); i != bars.end(); ++i) {
			if ((*i)->health != 0) {
				if ((*i)->health == 5) {
					glColor3d(.2, 1.7, 1.63);
					(*i)->draw();
				} else if ((*i)->health == 3) { 
					glColor3d(1.7,.33, 1.93);
					(*i)->draw();
				}
			}
		}
	}
};

#endif
