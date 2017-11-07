#include "NodoGrafoEscenaParam.hpp"

int NodoGrafoEscenaParam::numParametros() {
  return parametros.size();
}

Parametro* NodoGrafoEscenaParam::leerPtrParametro(unsigned i) {
  return &parametros[i];
}

void NodoGrafoEscenaParam::siguienteCuadro() {
  for (Parametro& param : parametros)
    param.siguiente_cuadro();
}
