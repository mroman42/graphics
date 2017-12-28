#ifndef CAMARA_HPP
#define CAMARA_HPP

#include "aux.hpp"
#include "tuplasg.hpp"
#include "matrices-tr.hpp"
#include "MarcoCoordVista.hpp"
#include "ViewFrustum.hpp"

class Camara {
public:
  MarcoCoordVista mcv; // Marco de coordenadas de la vista
  ViewFrustum vf; // Parámetros de la proyección

  // Usa constructores por defecto para mcv y vf
  Camara() {};

  // Fija las matrices Modelview y Projection de OpenGL
  void fijarMVPogl(); 
};

#endif
