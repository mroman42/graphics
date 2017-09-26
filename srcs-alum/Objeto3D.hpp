#ifndef OBJETO_3D_HPP
#define OBJETO_3D_HPP

#include <string>
#include "practicas.hpp"

// Un objeto 3D es cualquier cosa que pueda ser visualizada
// dentro de OpenGL.
class Objeto3D {
protected:
  // Nombre interno del objeto. Puede usarse para depurar.
  // Debe accederse para lectura desde "nombre()".
  std::string nombre_objeto;

public:
  Objeto3D(){}
  
  // Devuelve el nombre interno del objeto.
  std::string nombre();

  // Visualiza un objeto con el modo de visualización dado.
  virtual void visualizar(ContextoVis& cv) = 0;
};

#endif
