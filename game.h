#ifndef MAIN_H
#define MAIN_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "paddle.h"
#include "ball.h"
#include "bar.h"
#include "level.h"
using namespace std;

int width = 480, height =640;
int interval = 1000 / 60;
int data[] = {0};

int lives = 3;
int score = 0;
int levelNow = 1;

bool gameOver = false;
bool gameStart = false;
bool oneHit = true;

paddle *paddleMain = new paddle(200.0, 10.0, 10.0, 80.0, 0, 1, 1);
ball *ballMain = new ball((paddleMain->x + (paddleMain->w / 2)), (paddleMain->y + paddleMain->h + 4), 0, 1, 0, 8, 8, 4, 1, 0, 1);
level *levelMain = new level();

void gameOverDraw(){
	levelMain->addBar(new bar(30, 410 + 30, 15, 75, 5, 0)); //Row 1
	levelMain->addBar(new bar(150, 410 + 30, 15, 45, 5, 0));
	levelMain->addBar(new bar(240, 410 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(315, 410 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 410 + 30, 15, 105, 5, 0));
	
	levelMain->addBar(new bar(15, 395 + 30, 15, 30, 5, 0)); //Row 2
	levelMain->addBar(new bar(135, 395 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(180, 395 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 395 + 30, 15, 45, 5, 0));
	levelMain->addBar(new bar(300, 395 + 30, 15, 45, 5, 0));
	levelMain->addBar(new bar(360, 395 + 30, 15, 30, 5, 0));
	
	levelMain->addBar(new bar(15, 380 + 30, 15, 15, 5, 0));// Row 3
	levelMain->addBar(new bar(120, 380 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 380 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 380 + 30, 15, 105, 5, 0));
	levelMain->addBar(new bar(360, 380 + 30, 15, 30, 5, 0));
	
	levelMain->addBar(new bar(15, 365 + 30, 15, 15, 5, 0)); //Row 4
	levelMain->addBar(new bar(60, 365 + 30, 15, 45, 5, 0));
	levelMain->addBar(new bar(120, 365 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 365 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 365 + 30, 15, 105, 5, 0));
	levelMain->addBar(new bar(360, 365 + 30, 15, 90, 5, 0));
	
	levelMain->addBar(new bar(15, 350 + 30, 15, 15, 5, 0)); // Row 5
	levelMain->addBar(new bar(75, 350 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(120, 350 + 30, 15, 105, 5, 0));
	levelMain->addBar(new bar(240, 350 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(285, 350 + 30, 15, 15, 5, 0));
	levelMain->addBar(new bar(315, 350 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 350 + 30, 15, 30, 5, 0));
	
	levelMain->addBar(new bar(15, 335 + 30, 15, 30, 5, 0)); //Row 6
	levelMain->addBar(new bar(75, 335 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(120, 335 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 335 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 335 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(315, 335 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 335 + 30, 15, 30, 5, 0));

	levelMain->addBar(new bar(30, 320 + 30, 15, 75, 5, 0)); //Row 7
	levelMain->addBar(new bar(120, 320 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 320 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 320 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(315, 320 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 320 + 30, 15, 105, 5, 0));

	levelMain->addBar(new bar(30, 290 + 30, 15, 60, 5, 0)); //Row 9
	levelMain->addBar(new bar(120, 290 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 290 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 290 + 30, 15, 105, 5, 0));
	levelMain->addBar(new bar(360, 290 + 30, 15, 90, 5, 0));

	levelMain->addBar(new bar(15, 275 + 30, 15, 30, 5, 0)); //Row 10
	levelMain->addBar(new bar(75, 275 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(120, 275 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 275 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 275 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 275 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(435, 275 + 30, 15, 30, 5, 0));
	
	levelMain->addBar(new bar(15, 260 + 30, 15, 30, 5, 0)); //Row 11
	levelMain->addBar(new bar(75, 260 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(120, 260 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 260 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 260 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 260 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(435, 260 + 30, 15, 30, 5, 0));

	levelMain->addBar(new bar(15, 245 + 30, 15, 30, 5, 0)); //Row 12
	levelMain->addBar(new bar(75, 245 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(120, 245 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(195, 245 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 245 + 30, 15, 90, 5, 0));
	levelMain->addBar(new bar(360, 245 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(420, 245 + 30, 15, 45, 5, 0));

	levelMain->addBar(new bar(15, 230 + 30, 15, 30, 5, 0)); //Row 13
	levelMain->addBar(new bar(75, 230 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(135, 230 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(180, 230 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(240, 230 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 230 + 30, 15, 75, 5, 0));
	
	levelMain->addBar(new bar(15, 215 + 30, 15, 30, 5, 0)); //Row 14
	levelMain->addBar(new bar(75, 215 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(150, 215 + 30, 15, 45, 5, 0));
	levelMain->addBar(new bar(240, 215 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(360, 215 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(405, 215 + 30, 15, 45, 5, 0));
	
	levelMain->addBar(new bar(30, 200 + 30, 15, 60, 5, 0)); //Row 15
	levelMain->addBar(new bar(165, 200 + 30, 15, 15, 5, 0));
	levelMain->addBar(new bar(240, 200 + 30, 15, 105, 5, 0));
	levelMain->addBar(new bar(360, 200 + 30, 15, 30, 5, 0));
	levelMain->addBar(new bar(420, 200 + 30, 15, 45, 5, 0));
}
void levelOne(){
  
    levelMain->addBar(new bar(30 , 580, 15, 35, 3, 1)); //Row 1
    levelMain->addBar(new bar(80 , 580, 15, 35, 5, 0));
    levelMain->addBar(new bar(130 , 580, 15, 35, 3, 0));
    levelMain->addBar(new bar(180 , 580, 15, 35, 5, 0));
    levelMain->addBar(new bar(230 , 580, 15, 35, 3, 0));
    levelMain->addBar(new bar(280  , 580, 15, 35, 5, 0));
    levelMain->addBar(new bar(330 , 580, 15, 35, 3, 0));
    levelMain->addBar(new bar(380 , 580, 15, 35, 5, 0));
    levelMain->addBar(new bar(430 , 580, 15, 35, 3, 0));
   
    levelMain->addBar(new bar(55 , 550, 15, 35, 5, 0)); //Row 2
    levelMain->addBar(new bar(105 , 550, 15, 35, 3, 0));
    levelMain->addBar(new bar(155 , 550, 15, 35, 5, 0));
    levelMain->addBar(new bar(205 , 550, 15, 35, 3, 0));
    levelMain->addBar(new bar(255  , 550, 15, 35, 5, 0));
    levelMain->addBar(new bar(305 , 550, 15, 35, 3, 0));
    levelMain->addBar(new bar(355 , 550, 15, 35, 5, 0));
    levelMain->addBar(new bar(405 , 550, 15, 35, 3, 0));
 
    levelMain->addBar(new bar(30 , 520, 15, 35, 3, 0)); //Row 3
    levelMain->addBar(new bar(80 , 520, 15, 35, 5, 0));
    levelMain->addBar(new bar(130 , 520, 15, 35, 3, 0));
    levelMain->addBar(new bar(180 , 520, 15, 35, 5, 0));
    levelMain->addBar(new bar(230 , 520, 15, 35, 3, 0));
    levelMain->addBar(new bar(280  , 520, 15, 35, 5, 0));
    levelMain->addBar(new bar(330 , 520, 15, 35, 3, 0));
    levelMain->addBar(new bar(380 , 520, 15, 35, 5, 0));
    levelMain->addBar(new bar(430 , 520, 15, 35, 3, 0));
    
    levelMain->addBar(new bar(55 , 490, 15, 35, 5, 0));  //Row 4
    levelMain->addBar(new bar(105 , 490, 15, 35, 3, 0));
    levelMain->addBar(new bar(155 , 490, 15, 35, 5, 0));
    levelMain->addBar(new bar(205 , 490, 15, 35, 3, 0));
    levelMain->addBar(new bar(255  , 490, 15, 35, 5, 0));
    levelMain->addBar(new bar(305 , 490, 15, 35, 3, 0));
    levelMain->addBar(new bar(355 , 490, 15, 35, 5, 0));
    levelMain->addBar(new bar(405 , 490, 15, 35, 3, 0));

    levelMain->addBar(new bar(30 , 460, 15, 35, 3, 0)); //Row 5
    levelMain->addBar(new bar(80 , 460, 15, 35, 5, 0));
    levelMain->addBar(new bar(130 , 460, 15, 35, 3, 0));
    levelMain->addBar(new bar(180 , 460, 15, 35, 5, 0));
    levelMain->addBar(new bar(230 , 460, 15, 35, 3, 0));
    levelMain->addBar(new bar(280  , 460, 15, 35, 5, 0));
    levelMain->addBar(new bar(330 , 460, 15, 35, 3, 0));
    levelMain->addBar(new bar(380 , 460, 15, 35, 5, 0));
    levelMain->addBar(new bar(430 , 460, 15, 35, 3, 0));
 
    levelMain->addBar(new bar(55 , 430, 15, 35, 5, 0)); //Row 6
    levelMain->addBar(new bar(105 , 430, 15, 35, 3, 0));
    levelMain->addBar(new bar(155 , 430, 15, 35, 5, 0));
    levelMain->addBar(new bar(205 , 430, 15, 35, 3, 0));
    levelMain->addBar(new bar(255  , 430, 15, 35, 5, 0));
    levelMain->addBar(new bar(305 , 430, 15, 35, 3, 0));
    levelMain->addBar(new bar(355 , 430, 15, 35, 5, 0));
    levelMain->addBar(new bar(405 , 430, 15, 35, 3, 0));
    
    levelMain->addBar(new bar(30 , 400, 15, 35, 3, 0)); //Row 7
    levelMain->addBar(new bar(80 , 400, 15, 35, 5, 0));
    levelMain->addBar(new bar(130 , 400, 15, 35, 3, 0));
    levelMain->addBar(new bar(180 , 400, 15, 35, 5, 0));
    levelMain->addBar(new bar(230 , 400, 15, 35, 3, 0));
    levelMain->addBar(new bar(280  , 400, 15, 35, 5, 0));
    levelMain->addBar(new bar(330 , 400, 15, 35, 3, 0));
    levelMain->addBar(new bar(380 , 400, 15, 35, 5, 0));
    levelMain->addBar(new bar(430 , 400, 15, 35, 3, 0));
}
#endif
