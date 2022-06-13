#ifndef ESCENA_H
#define ESCENA_H


#include <GL/glut.h>
#include "colisiones.h"

#include "edificio.h"
#include "observador.h"

class Escena {
private:
    float X_MIN=-50;
    float X_MAX=50;
    float Y_MIN=-50;
    float Y_MAX=50;
    float Z_MIN=-50;
    float Z_MAX=50;

    Colisiones *colisiones;

    Edificio edificio;
    Observador observador;

    void drawAxis();
    void loadColliders();

public:
    void drawScene();
    void updateScene();
    void initScene();
    void updateView(int key, int x, int y);

    Escena();
};

#endif // ESCENA_H
