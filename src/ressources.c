#include "ressources.h"

Vec3 initVec3(int i, int j, int k){
	Vec3 v = {i,j,k};
	return v;
}

void print_Vec3(Vec3 v){
    printf("v.x=%d, v.y=%d\n, v.z=%d\n", v.x, v.y, v.z);
}

Vec3 addVec3(Vec3 *v1, Vec3 *v2){
	Vec3 v = initVec3(0, 0, 0);
	v.x=v1->x+v2->x;
	v.y=v1->y+v2->y;
	v.z=v1->z+v2->z;
	return v;
}

Vec3 mulVec3(Vec3 *v1, int a){
	Vec3 v = initVec3(0, 0, 0);
	v.x=v1->x*a;
	v.y=v1->y*a;
	v.z=v1->z*a;
	return v;
}

Vec3 Vec3projToXY(Vec3 *v){
	Vec3 vxy = initVec3(v->x, v->y, 0);
	return vxy;
}


Vec2 initVec2(int i, int j){
	Vec2 v = {i,j};
	return v;
}

void print_Vec2(Vec2 v){
    printf("v.x=%d, v.y=%d\n", v.x, v.y);
}

Vec2 addVec2(Vec2 *v1, Vec2 *v2){
	Vec2 v = initVec2(0, 0);
	v.x=v1->x+v2->x;
	v.y=v1->y+v2->y;
	return v;
}

Vec2 mulVec2(Vec2 *v1, int a){
	Vec2 v = initVec2(0, 0);
	v.x=v1->x*a;
	v.y=v1->y*a;
	return v;
}