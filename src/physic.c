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


Plan initPlan(Vec3 point1, Vec3 point2, Vec3 point3){

	Vec3 minusP1 = mulVec3(&point1, -1);

	Plan p = {
		.r=point1,
		.v=addVec3(&point2, &minusP1),
		.w=addVec3(&point3, &minusP1)
	};
	return p;
}

