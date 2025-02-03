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
		.direction=initVec3(0, 180, 0),
		.rotSpeed=5,
		.health=100,
		.shield=0,
		.munitions=(int*) malloc(4*sizeof(int)),
		.guns=0,
		.actualGun=0,
		.keys=0
	};
	return p;
}

void printPlayer(Player p) {
	printf("Player : speed=%d, rotSpeed=%d\n", p.speed, p.rotSpeed);
	printf("\tcoords : ");
	print_Vec3(p.coords);
	printf("\tdirection : ");
	print_Vec3(p.direction);
}

