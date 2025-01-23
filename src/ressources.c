#include "ressources.h"

Coords initCoords(int i, int j, int k){
	Coords coords = {i,j,k};
	return coords;
}

void print_Coords(Coords c){
    printf("c.x=%d, c.y=%d\n, c.z=%d\n", c.x, c.y, c.z);
}

Coords incrCoords(Coords coords, Coords dir, int speed){
	coords.x+=dir.x;
	coords.y+=dir.y;
	coords.z+=dir.z;
	return coords;
}