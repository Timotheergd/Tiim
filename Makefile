# A simple Makefile

# set the compiler
CC := gcc

# source files path
SRC_DIRS := ./src

# set the compiler flags
CFLAGS := -lGL -lGLU -lglut -lm

WARNINGFLAGS := -w

# name of executable
EXEC := tiim

clean:
	@ rm -f $(EXEC)

compile:
# $(CC) main.c $(SRC_DIRS)/*.c -o $(EXEC) $(CFLAGS) -ldl -lglfw
	$(CC) main.c $(SRC_DIRS)/*.c -o $(EXEC) $(CFLAGS) $(WARNINGFLAGS)

run:
	@ ./$(EXEC)

# clear the terminal
clear:
	clear

all: clear compile run clean