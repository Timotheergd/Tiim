#ifndef PHYSIC_H
#define PHYSIC_H

#include "ressources.h"
#include "vec.h"

// Also works for 2D line by setting one of the parameter to 0. (ex: z=0 for both points)
typedef struct Line Line;
struct Line {
	Vec3 point1;
	Vec3 point2;
};

Line initLine(Vec3 point1, Vec3 point2);
Line projLineToXY(Line* line);
void printLine(Line* l);

// INTERSECTIONS
/*
https://en.wikipedia.org/wiki/Intersection_(geometry)#Two_surfaces
https://en.wikipedia.org/wiki/Three-dimensional_space#Lines_and_planes
https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection#Parametric_form

*/


// The plan is more like a surface. It has boundaries
typedef struct Plan Plan;
struct Plan {
	Vec3 r; // vec of the origin of the plan
	Vec3 v;
	Vec3 w;
};

Plan initPlan(Vec3 r, Vec3 v, Vec3 w);
void printPlan(Plan* p);

#endif