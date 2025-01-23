#include "pillar.h"

Pillar initPillar(Vec3 coords,int radius, int height){
	Pillar w = {
		.texture=NULL, // TODO
		.coords=coords,
		.radius=radius,
		.height=height
	};
	return w;
}

