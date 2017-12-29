#ifndef OBJETOPRACTICA4
#define OBJETOPRACTICA4

#include "NodoGrafoEscenaParam.hpp"
#include "MallaRevol.hpp"
#include "MallaPLY.hpp"
#include "Material.hpp"
#include "MaterialEstandar.hpp"
#include "FuenteLuz.hpp"
#include "FuenteDireccional.hpp"
#include "FuentePosicional.hpp"
#include "ColeccionFL.hpp"

class ObjetoPractica4 : public NodoGrafoEscenaParam {
public:
  ColeccionFL coleccion;
  FuenteDireccional* direccional;
  FuentePosicional* posicional;

  ObjetoPractica4();
  
  void aumentarAlpha();
  void aumentarBeta();
  void disminuirAlpha();
  void disminuirBeta();
};

class MaterialLata : public MaterialEstandar { public: MaterialLata(); };
class MaterialTapasLata : public MaterialEstandar { public: MaterialTapasLata(); };
class MaterialPeonMadera : public MaterialEstandar { public: MaterialPeonMadera(); };
class MaterialPeonBlanco : public MaterialEstandar { public: MaterialPeonBlanco(); };
class MaterialPeonNegro : public MaterialEstandar { public: MaterialPeonNegro(); };

class Lata : public NodoGrafoEscena { public: Lata(); };
class PeonBlanco : public NodoGrafoEscena { public: PeonBlanco(); };
class PeonNegro : public NodoGrafoEscena { public: PeonNegro(); };
class PeonMadera : public NodoGrafoEscena { public: PeonMadera(); };

#endif
