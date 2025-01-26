#include "wall.h"

Wall initWall(Vec3 coords,Vec2 point1, Vec2 point2, int height){
	
	/* View
	^ z                                   + point4
	|                                    |
	|                                    |  } height
	|                                    |
	|         point1 +-------------------+ point3
	|               /                   /
	|     x        /                   /
	|    ^        /                   /
	|   /        /                   /
	|  / coords +-------------------+  point2
	| /
	+--------------------------------------> y
	*/

	// Compute edges

	// 2D

	Vec3 point1_3d = initVec3(coords.x+point1.x, coords.y+point1.y, coords.z);
	Vec3 point2_3d = initVec3(coords.x+point2.x, coords.y+point2.y, coords.z);
	
	Line line1 = initLine(coords, point1_3d);
	Line line2 = initLine(coords, point2_3d);
	
	Vec3 point3 = initVec3(point1_3d.x, point2_3d.y, coords.z);

	Line line4 = initLine(point3, point2_3d);	
	Line line3 = initLine(point3, point1_3d);

	Line Edges2d[4] = {line1, line2, line3, line4};

	// 3D

	Vec3 w = initVec3(0, 0, height);

	// negative vectors
	Vec3 Npoint1_3d = mulVec3(point1_3d, -1);
	Vec3 Npoint2_3d = mulVec3(point2_3d, -1);

	Plan plan1 = initPlan(coords, point1_3d, w);
	Plan plan2 = initPlan(coords, point2_3d, w);

	Plan plan2 = initPlan(point3, Npoint1_3d, w);
	Plan plan4 = initPlan(point3, Npoint2_3d, w);

	Plan Edges3d[4] = {plan1, plan2, plan3, plan4};


	Wall w = {
		.texture=NULL, // TODO
		.Edges2d=Edges2d, // [Line; 4] with Line = (Vec3, Vec3) -> Change to (vec2, vec2) ??
		.Edges3d=Edges3d, // [Plan; 4] with Plan = (Vec3, Vec3, Vec3)
		.height=height
	};
	return w;
}

