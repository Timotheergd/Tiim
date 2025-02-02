#include "display.h"

static int* g_viewModePtr = NULL;

void setViewMode(int* viewMode) {
    g_viewModePtr = viewMode;
}

static Player* g_playerPtr = NULL;

void setPlayer(int* player) {
    g_playerPtr = player;
}

static Board* g_boardPtr = NULL;

void setBoard(int* board) {
    g_boardPtr = board;
}


void display() {
    if(!g_viewModePtr) {
        printf("g_viewModePtr not defined ! Does not go further in display\n");
        return 1;
    }
    if(!g_playerPtr) {
        printf("g_playerPtr not defined ! Does not go further in display\n");
        return 1;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    printf("ViewMode = %d\n", *g_viewModePtr);
    // printf("player x = %d\n", g_playerPtr->coords.x);
    printPlayer(*g_playerPtr);


    // Print camera position and rotation
    // printf("Camera Position: (%.2f, %.2f, %.2f) Rotation: (%.2f, %.2f)\n",
    //        g_playerPtr->coords.x, g_playerPtr->coords.y, g_playerPtr->coords.z, camRotX, g_playerPtr->direction.y);
    // *g_viewModePtr = *g_viewModePtr + 1;

    if (*g_viewModePtr == 0) {
        // 3D View

        // Set camera view
        // float lookX = g_playerPtr->coords.x + cos(g_playerPtr->direction.y * M_PI / 180.0f);
        // float lookY = g_playerPtr->coords.y + sin(g_playerPtr->direction.y * M_PI / 180.0f);
        // float lookZ = g_playerPtr->coords.z + sin(camRotX * M_PI / 180.0f);
        
        // gluLookAt(g_playerPtr->coords.x, g_playerPtr->coords.y, g_playerPtr->coords.z,      // Camera position
        //           lookX, lookY, lookZ,    // Look at point
        //           0.0f, 0.0f, .0f);     // Up vector (Z is up)
    } else {
        // 2D Top View (looking down the Z axis)


        // ***** Set camera view *****

        float diam = g_playerPtr->radius/100;
        //8.070 
        float zNear = 1.0;
        float zFar = zNear + diam;

        GLdouble left = - diam;
        GLdouble right =  diam;
        GLdouble bottom = - diam;
        GLdouble top = + diam;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(left, right, bottom, top, zNear, zFar);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        gluLookAt(0.0f, 0.0f, 1.0f,    // Camera high above on Z axis
                  0.0f, 0.0f, 0.0f,    // Looking at origin
                  0.0f, 1.0f, 0.0f);   // Up vector

    }

    

    // Draw each element
    // drawCube();
    drawCameraPosition();
    drawBoard(g_boardPtr);
    
    glutSwapBuffers();
}




// Normalize angle to 0-360 range
float normalizeAngle(float angle) {
    angle = fmod(angle, 360.0f);
    if (angle < 0) {
        angle += 360.0f;
    }
    return angle;
}

void drawBoard(Board* board) {
        // Draw Walls
        for(int i=0; i<board->nbWall; i++) {
            drawWall(&board->wall_list[i]);
            // printf("drawing line %d.....\n", i);
            // printWall(&board->wall_list[i]);
        }
}

void drawWall(Wall* wall) {
    if(!g_viewModePtr) {
        printf("g_viewModePtr not defined ! Does not go further in drawBoard\n");
        return 1;
    }
    if (*g_viewModePtr == 1) {
        // 2D view
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);        
        for(int i=0; i<4; i++) {
            glVertex3f(wall->Edges2d[i].point1.x * 2 /  (float)WINDOW_WIDTH, wall->Edges2d[i].point1.y * 2 /  (float)WINDOW_HEIGHT, 0);
            glVertex3f(wall->Edges2d[i].point2.x * 2 /  (float)WINDOW_WIDTH, wall->Edges2d[i].point2.y * 2 /  (float)WINDOW_HEIGHT, 0);
        }
        glEnd();
    }
    else {
        // 3D view
    }
}

/*
void drawCube() {
    if (viewMode == 1) {
        // 2D view - draw with GL_LINE_LOOP (top view)
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glEnd();
    } else {
        // 3D view - draw with GL_QUADS
        glBegin(GL_QUADS);
        // Front face (red)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Back face (green)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        // Top face (blue)
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // Bottom face (yellow)
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);

        // Right face (magenta)
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);

        // Left face (cyan)
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glEnd();
    }
}
*/

