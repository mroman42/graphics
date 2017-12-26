#include "FuenteLuz.hpp"

void FuenteLuz::activar(int i) {
  // Activa la fuente de luz indicada. Usa que las fuentes son
  // constantes consecutivas.
  GLenum GL_LIGHTI = GL_LIGHT0 + i;
  glEnable(GL_LIGHTI);

  // Configuración de colores de la fuente
  glLightfv(GL_LIGHTI, GL_AMBIENT, colores[0]);
  glLightfv(GL_LIGHTI, GL_DIFFUSE, colores[1]);
  glLightfv(GL_LIGHTI, GL_SPECULAR, colores[2]);

  // Configuración de posición/dirección de una fuente.
  // El valor de la w en el vector (x,y,z,w) determina el tipo de
  // fuente de luz.

  // En fuentes posicionales, damos la posición directamente
  if (posvec[3] == 0) 
    glLightfv(GL_LIGHTI, GL_POSITION, posvec);

  // En fuentes direccionales, damos la dirección en coordenadas
  // polares.
  if (posvec[3] == 0) {
    const float ejez[4] = {0.0, 0.0, 1.0, 0.0};
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    {
      glLoadIdentity();
      glRotatef(longi, 0,1,0);
      glRotatef(lati, -1,0,0);
      glLightfv(GL_LIGHTI, GL_POSITION, ejez);
    }
    glPopMatrix();
  }
}
