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

bool gameStart = false;
bool oneHit = true;
int data[] = {0};

paddle *paddleMain = new paddle(200.0, 10.0, 10.0, 80.0, 0, 1, 1);
ball *ballMain = new ball((paddleMain->x + (paddleMain->w / 2)), (paddleMain->y + paddleMain->h + 4), 0, 1, 0, 8, 8, 4, 1, 0, 1);
level *levelMain = new level();

void levelOne(){//create the blocks
    levelMain->addBar(new bar(10 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(160 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 580, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 580, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 580, 15, 30, 3, 0));
    //Row 2
    levelMain->addBar(new bar(10 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(160 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 550, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 550, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 550, 15, 30, 5, 0));

    //Row 2
    levelMain->addBar(new bar(10 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(160 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 520, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 520, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 520, 15, 30, 3, 0));
    //Row 3
    levelMain->addBar(new bar(10 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(160 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 490, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 490, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 490, 15, 30, 5, 0));
    //Row 4
    levelMain->addBar(new bar(10 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(160 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 460, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 460, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 460, 15, 30, 3, 0));
    //Row 5
    levelMain->addBar(new bar(10 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(160 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 430, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 430, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 430, 15, 30, 5, 0));
    //Row 6
    levelMain->addBar(new bar(10 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(160 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 400, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 400, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 400, 15, 30, 3, 0));
    //Row 7
    levelMain->addBar(new bar(10 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(60 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(110 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(160 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(210 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(260  , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(310 , 370, 15, 30, 5, 0));
    levelMain->addBar(new bar(360 , 370, 15, 30, 3, 0));
    levelMain->addBar(new bar(410 , 370, 15, 30, 3, 0));
    //Row 8
    levelMain->addBar(new bar(10 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(60 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(110 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(160 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(210 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(260  , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(310 , 340, 15, 30, 3, 0));
    levelMain->addBar(new bar(360 , 340, 15, 30, 5, 0));
    levelMain->addBar(new bar(410 , 340, 15, 30, 3, 0));
}

#endif
