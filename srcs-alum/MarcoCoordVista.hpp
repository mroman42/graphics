#ifndef MARCOCOORDVISTA_HPP
#define MARCOCOORDVISTA_HPP

#include "tuplasg.hpp"
#include "matrices-tr.hpp"

// Marco de coordenadas cartesiano de una vista
class MarcoCoordVista {
public:
  Tupla3f org; // Origen del marco de coordenadas
  Tupla3f eje[3]; // Ejes cartesianos del marco de coordenadas (ortonormales)
  Matriz4f matrizML; // Matriz de coordenadas de marco a coordenadas de mundo
  Matriz4f matrizLM; // Matriz de coordenadas de mundo a coordenadas de marco

  // Crea un marco de coordenadas en el origen mirando a Z-
  MarcoCoordVista();

  // Constructor con parámetros iguales a gluLookAt
  // pfoco: posición del ojo
  // paten: posición del punto de referencia, al que se atiende
  // pvup:  posición dirección
  MarcoCoordVista(const Tupla3f& pfoco, const Tupla3f& paten, const Tupla3f& pvup);
};

#endif
