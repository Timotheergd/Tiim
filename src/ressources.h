#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Constants

#define FPS 60

// Additional Structs / Enums

typedef enum State State;
enum State
{
	IDLE, WALKING, RUNNING, CHASSING
};

typedef struct Coords Coords;
struct Coords {
	int x;
	int y;
    int z;
};

// typedef enum Entity Entity;
// enum {
//     WALL = '1',
//     PLAYER = '2',
//     GHOST = '3',
//     GUM = '4',
//     BIGGUM = '5',
//     GATE = '6',
//     GHOST_RESPAWN = '7'
// };

Coords initCoords(int i, int j, int k);
void print_Coords(Coords c);
Coords incrCoords(Coords coords, Coords dir, int speed);

#endif