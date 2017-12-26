#ifndef FUENTEPOSICIONAL_HPP
#define FUENTEPOSICIONAL_HPP

#include "FuenteLuz.hpp"

class FuentePosicional : public FuenteLuz {
public:
  FuentePosicional(const Tupla3f& posicion);
};

#endif
