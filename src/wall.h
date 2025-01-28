#ifndef WALL_H
#define WALL_H

#include "ressources.h"
#include "vec.h"
#include "physic.h"

typedef struct Wall Wall;
struct Wall {
	unsigned char* texture;
	Line *Edges2d; // [Line; 4] with Line = (Vec2, Vec2)
	Plan *Edges3d; // [Plan; 4] with Plan = (Vec3, Vec3, Vec3) // Do not contain ceiling and floor
	int height;
	int nbEdges2d;
	int nbEdges3d;
};

Wall initWall(Vec3 coords,Vec2 point1, Vec2 point2, int height);
void printWall(Wall *w);

#endif