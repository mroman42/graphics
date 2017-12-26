#ifndef FUENTEDIRECCIONAL_HPP
#define FUENTEDIRECCIONAL_HPP

#include "FuenteLuz.hpp"

class FuenteDireccional : public FuenteLuz {
public:
  // Inicialización de una fuente de luz direccional
  FuenteDireccional(float alpha_inicial, float beta_inicial);

  // Cambiar el ángulo de la fuente de luz
  void variarAngulo(unsigned angulo, float incremento);
};

#endif
