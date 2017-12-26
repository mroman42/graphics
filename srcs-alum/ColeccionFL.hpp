#ifndef COLECCIONFL_HPP
#define COLECCIONFL_HPP

#include <vector>
#include "FuenteLuz.hpp"

class ColeccionFL {
public:
  // Vector de fuentes de luz
  std::vector<FuenteLuz*> fuentes;

  // Activa todas las fuentes de luz de la colección
  void activar(); 
};

#endif
