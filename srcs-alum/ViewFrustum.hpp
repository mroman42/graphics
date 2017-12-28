#ifndef VIEWFRUSTUM_HPP
#define VIEWFRUSTUM_HPP

#include "matrices-tr.hpp"

// Parámetros de transformación de la proyección
class ViewFrustum {
public:
  bool persp;
  float left;
  float right;
  float bottom;
  float top;
  float near;
  float far;
  Matriz4f matrizProy;

  // Crea view-frustum ortográfico, de lado 2 y centrado en el 0.
  ViewFrustum();

  // Crea view-frustum perspectiva
  ViewFrustum(float hfovy, float aspect, float zNear, float zFar);
};

#endif
