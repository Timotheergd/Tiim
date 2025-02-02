#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "ressources.h"
#include "player.h"


void setViewMode(int* viewMode);
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
float normalizeAngle(float angle);
void drawCameraPosition();
//void drawCube();


#endif