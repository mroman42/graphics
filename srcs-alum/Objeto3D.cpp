#include "Objeto3D.hpp"

// Implementa la función que devuelve el nombre y que puede usarse
// para depurar.
std::string Objeto3D::nombre() {
    return nombre_objeto;
}

bool Objeto3D::buscarObjeto(const int ident, const Matriz4f& mmodelado, Objeto3D** objeto, Tupla3f& centro_wc) {
  // Si el identificador es el buscado, se devuelve el objeto actual
  // con su centro.
  if (identificador == ident) {
    *objeto = this;
    centro_wc = centro_oc;
  }
}
