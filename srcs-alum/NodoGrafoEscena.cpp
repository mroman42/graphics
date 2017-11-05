#include "NodoGrafoEscena.hpp"
#include <vector>

void NodoGrafoEscena::visualizarGL(ContextoVis& cv) {
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  for (unsigned i=0; i<entradas.size(); i++) {
    if (entradas[i].tipoE == 0) {
      // Si la entrada es un subobjeto, lo visualiza
      entradas [i].objeto -> visualizarGL(cv);
    }
    else {
      // Si la entrada es una matriz, entra en modo modelview y la
      // compone.
      glMatrixMode(GL_MODELVIEW);
      glMultMatrixf(*(entradas[i].matriz));
    }
  }

  // Restaura la modelview guardada
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}


void NodoGrafoEscena::agregar(EntradaNGE* entrada) {
  entradas.push_back(entrada);
}

void NodoGrafoEscena::agregar(Objeto3D* pObjeto) {
  agregar(EntradaNGE(pObjeto));
}

void NodoGrafoEscena::agregar(const Matriz4f& pMatriz) {
  agregar(EntradaNGE(pMatriz));
}
