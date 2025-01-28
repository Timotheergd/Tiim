#ifndef VEC_H
#define VEC_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// TODO :
// for Vec2 and Vec3, make dot product, addition, ... basic vector operations


/***** VEC 2 *****/

typedef struct Vec2 Vec2;
struct Vec2 {
	int x;
	int y;
};

Vec2 initVec2(int i, int j);
void print_Vec2(Vec2 v);
Vec2 addVec2(Vec2 *v1, Vec2 *v2);
Vec2 mulVec2(Vec2 *v1, int a);


/***** VEC 3 *****/

typedef struct Vec3 Vec3;
struct Vec3 {
	int x;
	int y;
    int z;
};

Vec3 initVec3(int i, int j, int k);
void print_Vec3(Vec3 v);
Vec3 addVec3(Vec3 *v1, Vec3 *v2);
Vec3 mulVec3(Vec3 *v1, int a);
Vec3 Vec3projToXY(Vec3 *v);

#endif