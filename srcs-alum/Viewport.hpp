#ifndef VIEWPORT_HPP
#define  VIEWPORT_HPP

#include "matrices-tr.hpp"

// Matriz de viewport y su inversa, necesarias para aplicaciones como
// la selección de objetos de la última práctica.
class Viewport {
public:
  int org_x; // Origen en pixels, esquina inferior izquierda, x
  int org_y; // Origen en pixels, esquina inferior izquierda, y
  int ancho; // Número de columnas (pixels)
  int alto;  // Número de filas (pixels)
  float ratio_yx; // Relación de aspecto alto/ancho
  Matriz4f matrizVp;    // Matriz de viewport: coordenadas normalizadas (NDC) a coordenadas de dispositivo (DC)
  Matriz4f matrizVpInv; // Matriz de viewport inversa: DC a NDC

  // Crea un viewport estándar de 512x512 con origen en (0,0)
  Viewport();

  // Crea un viewport dados unos parámetros
  Viewport(int p_org_x, int p_org_y, int p_ancho, int p_alto);

  // Fijar viewport
  void fijarViewport();
};

#endif
