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

#endif