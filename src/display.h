#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "ressources.h"
#include "player.h"
#include "board.h"

#define PLAYER_INDICATOR_SIZE_2D 70


void setViewMode(int* viewMode);
void renderBitmapString(float x, float y, float z, void *font, char *string);
void restorePerspectiveProjection();
void setOrthographicProjection();
void display();
void drawFPS();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
float normalizeAngle(float angle);
void drawBoard(Board* board);
void drawWall(Wall* wall);
void drawCameraPosition();
//void drawCube();


#endif