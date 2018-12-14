#include "game.h"

void vec2_norm(float& x, float &y){
    float length = sqrt((x * x) + (y * y));
    if (length != 0.0f) {
        length = 1.0f / length;
        x *= length;
        y *= length;
    }
}

string scoring(int x){ //Converts int to string
    stringstream ss;
    ss << x;
    return ss.str( );
}

void Text(float x, float y, const char* text){
    const char *c;
    glRasterPos2f(x, y);
    for (c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void enable2D(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

static void key(unsigned char key, int x, int y){
    if (key == ' ' && lives != 0) {
        ballMain->speed = 5;
        gameStart = true;
    }
    if (key == 'r') {  //Restart Level
        levelMain->bars.clear();
        levelOne();
        ballMain->speed = 0;
        ballMain->x = (paddleMain->x + (paddleMain->w / 2));
        ballMain->y = (paddleMain->y + paddleMain->h + 4);
        ballMain->dirY = fabs(ballMain->dirY);
        ballMain->dirX = 0;
        gameStart = false;
        levelNow = 1;
        lives = 3;
        score = 0;
    }
    glutPostRedisplay();
}

void mouseMove(int x, int y){
    if (x < (paddleMain->w / 2)) {
        paddleMain->x = 0;
    } else if ( x > (width - (paddleMain->w / 2))) {
        paddleMain->x = (width - (paddleMain->w));
    } else {
        paddleMain->x = x - (paddleMain->w / 2);
    }
    if (!gameStart) {
        ballMain->x = paddleMain->x + (paddleMain->w / 2);
    }
}

void mouseButton(int button, int state, int x, int y)
{

}
void updateBall(){
    ballMain->x += ballMain->dirX * ballMain->speed;
    ballMain->y += ballMain->dirY * ballMain->speed;

    if (paddleMain->contact(ballMain)) {
        float t = ((ballMain->x - paddleMain->x) / paddleMain->w) - 0.5f;
        ballMain->dirY = fabs(ballMain->dirY);
        ballMain->dirX = t;
    }
    int blocksLeft = 0;
    for (vector<bar*>::iterator i = levelMain->bars.begin(); i != levelMain->bars.end(); ++i) {
        if ((*i)->isHit(ballMain)) {
            if ((*i)->health != 0) {
                float t = ((ballMain->x - (*i)->x) / (*i)->w) - 0.5f;
                float z = ((ballMain->y - (*i)->y) / (*i)->h) - 0.5f;
                if (ballMain->dirY < 0) {
                    ballMain->dirY = -z;
                } else {
                    ballMain->dirY = z;
                }

                ballMain->dirX = t;
                if (oneHit) {
                    (*i)->health = 0;
                } else {
                    (*i)->health--;
                }
                if ((*i)->health == 0) {
                    score += 10;
                }
            }
        }
        if ((*i)->health != 0) {
            blocksLeft++;
        }
    }
    if (blocksLeft == 0) {
        levelMain->bars.clear();
        levelNow++;
        if (levelNow == 1) {
            levelOne();
        }
        ballMain->speed = 0;
        ballMain->x = (paddleMain->x + (paddleMain->w / 2));
        ballMain->y = (paddleMain->y + paddleMain->h + 4);
        ballMain->dirY = fabs(ballMain->dirY);
        ballMain->dirX = 0;
        gameStart = false;
    }
   //If Left/Right/Top/Bottom Wall (in that order) have been hit
    if (ballMain->x < 0) {
        ballMain->dirX = fabs(ballMain->dirX);
    }
    if (ballMain->x > width) {
        ballMain->dirX = -fabs(ballMain->dirX);
    }
    if (ballMain->y > height) {
        ballMain->dirY = -fabs(ballMain->dirY);
    }
    if (ballMain->y < 0) {
        --lives;
        score -= 20;
        gameStart = false;
        ballMain->speed = 0;
        ballMain->x = (paddleMain->x + (paddleMain->w / 2));
        ballMain->y = (paddleMain->y + paddleMain->h + 4);
        ballMain->dirY = fabs(ballMain->dirY);
        ballMain->dirX = 0;
    }
    vec2_norm(ballMain->dirX, ballMain->dirY);
}
void update(int value){
    updateBall();
    glutTimerFunc(interval, update, 0);
    glutPostRedisplay();
}
void draw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if (lives > 0) {
        paddleMain->draw();
        ballMain->draw();
        levelMain->draw();
    } else {
        levelMain->bars.clear();
        gameOverDraw();
        ballMain->speed = 0;
        ballMain->x = (paddleMain->x + (paddleMain->w / 2));
        ballMain->y = (paddleMain->y + paddleMain->h + 4);
        ballMain->dirY = fabs(ballMain->dirY);
        ballMain->dirX = 0;
        gameStart = false;
        lives = 3;
        score = 0;
    }
   //Lives
    glColor3f(1.0f, 1.0f, 1.0f);
    Text(14, height - 15,
             ("Lives: " + scoring(lives) + "                                                                                               Score: " + scoring(score)).c_str());
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Brick Breaker");
    // Register callback functions
    glutKeyboardFunc(key);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutDisplayFunc(draw);
    glutTimerFunc((1000 / 60), update, 0);
    
    levelOne();
    enable2D(width, height);
    glColor3f(1.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}

