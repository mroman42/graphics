#include "ColeccionFL.hpp"
#include "FuenteLuz.hpp"
#include <vector>

void ColeccionFL::activar() {
  // Normalización de vectores normales al activar la iluminación
  glEnable(GL_NORMALIZE);

  // Parámetros de iluminación
  // Proyección perspectiva, el observador es local y no está en el infinito
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  // Usa el color de la textura excepto en el especular, permite brillos blancos
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  // Parámetros de iluminación
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  
  // Activa las fuentes incluidas en la colección
  for (int i = 0; i < fuentes.size(); i++)
    fuentes[i] -> activar(i);
}

ColeccionFL::ColeccionFL() {}
