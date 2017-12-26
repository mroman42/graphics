#include "MaterialEstandar.hpp"

void MaterialEstandar::activar() {
  // Se habilita la iluminación en OpenGL
  glEnable(GL_LIGHTING);

  // Se configuran los parámetros de material de OpenGL
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]); // emisión
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]); // ambiente
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]); // difuso
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]); // especular
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, exponente); // exponente

  // Habilitación de textura para los materiales que la llevan
  if (textura == NULL)
    glDisable(GL_TEXTURE_2D);
  else {
    glEnable(GL_TEXTURE_2D);
    textura -> activar();
  }
  
}
