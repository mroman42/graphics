#include "NodoGrafoEscena.hpp"

void NodoGrafoEscena::visualizarGL(ContextoVis& cv) {
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  for (EntradaNGE& entrada : entradas) {
    if (entrada.tipoE == 0) {
      // Si la entrada es un subobjeto, lo visualiza
      entrada.objeto -> visualizarGL(cv);
    }
    else {
      // Si la entrada es una matriz, entra en modo modelview y la
      // compone.
      glMatrixMode(GL_MODELVIEW);
      glMultMatrixf(*(entrada.matriz));
    }
  }

  // Restaura la modelview guardada
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}


void NodoGrafoEscena::agregar(EntradaNGE* entrada) {
  entradas.push_back(*entrada);
}

void NodoGrafoEscena::agregar(Objeto3D* pObjeto) {
  EntradaNGE* nueva = new EntradaNGE(pObjeto);
  agregar(nueva);
}

void NodoGrafoEscena::agregar(const Matriz4f& pMatriz) {
  EntradaNGE* nueva = new EntradaNGE(pMatriz);
  agregar(nueva);
}
