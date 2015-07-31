/***************************
 * All display related code should be here
 **************************/

#include "view.h"
#include "model.h"
#include "controller.h"

#include <math.h>
#include <stdio.h>

// Using OpenGL version 2.1 for support of more graphics cards
#include <GL/glut.h>

#define Y_VAL -5.0

void display (void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    player cur = getPlayer();

    //Camera is always centered on the player
    gluLookAt(cur.x, cur.y, 0.0, cur.x, cur.y, -5.0, 0.0, 1.0, 0.0);

    //Draw in world
    drawWorld();

    //Move brush to player location
    glTranslatef(cur.x, cur.y, Y_VAL);
    glRotatef((cur.angle*360)/(2*M_PI),0.0,0.0,1.0);

    //Draw player
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-0.4,0.2,Y_VAL);
    glVertex3f(0.2,0.0,Y_VAL);
    glVertex3f(-0.4,-0.2,Y_VAL);
    glEnd();
    glFlush();          //Finish rendering
}

void drawWorld() {
    /*int x = worldXDim();
    int y = worldYDim();

    material out;
    glTranslatef(0,0,Y_VAL -0.1);

    int i = 0;
    for (i = 0; i < x; i++) {
        glBegin(GL_TRIANGLE_STRIP);
        
        int j = 0;

        out = materialAtPoint(i,j,0);
        glColor3f(out.r, out.g, out.b);
        glVertex3f(i,j,Y_VAL -0.1);
        glVertex3f(i,j+1,Y_VAL -0.1);

        for (j = 0; j < y; j++) {
            out = materialAtPoint(i, j, 0);
            //printf("color r%f, g%f, b%f, of %s ",out.r, out.g, out.b, out.name);

            glColor3f(out.r, out.g, out.b);
            glVertex3f(i+1,j+1,Y_VAL - 0.1);
            glVertex3f(i+1,j,Y_VAL -0.1);

        }
        glEnd();
    }*/

    glTranslatef(0,0,Y_VAL-0.1);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0,0.0,1.0);

    glVertex3f(0.0,10.0,Y_VAL-0.1);
    glVertex3f(10.0,10.0,Y_VAL-0.1);
    glVertex3f(0.0,0.0,Y_VAL-0.1);

    glColor3f(0.0,1.0,0.0);
    glVertex3f(10.0,0.0,Y_VAL-0.1);
    glEnd();
}


void reshape (int x, int y) {
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void initialize (int argc, char **argv) {
 
    //Initialize model
    initPlayer();
    initWorld();

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300,300);
    
    //Create a window with rendering context and everything else we need
    glutCreateWindow("Intro");
    glClearColor(0.0,0.0,0.0,0.0);
 
    //Assign the two used Msg-routines
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);

    //Let GLUT get the msgs
    glutMainLoop();
}
