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

int width = 480;
int height = 640;
int interval = 1000 / 60;

int lives = 3;
int score = 0;
int levelNow = 1;

bool gameOver = false;
bool gameStart = false;
bool oneHit = true;
int data[] = {0};

paddle *paddleMain = new paddle(200.0, 10.0, 10.0, 80.0, 0, 1, 1);
ball *ballMain = new ball((paddleMain->x + (paddleMain->w / 2)), (paddleMain->y + paddleMain->h + 4), 0, 1, 0, 8, 8, 4, 1, 0, 1);
level *levelMain = new level();

void gameOverDraw(){
//levelMain->addBar(new bar(30, 150,+30 15, 30, 3, 0));  default starting point
	levelMain->addBar(new bar(30, 410 + 30, 15, 75, 3, 0));
	levelMain->addBar(new bar(150, 410 + 30, 15, 45, 3, 0));
	levelMain->addBar(new bar(240, 410 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(315, 410 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 410 + 30, 15, 105, 3, 0));
	//Row 2
	levelMain->addBar(new bar(15, 395 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(135, 395 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(180, 395 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 395 + 30, 15, 45, 3, 0));
	levelMain->addBar(new bar(300, 395 + 30, 15, 45, 3, 0));
	levelMain->addBar(new bar(360, 395 + 30, 15, 30, 3, 0));
	//Row 3
	levelMain->addBar(new bar(15, 380 + 30, 15, 15, 3, 0));
	levelMain->addBar(new bar(120, 380 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 380 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 380 + 30, 15, 105, 3, 0));
	levelMain->addBar(new bar(360, 380 + 30, 15, 30, 3, 0));
	//Row 4
	levelMain->addBar(new bar(15, 365 + 30, 15, 15, 3, 0));
	levelMain->addBar(new bar(60, 365 + 30, 15, 45, 3, 0));
	levelMain->addBar(new bar(120, 365 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 365 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 365 + 30, 15, 105, 3, 0));
	levelMain->addBar(new bar(360, 365 + 30, 15, 90, 3, 0));
	//Row 5
	levelMain->addBar(new bar(15, 350 + 30, 15, 15, 3, 0));
	levelMain->addBar(new bar(75, 350 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(120, 350 + 30, 15, 105, 3, 0));
	levelMain->addBar(new bar(240, 350 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(285, 350 + 30, 15, 15, 3, 0));
	levelMain->addBar(new bar(315, 350 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 350 + 30, 15, 30, 3, 0));
	//Row 6
	levelMain->addBar(new bar(15, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(120, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(315, 335 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 335 + 30, 15, 30, 3, 0));
	//Row 7
	levelMain->addBar(new bar(30, 320 + 30, 15, 75, 3, 0));
	levelMain->addBar(new bar(120, 320 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 320 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 320 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(315, 320 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 320 + 30, 15, 105, 3, 0));
	//Row 9
	levelMain->addBar(new bar(30, 290 + 30, 15, 60, 3, 0));
	levelMain->addBar(new bar(120, 290 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 290 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 290 + 30, 15, 105, 3, 0));
	levelMain->addBar(new bar(360, 290 + 30, 15, 90, 3, 0));
	//Row 10
	levelMain->addBar(new bar(15, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(120, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 275 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(435, 275 + 30, 15, 30, 3, 0));
	//Row 11
	levelMain->addBar(new bar(15, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(120, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 260 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(435, 260 + 30, 15, 30, 3, 0));

	//Row 12
	levelMain->addBar(new bar(15, 245 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 245 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(120, 245 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(195, 245 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 245 + 30, 15, 90, 3, 0));
	levelMain->addBar(new bar(360, 245 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(420, 245 + 30, 15, 45, 3, 0));
	//Row 13
	levelMain->addBar(new bar(15, 230 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 230 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(135, 230 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(180, 230 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(240, 230 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 230 + 30, 15, 75, 3, 0));
	//Row 14
	levelMain->addBar(new bar(15, 215 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(75, 215 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(150, 215 + 30, 15, 45, 3, 0));
	levelMain->addBar(new bar(240, 215 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(360, 215 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(405, 215 + 30, 15, 45, 3, 0));
	//Row 15
	levelMain->addBar(new bar(30, 200 + 30, 15, 60, 3, 0));
	levelMain->addBar(new bar(165, 200 + 30, 15, 15, 3, 0));
	levelMain->addBar(new bar(240, 200 + 30, 15, 105, 3, 0));
	levelMain->addBar(new bar(360, 200 + 30, 15, 30, 3, 0));
	levelMain->addBar(new bar(420, 200 + 30, 15, 45, 3, 0));
}

void levelOne(){
    levelMain->addBar(new bar(10 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 580, 15, 30, 3, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 580, 15, 30, 3, 0));
    //Row 2
    levelMain->addBar(new bar(10 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 550, 15, 30, 5, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 550, 15, 30, 5, 0));

    //Row 4
    levelMain->addBar(new bar(10 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 520, 15, 30, 3, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 520, 15, 30, 3, 0));
    //Row 6
    levelMain->addBar(new bar(10 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 490, 15, 30, 5, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 490, 15, 30, 5, 0));
    //Row 8
    levelMain->addBar(new bar(10 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 460, 15, 30, 3, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 460, 15, 30, 3, 0));
    //Row 10
    levelMain->addBar(new bar(10 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 430, 15, 30, 5, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 430, 15, 30, 5, 0));
    //Row 12
    levelMain->addBar(new bar(10 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 400, 15, 30, 3, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 400, 15, 30, 3, 0));
    //Row 14
    levelMain->addBar(new bar(10 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 370, 15, 30, 5, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 370, 15, 30, 3, 0));
    //Row 16
    levelMain->addBar(new bar(10 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 340, 15, 30, 3, 0)); //all 2/3 block
    levelMain->addBar(new bar(160 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 340, 15, 30, 3, 0));
}

#endif
