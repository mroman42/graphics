#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "practicas.hpp"
#include "jpg_imagen.hpp"


class Textura {
public:
  GLuint idText; // Identificador de OpenGL para la textura
  jpg::Imagen* img; // Puntero a la imagen con los texels en RAM
  unsigned mgct; // Modo generación: 0=desactivado, 1=objeto, 2=mundo
  float cs[4];
  float ct[4];

  void activar(ContextoVis& cv);
};


// Material abstracto
class Material {
public:
  virtual void activar(ContextoVis& cv) = 0;
};

// Material estándar implemnetando el MIL visto en teoría
class MaterialEstandar : public Material {
public:
  Textura* textura; // puntero a la textura, nulo si no hay textura
  Tupla4f color[4]; 
  float exponente;

  virtual void activar(ContextoVis& cv);
};



#endif
