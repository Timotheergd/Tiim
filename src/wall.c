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

	Wall wall = {
		.texture=NULL, // TODO
		.Edges2d=NULL, // [Line; 4] with Line = (Vec3, Vec3) -> Change to (vec2, vec2) ??
		.Edges3d=NULL, // [Plan; 4] with Plan = (Vec3, Vec3, Vec3)
		.height=height,
		.nbEdges2d=0,
		.nbEdges3d=0
	};

	// Compute edges

	// 2D

	Vec3 point1_3d = initVec3(coords.x+point1.x, coords.y+point1.y, coords.z);
	Vec3 point2_3d = initVec3(coords.x+point2.x, coords.y+point2.y, coords.z);
	Vec3 point3 = initVec3(coords.x+point1.x+point2.x, coords.y+point1.y+point2.y, coords.z);
	
	wall.nbEdges2d=4;
	wall.Edges2d=(Line*)realloc(wall.Edges2d, wall.nbEdges2d*sizeof(Line));
	wall.Edges2d[0] = initLine(coords, point1_3d);
	wall.Edges2d[1] = initLine(coords, point2_3d);
	wall.Edges2d[2] = initLine(point3, point1_3d);
	wall.Edges2d[3] = initLine(point3, point2_3d);	

	// 3D

	Vec3 w = initVec3(0, 0, height);

	// oposite vectors
	Vec3 Npoint1_3d = mulVec3(&point1_3d, -1);
	Vec3 Npoint2_3d = mulVec3(&point2_3d, -1);

	wall.nbEdges3d=4;
	wall.Edges3d=(Plan*)realloc(wall.Edges3d, wall.nbEdges3d*sizeof(Plan));
	wall.Edges3d[0] = initPlan(coords, point1_3d, w);
	wall.Edges3d[1] = initPlan(coords, point2_3d, w);
	wall.Edges3d[2] = initPlan(point3, Npoint1_3d, w);
	wall.Edges3d[3] = initPlan(point3, Npoint2_3d, w);

	return wall;
}


void printWall(Wall *w) {
	printf("Wall elements :\nheight=%d\n", w->height);
	printf("\n");
	for(int i=0; i < w->nbEdges2d; i++){
		printf("Line %d : ", i);
		printLine(&w->Edges2d[i]);
	}
	printf("\n");

	for(int i=0; i < w->nbEdges3d; i++){
		printf("\tPlan %d :\n", i);
		printPlan(&w->Edges3d[i]);
	}
	printf("\n");

}