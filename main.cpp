//Proyecto Final
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "escena.h"

//Declaracion de variables
Escena escena;

//Variables dimensiones de la pantalla
int WIDTH=500;
int HEIGTH=500;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    escena.initScene();
    glClearColor(0,0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
}

void SpecialInput(int key, int x, int y)
{
    escena.updateView(key, x, y);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    escena.drawScene();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Examen Final");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}
