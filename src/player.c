#include "player.h"

// int* initMunitions(){
// 	int a[4] = {0, 0, 0, 0};
// 	return a;
// }

Player initPlayer(Vec3 c){
	Player p = {
		.coords=c,
		.radius=20,
		.height=50,
		.speed=4,
		.state=IDLE,
		.direction=initVec3(0, 0, 0),
		.health=100,
		.shield=0,
		.munitions=(int*) malloc(4*sizeof(int)),
		.guns=0,
		.actualGun=0,
		.keys=0
	};
	return p;
}

