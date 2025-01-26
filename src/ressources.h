#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Constants

#define FPS 60


// TODO :
// for Vec2 and Vec3, make dot product, addition, ... basic vector operations

// Additional Structs / Enums

typedef enum State State;
enum State
{
	IDLE, WALKING, RUNNING, CHASSING
};

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

typedef struct Vec2 Vec2;
struct Vec2 {
	int x;
	int y;
};

Vec2 initVec2(int i, int j);
void print_Vec2(Vec2 v);
Vec2 addVec2(Vec2 *v1, Vec2 *v2);
Vec2 mulVec2(Vec2 *v1, int a);


#endif