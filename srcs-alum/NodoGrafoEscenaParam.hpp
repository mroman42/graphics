#ifndef NODOGRAFOESCENAPARAM_H
#define NODOGRAFOESCENAPARAM_H

#include "NodoGrafoEscena.hpp"
#include "Parametro.hpp"

class NodoGrafoEscenaParam : public NodoGrafoEscena {
public:
  std::vector<Parametro> parametros;
  
  // Devuelve el número de parámetros
  int numParametros();

  // Devuelve el puntero al i-ésimo parámetro
  Parametro* leerPtrParametro(unsigned i);

  // Actualiza el objeto para pasar al siguiente cuadro
  void siguienteCuadro();
};

#endif
