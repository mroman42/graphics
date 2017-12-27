#include "FuenteDireccional.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial) {
  // Latitud y longitud.
  lati = beta_inicial;
  longi = alpha_inicial;

  // Colores
  colores[0] = Tupla4f(0.5,0.5,0.5,1);
  colores[1] = Tupla4f(0.1,0.1,0.1,1);
  colores[2] = Tupla4f(0.7,0.7,0.7,1);
  
  // Se marca como fuente direccional.
  posvec = {0.0, 0.0, 0.0, 0.0};
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento) {
  if (angulo == 0)
    longi += incremento;
  else
    lati += incremento;
}
