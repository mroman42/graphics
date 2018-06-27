#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Textura.hpp"
#include "jpg_imagen.hpp"

// Material abstracto
class Material {
public:
  virtual void activar() = 0;
};

#endif
