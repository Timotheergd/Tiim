#include "monster.h"

// int* initMunitions(){
// 	int a[4] = {0, 0, 0, 0};
// 	return a;
// }

Monster initMonster(Coords c){
	Monster p = {
		.coords=c,
		.radius=20,
		.height=50,
		.speed=4,
		.state=IDLE,
		.direction=initCoords(0, 0, 0),
		.health=100,
		.guns=0
	};
	return p;
}

