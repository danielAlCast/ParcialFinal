#ifndef COLISIONES_H
#define COLISIONES_H

#include <GL/glut.h>
#include <math.h>

#define MAXLENGHT 32

using namespace std;

struct Object {
    float centerX;
    float centerY;
    float centerZ;
    float cubeSize;
};

class Colisiones{
private:
    Object objects [MAXLENGHT];
    int index;

public:
    Colisiones();

    void addObject(float centerX, float centerY, float centerZ, float cubeSize);
    void drawColliders();
    bool hasCollition(float centerX, float centerY, float centerZ, float cubeSize);

};


#endif // COLISIONES_H
