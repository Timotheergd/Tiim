#ifndef BOARD_H
#define BOARD_H

#include "ressources.h"
#include "vec.h"
#include "physic.h"
#include "player.h"
#include "wall.h"
#include "physic.h"


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

// Collisions
bool wallCollision(Player p, Board *board);

#endif