#include "ViewFrustum.hpp"

ViewFrustum::ViewFrustum() {
  // View-frustum ortográfica
  persp = false;
  
  // De lado 2 y centrada en el 0
  left = -1;
  right = 1;
  bottom = -1;
  top = 1;
  near = -1;
  far = 1;

  // La librería de matrices proporciona matrices ortográficas
  matrizProy = MAT_Ortografica(left, right, bottom, top, near, far);
}

ViewFrustum::ViewFrustum(float hfovy, float aspect, float zNear, float zFar) {
  // View-frustum perspectiva
  persp = true;

  // Parámetros
  // ???
  // Qué sentido tienen los parámetros una vez calculada la matriz?
  // top = 
  // left =
  // right =
  // bottom = 
  near = zNear;
  far = zFar;

  // La librería de matrices proporciona matrices de perspectiva
  matrizProy = MAT_Perspectiva(hfovy, aspect, zNear, zFar);
}
