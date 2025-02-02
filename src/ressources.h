#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Constants

#define FPS 60
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Additional Structs / Enums

typedef enum State State;
enum State
{
	IDLE, WALKING, RUNNING, CHASSING
};

#endif