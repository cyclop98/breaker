#ifndef LEVEL_H
#define LEVEL_H
#include "game.h"
using namespace std;

class level
{
public:
	vector<bar*> bars;
	level() {};
	level(vector<bar*> bars): bars(bars) {};
	~level() {};
	
	
	void addBar(bar* b){
		bars.push_back(b);
	}

	void draw(){
		for (vector<bar*>::iterator i = bars.begin(); i != bars.end(); ++i) {
			if ((*i)->health != 0) {
				if ((*i)->health == 5) { //red
					glColor3d(1, 0, 0);
					(*i)->draw();
				} else if ((*i)->health == 3) { //green
					glColor3d(0.46, 0.93, 0);
					(*i)->draw();
				}
			}
		}
	}
};

#endif
