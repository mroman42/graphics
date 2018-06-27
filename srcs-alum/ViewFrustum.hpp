#ifndef VIEWFRUSTUM_HPP
#define VIEWFRUSTUM_HPP

#include "matrices-tr.hpp"

// Parámetros de transformación de la proyección
class ViewFrustum {
public:
  Matriz4f matrizProy;

  // Crea view-frustum
  ViewFrustum();

  // Calcula la matriz de proyección asumiendo view-frustum proyectivo
  // o asumiéndolo ortográfico.
  void perspectivo(float hfovy, float aspect, float zNear, float zFar);
  void ortografico(float dist, float aspect, float zNear, float zFar);
};

#endif
