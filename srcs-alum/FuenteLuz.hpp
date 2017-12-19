#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

class FuenteLuz {
public:
  Tupla4f posvec; // Posición o vector de dirección (x,y,z,w)
  Tupla4f colores[3]; // Colores: [0]ambiental, [1]difuso y [2]especular
  float longi; // Longitud del ángulo de rotación
  float lati; // Latitud del ángulo de rotación

  void activar(int i); // Activar la fuente de luz
};

class FuenteDireccional : public FuenteLuz {
public:
  // Inicialización de una fuente de luz direccional
  FuenteDireccional(float alpha_inicial, float beta_inicial);

  // Cambiar el ángulo de la fuente de luz
  void variarAngulo(unsigned angulo, float incremento);
};

class FuentePosicional : public FuenteLuz {
public:
  FuentePosicional(const Tupla3f& posicion);
};


class ColeccionFL {
public:
  // Vector de fuentes de luz
  std::vector<FuenteLuz*> fuentes;

  // Activa todas las fuentes de luz de la colección
  void activar(); 
};

class ColeccionFuentesP4 : public ColeccionFL {
public:
  ColeccionFuentesP4();
}


#endif
