#ifndef MALLAIND_H
#define MALLAIND_H

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include "aux.hpp"
#include <vector>

// Una malla es un objeto 3D, por lo que hereda de él y
// consta de un método "visualizar" que la dibuja.
class MallaInd : public Objeto3D {
protected:
  // Los objetos derivados de una malla 3D deberían poder modificar
  // los vértices y las caras de la malla.
  std::vector<Tupla3f> vertices;
  std::vector<Tupla3i> caras;

public:
  // Función de visualización de la malla, implementando el método
  // abstracto de un objeto3D.
  void visualizar(ContextoVis& cv) override;
};

#endif
