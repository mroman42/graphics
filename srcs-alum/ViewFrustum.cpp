#include "ViewFrustum.hpp"

ViewFrustum::ViewFrustum() {
  // Empieza colocando una matriz identidad de proyección, sólo cuando
  // conozcamos el tipo de view-frustum será interesante usar más
  // datos.
  matrizProy = MAT_Ident();
}

void ViewFrustum::perspectivo(float hfovy, float aspect, float zNear, float zFar) {
  // Calcula la matriz de perspectiva directamente
  matrizProy = MAT_Perspectiva(hfovy, aspect, zNear, zFar);
}

void ViewFrustum::ortografico(float dist, float aspect, float zNear, float zFar) {
  // Elige un plano de recorte por distancia y aspecto
  float left = -dist*aspect;
  float right = dist*aspect;
  float bottom = -dist;
  float top = dist;

  // La librería de matrices proporciona matrices ortográficas
  matrizProy = MAT_Ortografica(left, right, bottom, top, zNear, zFar);
}
