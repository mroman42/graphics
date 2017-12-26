#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

#include "aux.hpp"
#include "tuplasg.hpp"

class FuenteLuz {
public:
  Tupla4f posvec; // Posición o vector de dirección (x,y,z,w)
  Tupla4f colores[3]; // Colores: [0]ambiental, [1]difuso y [2]especular
  float longi; // Longitud del ángulo de rotación (alpha)
  float lati; // Latitud del ángulo de rotación (beta)

  void activar(int i); // Activar la fuente de luz
};

#endif
