#ifndef OBJETOPRACTICA3
#define OBJETOPRACTICA3

#include "NodoGrafoEscenaParam.hpp"
#include "MallaRevol.hpp"
#include "MallaPLY.hpp"
#include "MaterialEstandar.hpp"

class ObjetoPractica3 : public NodoGrafoEscenaParam {public: ObjetoPractica3();};
class Estructura : public NodoGrafoEscenaParam {public: Estructura();};
class Rotor : public NodoGrafoEscenaParam {public: Rotor();};
class Base : public NodoGrafoEscenaParam {public: Base();};
class Columna : public NodoGrafoEscenaParam{public: Columna();};
class Poste : public NodoGrafoEscenaParam{public: Poste(int,float,float,float,int);};
class Columnas : public NodoGrafoEscenaParam{public: Columnas();};
class Cilindro : public NodoGrafoEscenaParam{public: Cilindro();};
class Caballito : public NodoGrafoEscenaParam{public: Caballito();};

class MaterialMadera : public MaterialEstandar { public: MaterialMadera(); };
class MaterialMetal : public MaterialEstandar { public: MaterialMetal(); };
class MaterialVaca : public MaterialEstandar { public: MaterialVaca(); };

#endif
