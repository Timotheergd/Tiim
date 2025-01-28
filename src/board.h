#ifndef BOARD_H
#define BOARD_H

#include "ressources.h"
#include "physic.h"
#include "player.h"
#include "wall.h"


// store every objects of the map
typedef struct Board Board;
struct Board {
	Player player;
	Wall *wall_list;
    int nbWall;
};



// Board
Board initBoard();
void printBoardContent(Board *board); // for debugging
void loadLevel(char filename[50], Board *board);
void freeBoard(Board *board);

#endif