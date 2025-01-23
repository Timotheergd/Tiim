#ifndef PLAYER_H
#define PLAYER_H

#include "ressources.h"
#include "time.h"
#include <stdlib.h>

typedef struct Player Player;
struct Player {
	Coords coords;
	int radius;
	int height;
	int speed;
	State state;
	Coords direction;
	int health;
	int shield;
	int *munitions;
	int guns;
	int actualGun; // 0 = fist
	int keys;
};
/*
guns
|Name  		 |flag|
|pistol		 |0001|
|pompe       |0010|
|mitraillette|0100|
|boule  	 |1000|

keys
|Name  	|flag|
|Blue	|001|
|Red    |010|
|Yellow |100|
*/
Player initPlayer(Coords c);


#endif