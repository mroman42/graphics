// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP

#include "PilaMateriales.hpp"
#include "ParTransf.hpp"

// tipo de datos enumerado para los modos de visualización:
typedef enum {
  modoPuntos,
  modoAlambre,
  modoSolido,
  modoAjedrez,
  modoIluminacionPlano,
  modoIluminacionSuave
} ModosVisu;
const int numModosVisu = 6;


// Contextos de visualización
class ContextoVis {
public:
  ModosVisu modoVisu; // modo de visualización actual
  bool modoVbos; // modo diferido para visualización de mallas
  PilaMateriales pilaMateriales; // Pila de materiales
  ParTransf pt; // Parámetros de transformación actuales
  
  ContextoVis() {
    modoVisu = modoAlambre; // poner alambre por defecto
    modoVbos = false; // no usar modo diferido por defecto
  }
};

#endif
