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

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {

	// switch to projection mode
	glMatrixMode(GL_PROJECTION);

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}


void display() {
    printf("Begin display\n");
    if(!g_viewModePtr) {
        printf("g_viewModePtr not defined ! Does not go further in display\n");
        return 1;
    }
    if(!g_playerPtr) {
        printf("g_playerPtr not defined ! Does not go further in display\n");
        return 1;
    }
    if(!g_boardPtr) {
        printf("g_boardPtr not defined ! Does not go further in display\n");
        return 1;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    printf("\n\n\n");
    printf("ViewMode = %d\n", *g_viewModePtr);
    // printf("player x = %d\n", g_playerPtr->coords.x);
    printPlayer(*g_playerPtr);

    float zero = 0.0f;
    // Print camera position and rotation
    printf("Camera Position: (%.2f, %.2f, %.2f) Rotation: (%.2f, %.2f)\n",
           g_playerPtr->coords.x * 2 / (float)WINDOW_WIDTH, g_playerPtr->coords.y * 2 / (float)WINDOW_HEIGHT, g_playerPtr->coords.z, zero, g_playerPtr->direction.y);

    if (*g_viewModePtr == 0) {
        // 3D View

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        reshape(WINDOW_WIDTH, WINDOW_HEIGHT);

        float lookX = g_playerPtr->coords.x + cos(g_playerPtr->direction.y * M_PI / 180.0f);
        float lookY = g_playerPtr->coords.y + sin(g_playerPtr->direction.y * M_PI / 180.0f);
        float lookZ = g_playerPtr->coords.z + sin(g_playerPtr->direction.z * M_PI / 180.0f);
        
        gluLookAt(g_playerPtr->coords.x , g_playerPtr->coords.y, g_playerPtr->coords.z,      // Camera position
                  lookX, lookY, lookZ,    // Look at point
                  0.0f, 0.0f, 1.0f);     // Up vector (Z is up)
        
        // Draw all elements
        drawBoard(g_boardPtr);
        drawFPS();
        
        restorePerspectiveProjection();

        glutSwapBuffers();
        // glutPostRedisplay();

        // reshape(WINDOW_WIDTH, WINDOW_HEIGHT);
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
        // glLoadIdentity();

        gluLookAt(0.0f, 0.0f, 1.0f,    // Camera high above on Z axis
                  0.0f, 0.0f, 0.0f,    // Looking at origin
                  0.0f, 1.0f, 0.0f);   // Up vector

        // Display the radius of the player
        drawCircle(g_playerPtr->coords, g_playerPtr->radius, 100);

        // Draw each element
        drawCameraPosition();
        drawBoard(g_boardPtr);
        
        glutSwapBuffers();

    }    
}

void drawFPS() {
    static int frame;
    static long time, timebase;
    static char s[50];

    glColor3f(1.0f, 1.0f, 1.0f);

    // display fps in the top window
    frame++;

    time=glutGet(GLUT_ELAPSED_TIME);
    if (time - timebase > 1000) {
        sprintf(s,"Tiim - FPS:%4.2f",
            frame*1000.0/(time-timebase));
        timebase = time;
        frame = 0;
    }

    setOrthographicProjection();

    glPushMatrix();
    glLoadIdentity();
    renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_12,s);
    glPopMatrix();
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

    if (*g_viewModePtr == 0) {
        // 3d view
        // draw Ground
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);
            glVertex3f(-400.0f, -300.0f, -0.0f);
            glVertex3f(-400.0f,  300.0f, -0.0f);
            glVertex3f( 400.0f,  300.0f, -0.0f);
            glVertex3f( 400.0f, -300.0f, -0.0f);
        glEnd();
    }

    // Draw Walls
    for(int i=0; i<board->nbWall; i++) {
        drawWall(&board->wall_list[i]);
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
        for(int i=0; i<wall->nbEdges2d; i++) {
            glVertex3f(wall->Edges2d[i].point1.x * 2 / (float)WINDOW_WIDTH, wall->Edges2d[i].point1.y * 2 / (float)WINDOW_HEIGHT, 0);
            glVertex3f(wall->Edges2d[i].point2.x * 2 / (float)WINDOW_WIDTH, wall->Edges2d[i].point2.y * 2 / (float)WINDOW_HEIGHT, 0);
        }
        glEnd();
    }
    else {
        // 3D view
        glPushMatrix();
        // glTranslatef(wall->Edges2d[i].point1.x, wall->Edges2d[i].point1.y, wall->Edges2d[i].point1.z);
        glColor3f(1.0f, 0.0f, 0.0f);
        
        for(int i=0; i<wall->nbEdges3d; i++) {
            glBegin(GL_QUADS);
            // glColor3f(i*0.1f+0.4f, 0.0f, 0.0f);
            switch(i){
                case 0: glColor3f(1.0f, 0.0f, 0.0f); break;
                case 1: glColor3f(0.0f, 1.0f, 0.0f); break;
                case 2: glColor3f(0.0f, 0.0f, 1.0f); break;
                case 3: glColor3f(1.0f, 1.0f, 0.0f); break;
            }
            // r
            glVertex3f((wall->Edges3d[i].r.x),
                       (wall->Edges3d[i].r.y), 
                        wall->Edges3d[i].r.z);

            // r + v
            glVertex3f((wall->Edges3d[i].r.x+wall->Edges3d[i].v.x), 
                       (wall->Edges3d[i].r.y+wall->Edges3d[i].v.y),
                        wall->Edges3d[i].r.z);
         
            // r + v + w
            glVertex3f((wall->Edges3d[i].r.x+wall->Edges3d[i].v.x+wall->Edges3d[i].w.x),
                       (wall->Edges3d[i].r.y+wall->Edges3d[i].v.y+wall->Edges3d[i].w.y),
                        wall->Edges3d[i].r.z+wall->Edges3d[i].w.z);

            // r + w
            glVertex3f((wall->Edges3d[i].r.x+wall->Edges3d[i].w.x),
                       (wall->Edges3d[i].r.y+wall->Edges3d[i].w.y),
                        wall->Edges3d[i].r.z+wall->Edges3d[i].w.z);

            glEnd();
        }
        
        glPopMatrix();
    }
}

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
   
            // Draw position indicator
            glPointSize(10.0f);
            glBegin(GL_POINTS);
                // TODO : make a function to get this coords
                glVertex2f(g_playerPtr->coords.x * 2 / (float)WINDOW_WIDTH, g_playerPtr->coords.y * 2 / (float)WINDOW_HEIGHT);
            glEnd();
            
            // Draw direction indicator
            float dx = cos(g_playerPtr->direction.y * M_PI / 180.0f) * PLAYER_INDICATOR_SIZE_2D;
            float dy = sin(g_playerPtr->direction.y * (WINDOW_WIDTH/WINDOW_HEIGHT) * M_PI / 180.0f) * PLAYER_INDICATOR_SIZE_2D;
            glBegin(GL_LINES);
                glVertex2f(g_playerPtr->coords.x * 2 / (float)WINDOW_WIDTH, g_playerPtr->coords.y * 2 / (float)WINDOW_HEIGHT);
                glVertex2f((g_playerPtr->coords.x+dx) * 2 / (float)WINDOW_WIDTH, (g_playerPtr->coords.y+dy) * 2 / (float)WINDOW_HEIGHT);  // Point in the direction of view
            glEnd();

        glPopMatrix();
    }
}

void reshape(int w, int h) {
    printf("Begin reshape\n");
    w = WINDOW_WIDTH;
    h = WINDOW_HEIGHT;
    if (*g_viewModePtr == 0) {
        glViewport(0, 0, w, h);
    } else {
        glViewport(0, w, h, 0);
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / h, 0.1f, 1000.0f);
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
    if(!g_boardPtr) {
        printf("g_boardPtr not defined ! Does not go further in keyboard\n");
        return 1;
    }
    wallCollision(*g_playerPtr, g_boardPtr);
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
        case 'r':  // Move up (Z axis)
            g_playerPtr->coords.z += g_playerPtr->speed;
            break;
        case 'f':  // Move down
            g_playerPtr->coords.z -= g_playerPtr->speed;
            break;
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

void drawCircle(Vec3 coords, float radius, int num_segments) {
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < num_segments; i++)   {
            float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; //get the current angle
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glVertex2f((x + coords.x) * 2 / (float)WINDOW_WIDTH, (y + coords.y) * 2 / (float)WINDOW_HEIGHT);
            // printf("theta=%f\tradius=%f\tx + coords.x=%f\ty + coords.y=%f\n", theta, radius, x + coords.x, y + coords.y);
        }
        glEnd();
    glPopMatrix();
}