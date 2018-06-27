#ifndef TEXTURA_HPP
#define TEXTURA_HPP

#include "aux.hpp"
#include "jpg_imagen.hpp"
#include "tuplasg.hpp"

// Evita compilación cíclica
class ContextoVis;

class Textura {
public:
  GLuint idText;    // Identificador de OpenGL para la textura
  jpg::Imagen* img; // Puntero a la imagen con los texels en RAM
  unsigned mgct;    // Modo generación: 0=desactivado, 1=objeto, 2=mundo
  Tupla4f cs;       // Coeficientes (S) para generar coeficientes de textura
  Tupla4f ct;       // Coeficientes (T) para generar coeficientes de textura

  void activar(); // Activa la textura

  // Constructor estándar, inicializa valores
  Textura() : idText(0), img(nullptr), mgct(0) {};
};

#endif
