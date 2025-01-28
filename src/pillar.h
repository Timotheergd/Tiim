#ifndef PILLAR_H
#define PILLAR_H

#include "ressources.h"
#include "vec.h"

typedef struct Pillar Pillar;
struct Pillar {
	unsigned char* texture;
	Vec3 coords;
	int radius;
	int height;
};

Pillar initPillar(Vec3 coords,int radius, int height);

#endif