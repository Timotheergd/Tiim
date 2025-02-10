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



Circle initCircle(Vec3 coords, float r){
	Circle c = {
		.coords=coords,
		.radius=r,
	};
	return c;
}

void printCircle(Circle* c){
	printf("coords = ");
	print_Vec3(c->coords);
	printf("radius = %f\n", c->radius);
}


float distanceLinePoint(Line line, Vec2 point) {
	// https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
	// printf("begin distanceLinePoint\n");
	float x0 = point.x;
	float y0 = point.y;
	float x1 = line.point1.x;
	float x2 = line.point2.x;
	float y1 = line.point1.y;
	float y2 = line.point2.y;

	float d = fabs((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1) / sqrt(pow(y2-y1, 2) + pow(x2-x1, 2));
	// printf("distanceLinePoint = %f\n", d);
	// printf("end distanceLinePoint\n");
	return d;
}

bool collisionLineCircle(Line line, Circle circle) {
	return distanceLinePoint(line, Vec2FromVec3(circle.coords)) < circle.radius;
}


bool collisionSegmentCircle(Line line, Circle circle) {
	// Algo from :
	// https://www.baeldung.com/cs/circle-line-segment-collision-detection
	float min_dist = FLT_MAX;
	float max_dist = fmax(dist(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point1)),
						  dist(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point2))
						);
	
	if ((dotV3(Vec3projToXY(subVec3(&line.point1, &circle.coords)),Vec3projToXY(subVec3(&line.point1, &line.point2))) > 0)		// Dot(OP, QP) > 0
	 && (dotV3(Vec3projToXY(subVec3(&line.point2, &circle.coords)),Vec3projToXY(subVec3(&line.point2, &line.point1))) > 0) ) {	// and Dot(OQ, PQ) > 0
		min_dist = 2 * triangleArea(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point1), Vec2FromVec3(line.point2)) / dist(Vec2FromVec3(line.point1), Vec2FromVec3(line.point2));
	}
	else {
		min_dist = fmin(dist(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point1)), dist(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point2)));
	}

	printf("Distances max = %f - min = %f\t=> collide ? %d \t\tDist proj = %f\n", max_dist, min_dist, (min_dist <= circle.radius) && (max_dist >= circle.radius), (2 * triangleArea(Vec2FromVec3(circle.coords), Vec2FromVec3(line.point1), Vec2FromVec3(line.point2)) / dist(Vec2FromVec3(line.point1), Vec2FromVec3(line.point2))));

	return (min_dist <= circle.radius) && (max_dist >= circle.radius);
}
