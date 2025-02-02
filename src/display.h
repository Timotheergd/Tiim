#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "ressources.h"
#include "player.h"
#include "board.h"

#define PLAYER_INDICATOR_SIZE_2D 2000


void setViewMode(int* viewMode);
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
float normalizeAngle(float angle);
void drawBoard(Board* board);
void drawWall(Wall* wall);
void drawCameraPosition();
//void drawCube();


#endif