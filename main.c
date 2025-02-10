#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <float.h>

#include <GL/glut.h>

#include "./src/ressources.h"
#include "./src/vec.h"
#include "./src/physic.h"
#include "./src/player.h"
#include "./src/monster.h"
#include "./src/wall.h"
#include "./src/board.h"
#include "./src/display.h"

int main(int argc, char **argv){

  /* TODO

  - Clean display.c & display.h
  - Add function to transform pixel coords to GL coords
      => the coords of the objects are stored in pixel in 2D view

  - Display all the board in 2D
  - Display all the board in 3D
  
  */


	printf("Doom Like - Tiim\n");

  Vec3 p1 = initVec3(1, 3, 0);
  Vec3 p2 = initVec3(11, 4, 0);
  Vec2 p3 = initVec2(6, 1);
  Line l = initLine(p1, p2);
  float d = distanceLinePoint(l, p3);
  printf("distance = %f\n", d);

  /***** INITIALIZATION *****/

  char level_file[50]="./levels/test.lvl";
  Board board=initBoard();
  loadLevel(level_file, &board);

  printBoardContent(&board);


  /***** DISPLAY ******/
  int viewMode = 0;
  setViewMode(&viewMode);

  printf("main player x = %.2f\n", board.player.coords.x);

  setPlayer(&(board.player));
  setBoard(&board);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Timm ~ Doom-like ~ still in progress...");

  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  glutMainLoop();



	return 0;
}