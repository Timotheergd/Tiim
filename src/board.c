#include "board.h"

Board initBoard(){
	Board b = {
        .player=initPlayer(initVec3(0,0,0)), 
        .wall_list=NULL,
        .nbWall = 0
    };
	return b;
}

void printBoardContent(Board *board){
    printf("Board content :\n");

    printf("walls\n");
    for(int i=0;i<board->nbWall;i++){
        printWall(&board->wall_list[i]);
    }

    printf("player\n");
    print_Vec3(board->player.coords);

}

void loadLevel(char filename[50], Board *board){
    // Open file
	FILE* level_file = fopen(filename, "r");
    if (level_file == NULL) {
        printf("no such file. : %s\n", filename);
        return 1;
    }

    // Reset the board
    board->wall_list=NULL;
    board->nbWall = 0;

    /* Assuming that test.txt has content
       in below format :
       Type Variation Style	Trigger x y z R dz dx1 dy1 dx2 dy2 Vx Vy Vz
     */
    char type;
    int variation, style, trigger, x, y, z, R, dz, dx1, dy1, dx2, dy2, Vx, Vy, Vz;

    /*printf("Contents of the File are:\n");
    while (fscanf(level_file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &type, &variation, &style, &trigger, &x, &y, &z, &R, &dz, &dx1, &dy1, &dx2, &dy2, &Vx, &Vy, &Vz) == 16) {
        // printf("Name: %s\t   Age: %d\n", &name, &age);
        switch(type) {
            case 'W':
                printf("\n\n\n\nwall :)\n");
                printf("Wall is Variation: %d\n Style: %d\n Trigger: %d\n x: %d\n y: %d\n z: %d\n R: %d\n dz: %d\n dx1: %d\n dy1: %d\n dx2: %d\n dy2: %d\n Vx: %d\n Vy: %d\n Vz: %d\n", variation, style, trigger, x, y, z, R, dz, dx1, dy1, dx2, dy2, Vx, Vy, Vz);
                break;
            default:
                printf("Type: %s\n Variation: %d\n Style: %d\n Trigger: %d\n x: %d\n y: %d\n z: %d\n R: %d\n dz: %d\n dx1: %d\n dy1: %d\n dx2: %d\n dy2: %d\n Vx: %d\n Vy: %d\n Vz: %d\n", type, variation, style, trigger, x, y, z, R, dz, dx1, dy1, dx2, dy2, Vx, Vy, Vz);
                break;
        }   
    }   */
    // Read until end of file
    while (!feof(level_file)) {
        // Peek at first character
        type = fgetc(level_file);
        
        // Check for end of file
        if (type == EOF) break;
        
        // Put the character back
        ungetc(type, level_file);

        switch(type) {
            case '\n': // Skip char on newline
                type = fgetc(level_file);
                break;
            case 'W': // Process Wall-type line
                fscanf(level_file, "%s %d %d %d %d %d %d %d %d %d",
                        &type, &style, &x, &y, &z, &dz, &dx1, &dy1, &dx2, &dy2);
                // printf("Wall is\nStyle: %d\n x: %d\n y: %d\n z: %d\n dz: %d\n dx1: %d\n dy1: %d\n dx2: %d\n dy2: %d\n",
                //         style, x, y, z, dz, dx1, dy1, dx2, dy2);

                Vec3 coords = initVec3(x, y, z);
                Vec2 point1 = initVec2(dx1, dy1);
                Vec2 point2 = initVec2(dx2, dy2);
                Wall w = initWall(coords, point1, point2, dz);
                // printf("size of walls in read level = \n");
                // walls[*walls_size] = &w;//initWall(coords, point1, point2, dz);
                // *walls_size+=1;
                // printWall(&w);
                board->nbWall+=1;
                board->wall_list=(Wall*)realloc(board->wall_list, board->nbWall*sizeof(Wall));
                (board->wall_list)[board->nbWall-1]=w;
                break;
                
            case 'P': // Process Playre-type line
                fscanf(level_file, "%s %d %d %d %d", 
                        &type, &x, &y, &z, &dz);
                // printf("Player is\n: %d\n y: %d\n z: %d\n dz: %d\n",
                //         x, y, z, dz);
                break;
                
            default:
                printf("Error: Invalid line format starting with '%c'\n", type);
                // Skip to next line
                char buffer[1000];
                fgets(buffer, sizeof(buffer), level_file);
                break;
        }
    }

    fclose(level_file);
}



