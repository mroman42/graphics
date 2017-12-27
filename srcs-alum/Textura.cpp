#include "Textura.hpp"
#include "aux.hpp"

void Textura::activar() {
  // Especificación de los texels en la imagen de la textura
  uint tamx = img -> tamX(); // Número de columnas de la imagen
  uint tamy = img -> tamY(); // Número de filas de la imagen
  unsigned char* texels = img -> leerPixels(); // Puntero a los texels

  // Genera identificador y activa la textura
  glGenTextures(1, &idText);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, idText);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tamx, tamy, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);

  // Generación procedural de las coordenadas de textura
  if (mgct == 1) {
    // En coordenadas de objeto
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
  }
  else if (mgct == 2) {
    // En coordenadas de ojo
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);    
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
  }
  else {
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
  }
}