void drawCameraPosition() {
    if(!g_viewModePtr) {
        printf("g_viewModePtr not defined ! Does not go further in display\n");
        return 1;
    }
    if(!g_playerPtr) {
        printf("g_playerPtr not defined ! Does not go further in display\n");
        return 1;
    }

    if (*g_viewModePtr == 1) {
        // Draw camera position indicator in 2D view (top-down)
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);  // White color
            // glTranslatef(0.0f, 0.0f, 0.0f);
   
            // Draw position indicator
            glPointSize(10.0f);
            glBegin(GL_POINTS);
                // TODO : make a function to get this coords
                glVertex2f(g_playerPtr->coords.x * 2 /  (float)WINDOW_WIDTH, g_playerPtr->coords.y * 2 / (float)WINDOW_HEIGHT);
            glEnd();
            
            // Draw direction indicator
            float dx = cos(g_playerPtr->direction.y * M_PI / 180.0f) * PLAYER_INDICATOR_SIZE_2D;
            float dy = sin(g_playerPtr->direction.y * (WINDOW_WIDTH/WINDOW_HEIGHT) * M_PI / 180.0f) * PLAYER_INDICATOR_SIZE_2D;
            glBegin(GL_LINES);
                glVertex2f(g_playerPtr->coords.x * 2 /  (float)WINDOW_WIDTH, g_playerPtr->coords.y * 2 / (float)WINDOW_HEIGHT);
                glVertex2f((g_playerPtr->coords.x+dx) * 2 /  (float)WINDOW_WIDTH, (g_playerPtr->coords.y+dy) * 2 / (float)WINDOW_HEIGHT);  // Point in the direction of view
            glEnd();

            glBegin(GL_LINES);
                glVertex2f(-0.0f, -0.0f);
                glVertex2f(1.0f, 1.0f);
            glEnd();

            glBegin(GL_LINES);
                glVertex2f(-1.0f,-1.0f);
                glVertex2f(-0.5f, -0.5f);
            glEnd();
        glPopMatrix();
    }
}

void reshape(int w, int h) {
    w = WINDOW_WIDTH;
    h = WINDOW_HEIGHT;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if(!g_viewModePtr) {
        printf("g_viewModePtr not defined ! Does not go further in keyboard\n");
        return 1;
    }
    if(!g_playerPtr) {
        printf("g_playerPtr not defined ! Does not go further in keyboard\n");
        return 1;
    }
    // Calculate movement based on rotation
    float dx = cos(g_playerPtr->direction.y * M_PI / 180.0f) * g_playerPtr->speed;
    float dy = sin(g_playerPtr->direction.y * (WINDOW_WIDTH/WINDOW_HEIGHT) * M_PI / 180.0f) * g_playerPtr->speed;
    switch (key) {
        case 'v':  // Toggle view mode
            *g_viewModePtr = !*g_viewModePtr;
            break;
        case 'z':  // Move forward
            g_playerPtr->coords.x += dx;
            g_playerPtr->coords.y += dy;
            break;
        case 's':  // Move backward
            g_playerPtr->coords.x -= dx;
            g_playerPtr->coords.y -= dy;
            break;
        case 'q':  // Strafe left
            g_playerPtr->coords.x -= dy;
            g_playerPtr->coords.y += dx;
            break;
        case 'd':  // Strafe right
            g_playerPtr->coords.x += dy;
            g_playerPtr->coords.y -= dx;
            break;
        // case 'r':  // Move up (Z axis)
        //     g_playerPtr->coords.z += MOVE_SPEED;
        //     break;
        // case 'f':  // Move down
        //     g_playerPtr->coords.z -= MOVE_SPEED;
        //     break;
        case 'a':  // Turn left
            g_playerPtr->direction.y = normalizeAngle(g_playerPtr->direction.y + g_playerPtr->rotSpeed);
            break;
        case 'e':  // Turn right
            g_playerPtr->direction.y = normalizeAngle(g_playerPtr->direction.y - g_playerPtr->rotSpeed);
            break;
        case 27:   // ESC key
            exit(0);
            break;
    }
    glutPostRedisplay();
}