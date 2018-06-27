#include "NodoGrafoEscenaParam.hpp"

int NodoGrafoEscenaParam::numParametros() {
  return parametros.size();
}

Parametro* NodoGrafoEscenaParam::leerPtrParametro(unsigned i) {
  if (i < numParametros())
    return &parametros[i];
  else
    return nullptr;
}

void NodoGrafoEscenaParam::siguienteCuadro() {
  for (Parametro& param : parametros)
    param.siguiente_cuadro();
}
