#ifndef OBSERVADOR_H
#define OBSERVADOR_H

#include <GL/glut.h>
#include <math.h>
#include "colisiones.h"

class Observador{
private:
    float EYE_X=-3.0;
    float EYE_Y=0.0;
    float EYE_Z=0.0;
    float CENTER_X=10;
    float CENTER_Y=0;
    float CENTER_Z=0;
    float UP_X=0;
    float UP_Y=1;
    float UP_Z=0;

    float Theta=0;
    float PI = 3.14159265359;
    float Direction[3] = {1.0,0.0,0.0};

    float RadToDeg(float r);
    float DegToRad(float g);

    Colisiones *colisiones;

    void LookAt();
public:
    Observador();
    Observador(Colisiones *coll);

    void initView();
    void SpecialInput(int key, int x, int y);
};

#endif // OBSERVADOR_H
