#include "vec.h"

/***** VEC 2 *****/

Vec2 initVec2(float i, float j){
	Vec2 v = {i,j};
	return v;
}

void print_Vec2(Vec2 v){
    printf("v.x=%f, v.y=%f\n", v.x, v.y);
}

Vec2 addVec2(Vec2 *v1, Vec2 *v2){
	Vec2 v = initVec2(0, 0);
	v.x=v1->x+v2->x;
	v.y=v1->y+v2->y;
	return v;
}

Vec2 mulVec2(Vec2 *v1, float a){
	Vec2 v = initVec2(0, 0);
	v.x=v1->x*a;
	v.y=v1->y*a;
	return v;
}

/***** VEC 3 *****/

Vec3 initVec3(float i, float j, float k){
	Vec3 v = {i,j,k};
	return v;
}

void print_Vec3(Vec3 v){
    printf("v.x=%f, v.y=%f, v.z=%f\n", v.x, v.y, v.z);
}

Vec3 addVec3(Vec3 *v1, Vec3 *v2){
	Vec3 v = initVec3(0, 0, 0);
	v.x=v1->x+v2->x;
	v.y=v1->y+v2->y;
	v.z=v1->z+v2->z;
	return v;
}

// Vec3 mulVec3(Vec3 *v1, float a){
// 	Vec3 v = initVec3(0, 0, 0);
// 	v.x=v1->x*a;
// 	v.y=v1->y*a;
// 	v.z=v1->z*a;
// 	return v;
// }

// Written in asm just to flex :)
__asm__(".globl mulVec3\n\t"
        ".type func, @function\n\t"
		"mulVec3:\n\t"
		".cfi_startproc\n\t"
		"movaps %xmm0,%xmm1\n\t"
		"movq   (%rdi),%xmm0\n\t"
		"movaps %xmm1,%xmm2\n\t"
		"shufps $0xe0,%xmm2,%xmm2\n\t"
		"mulss  0x8(%rdi),%xmm1\n\t"
		"mulps  %xmm2,%xmm0\n\t"
		"ret\n\t"
		"nopw   0x0(%rax,%rax,1)  \n\t"
		".cfi_endproc"
);

Vec3 Vec3projToXY(Vec3 *v){
	Vec3 vxy = initVec3(v->x, v->y, 0);
	return vxy;
}