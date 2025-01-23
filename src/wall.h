#ifndef WALL_H
#define WALL_H

#include "ressources.h"

typedef struct Wall Wall;
struct Wall {
	unsigned char* texture;
	Vec3 coords;
	Vec2 point1;
	Vec2 point2;
	int height;
};

Wall initWall(Vec3 coords,Vec2 point1, Vec2 point2, int height);

#endif