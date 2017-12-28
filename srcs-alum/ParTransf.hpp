#ifndef PARTRANSF_HPP
#define PARTRANSF_HPP

#include "Camara.hpp"
#include "Viewport.hpp"

class ParTransf {
public:
  Camara cam;
  Viewport vp;

  // Usa constructores por defecto de los atributos
  ParTransf() {};
};

#endif
