#include "step.h"

Step initStep(Vec3 coords,Vec2 point1, Vec2 point2, int height){
	Step w = {
		.texture=NULL, // TODO
		.coords=coords,
		.point1=point1,
		.point2=point2,
		.height=height,
		.damage=5
	};
	return w;
}

