#ifndef MATERIALESTANDAR_HPP
#define MATERIALESTANDAR_HPP

#include "Material.hpp"
#include "Textura.hpp"

// Material estándar implemnetando el MIL visto en teoría
class MaterialEstandar : public Material {
public:
  // Puntero a la textura, nulo si no hay textura
  Textura* textura;

  // Reflectividad del material
  //  0 - Emisión
  //  1 - Reflectividad ambiental
  //  2 - Reflectividad difusa
  //  3 - Reflectividad especular
  Tupla4f color[4];
  
  // Exponente de brillo
  float exponente;

  void activar();
};

#endif
