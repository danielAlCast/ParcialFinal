#include "colisiones.h"

Colisiones::Colisiones() {
    index = 0;
}

void Colisiones::addObject(float centerX, float centerY, float centerZ, float cubeSize) {
    Object newObject;

    newObject.centerX = centerX;
    newObject.centerY = centerY;
    newObject.centerZ = centerZ;
    newObject.cubeSize = cubeSize;

    objects[index] = newObject;
    index ++;
}

bool Colisiones::hasCollition(float centerX, float centerY, float centerZ, float cubeSize) {
    float c;

    for(int i = 0; i < index; i++) {
        c = sqrt(pow(centerX - objects[i].centerX, 2) +
                 pow(centerY - objects[i].centerY, 2) +
                 pow(centerZ - objects[i].centerZ, 2));

        if (c < cubeSize + objects[i].cubeSize)
            return true;
    }

    return false;
}

void Colisiones::drawColliders(){
    for(int i = 0; i < index; i++) {
        glPushMatrix();

        glTranslated(objects[i].centerX, objects[i].centerY, objects[i].centerZ);

        glColor3f(0.0,1.0,0.0);
        glutSolidSphere(objects[i].cubeSize,5,5);

        glPopMatrix();
    }
}
