#include "escena.h"

Escena::Escena(){
    colisiones = new Colisiones();

    observador = Observador(colisiones);
}

void Escena::drawAxis(){
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
}

void Escena::loadColliders() {

    //Cube
    colisiones->addObject(0,0,0,.5);
}

void Escena::drawScene() {
    drawAxis();
    colisiones->drawColliders();

    glPushMatrix();
    edificio.draw();

    glPopMatrix();
}

void Escena::initScene() {
    observador.initView();
    loadColliders();
}

void Escena::updateView(int key, int x, int y) {
    observador.SpecialInput(key, x, y);
}
