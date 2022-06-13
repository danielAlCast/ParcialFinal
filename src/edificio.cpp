#include "edificio.h"

Edificio::Edificio()
{

}

void Edificio::draw() {
    glColor3f(1.0,0.0,1.0);
    glutSolidCube(1);
}
