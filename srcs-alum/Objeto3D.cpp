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
    return true;
  }

  return false;
}

void Objeto3D::FijarColorIdent() {
  // Asigna un color sacado exactamente del identificador del objeto.
  if (identificador != -1 and identificador != 0) {
    const unsigned char byteR = (identificador           ) % 0x100U; // rojo,  byte menos significativo
    const unsigned char byteG = (identificador /   0x100U) % 0x100U; // verde, byte intermedio
    const unsigned char byteB = (identificador / 0x10000U) % 0x100U; // azul,  byte más significativo
    glColor3ub(byteR, byteG, byteB);
  }
}
