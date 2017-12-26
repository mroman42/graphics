#include "NodoGrafoEscena.hpp"

void NodoGrafoEscena::visualizarGL(ContextoVis& cv) {
  // Guarda la modelview
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  // Guarda el material actual
  cv.pilaMateriales.push();

  for (EntradaNGE& entrada : entradas) {
    if (entrada.tipoE == 0) {
      // Si la entrada es un subobjeto, lo visualiza
      entrada.objeto -> visualizarGL(cv);
    }
    else if (entrada.tipoE == 1) {
      // Si la entrada es una matriz, entra en modo modelview y la
      // compone.
      glMatrixMode(GL_MODELVIEW);
      glMultMatrixf(*(entrada.matriz));
    }
    else if (entrada.tipoE == 2) {
      // Si la entrada es un material, lo activa
      cv.pilaMateriales.activarMaterial(entrada.material);
    }
  }

  // Restaura el material original
  cv.pilaMateriales.pop();
  
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

void NodoGrafoEscena::agregar(Material* pmaterial) {
  EntradaNGE* nueva = new EntradaNGE(pmaterial);
  agregar(nueva);
}
