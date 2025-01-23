#ifndef STEP_H
#define STEP_H

#include "ressources.h"

typedef struct Step Step;
struct Step {
	unsigned char* texture;
	Vec3 coords;
	Vec2 point1;
	Vec2 point2;
	int height;
	int damage;
};

Step initStep(Vec3 coords,Vec2 point1, Vec2 point2, int height);

#endif