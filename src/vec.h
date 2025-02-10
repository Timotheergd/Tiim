#ifndef VEC_H
#define VEC_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/***** VEC 2 *****/

// typedef struct Vec2 Vec2;
typedef struct {
	float x;
	float y;
} Vec2;


Vec2 initVec2(float i, float j);
void print_Vec2(Vec2 v);
Vec2 addVec2(Vec2 *v1, Vec2 *v2);
Vec2 mulVec2(Vec2 *v1, float a);
Vec2 absVec2(Vec2 v);
float dist(Vec2 v1, Vec2 v2);
float crossProduct2D(Vec2 a, Vec2 b);
float triangleArea(Vec2 a, Vec2 b, Vec2 c);

/***** VEC 3 *****/

typedef struct Vec3 Vec3;
struct Vec3 {
	float x;
	float y;
    float z;
};

Vec3 initVec3(float i, float j, float k);
void print_Vec3(Vec3 v);
Vec3 addVec3(Vec3 *v1, Vec3 *v2);
Vec3 subVec3(Vec3 *v1, Vec3 *v2);
Vec3 absSubVec3(Vec3 *v1, Vec3 *v2);
Vec3 mulVec3(Vec3 *v1, float a);
Vec3 absVec3(Vec3 v);
Vec3 Vec3projToXY(Vec3 v);
float dotV3(Vec3 u, Vec3 v);

/*****************/


Vec2 Vec2FromVec3(Vec3 v);


#endif