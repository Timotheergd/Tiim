#ifndef MONSTER_H
#define MONSTER_H

#include "ressources.h"
#include "time.h"
#include <stdlib.h>

typedef struct Monster Monster;
struct Monster {
	Coords coords;
	int radius;
	int height;
	int speed;
	State state;
	Coords direction;
	int health;
	int guns;
};
/*
guns
|Name  		 |flag|
|pistol		 |0001|
|pompe       |0010|
|mitraillette|0100|
|boule  	 |1000|
*/
Monster initMonster(Coords c);


#endif