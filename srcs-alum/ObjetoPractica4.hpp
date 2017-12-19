#ifndef OBJETOPRACTICA4
#define OBJETOPRACTICA4

#include "NodoGrafoEscenaParam.hpp"
#include "MallaRevol.hpp"
#include "MallaPLY.hpp"
#include "Material.hpp"

class ObjetoPractica4 : public NodoGrafoEscenaParam {
public:
  ObjetoPractica4();

  void aumentarAlpha();
  void aumentarBeta();
  void disminuirAlpha();
  void disminuirBeta();
};

class MaterialLata : public MaterialEstandar {
public:
  MaterialLata();
};

class MaterialTapasLata : public MaterialEstandar {
public:
  MaterialTapasLata();
};

class MaterialPeonMadera : public MaterialEstandar {
public:
  MaterialPeonMadera();
};

class MaterialPeonBlanco : public MaterialEstandar {
public:
  MaterialPeonBlanco();
};

class MaterialPeonNegro : public MaterialEstandar {
public:
  MaterialPeonNegro();
};


#endif
