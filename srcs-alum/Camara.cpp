#include "Camara.hpp"

void Camara::fijarMVPogl() {
  // Fija la matriz de vista en OpenGL, según el Tema 4
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMultMatrixf(mcv.matrizML);

  // Fija la matriz de proyección en OpenGL, según el Tema 4
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMultMatrixf(vf.matrizProy);

  // Redibujar después de fijar las nuevas matrices
  glutPostRedisplay();
}
