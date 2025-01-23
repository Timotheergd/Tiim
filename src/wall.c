#include "wall.h"

Wall initWall(Vec3 coords,Vec2 point1, Vec2 point2, int height){
	Wall w = {
		.coords=coords,
		.point1=point1,
		.point2=point2,
		.height=height
	};
	return w;
}

