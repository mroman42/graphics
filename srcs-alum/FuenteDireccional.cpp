#include "FuenteDireccional.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial) {
  // Latitud y longitud.
  lati = beta_inicial;
  longi = alpha_inicial;
  
  // Se marca como fuente direccional.
  posvec = {0.0, 0.0, 0.0, 0.0};
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento) {
  if (angulo == 0)
    longi += incremento;
  else
    lati += incremento;
}
