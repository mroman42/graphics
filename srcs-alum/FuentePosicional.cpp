#include "FuentePosicional.hpp"

FuentePosicional::FuentePosicional(const Tupla3f& posicion) {
  // Color rojizo
  colores[0] = Tupla4f(0.6,0.5,0.5,1);
  colores[1] = Tupla4f(0.3,0.1,0.1,1);
  colores[2] = Tupla4f(0.9,0.7,0.7,1);

  // Se marca como fuente posicional
  posvec = {posicion[0], posicion[1], posicion[2], 1};
  lati = 0;
  longi = 0;
}
