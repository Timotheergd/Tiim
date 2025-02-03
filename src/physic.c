#include "physic.h"

Line initLine(Vec3 point1, Vec3 point2){	

	Line l = {
		.point1=point1,
		.point2=point2
	};
	return l;
}

Line LineTo2D(Line* line){
	Line l = {
		.point1 = initVec3(line->point1.x, line->point1.y, 0),
		.point2 = initVec3(line->point2.x, line->point2.y, 0),
	};
	return l;
}

void printLine(Line* l){
	// printf("point1 = ");
	// print_Vec3(l->point1);
	// printf("point2 = ");
	// print_Vec3(l->point2);
	// printf("\n");
	printf("(%.2f, %.2f, %.2f) -> (%.2f, %.2f, %.2f)\n", l->point1.x, l->point1.y, l->point1.z, l->point2.x, l->point2.y, l->point2.z);

}


Plan initPlan(Vec3 coords, Vec3 v, Vec3 w){

	printf("Init Plan : v (%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
	Plan p = {
		.r=coords,
		.v=v,
		.w=w
	};
	return p;
}

void printPlan(Plan* p){
	printf("r = ");
	print_Vec3(p->r);
	printf("v = ");
	print_Vec3(p->v);
	printf("w = ");
	print_Vec3(p->w);
	printf("\n");
}