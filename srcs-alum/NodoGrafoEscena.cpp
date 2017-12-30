#include "NodoGrafoEscena.hpp"

void NodoGrafoEscena::visualizarGL(ContextoVis& cv) {
  // Guarda la modelview
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  // Guarda el material actual
  cv.pilaMateriales.push();

  // En el modo selección, coloca el color necesario
  if (cv.modoVisu == modoSeleccion)
    FijarColorIdent();

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

bool NodoGrafoEscena::buscarObjeto(const int ident, const Matriz4f& mmodelado,
				   Objeto3D** objeto, Tupla3f& centro_wc) {
  // Si el identificador es el buscado, se devuelve el objeto actual
  // con su centro.
  if (identificador == ident) {
    *objeto = this;
    // Habrá que multiplicar para calcular en coordenadas del mundo ???
    centro_wc = centro_oc;
    return true;
  }
  // En otro caso, se busca entre los hijos del nodo actual,
  // acumulando las matrices que operen sobre el centro que encuentre
  // luego.
  else {
    Matriz4f transformaciones = MAT_Ident();
    for (EntradaNGE entrada : entradas) {
      // Si es un objeto, busca sobre él
      if (entrada.tipoE == 0)
	if (entrada.objeto -> buscarObjeto(ident, mmodelado, objeto, centro_wc)) {
	  centro_wc = transformaciones * centro_wc;
	  return true;
	}
      // Si es una matriz, acumula la transformación
      if (entrada.tipoE == 1) {
	transformaciones = transformaciones * (*entrada.matriz);
      }
    }
  }

  return false;
}
