#ifndef OBJETOPRACTICA3
#define OBJETOPRACTICA3

#include "NodoGrafoEscenaParam.hpp"
#include "MallaRevol.hpp"
#include "MallaPLY.hpp"

class ObjetoPractica3 : public NodoGrafoEscenaParam {public: ObjetoPractica3();};
class Rotor : public NodoGrafoEscenaParam {public: Rotor();};
class Base : public NodoGrafoEscenaParam {public: Base();};
class Columna : public NodoGrafoEscenaParam{public: Columna(float,float);};
class Columnas : public NodoGrafoEscenaParam{public: Columnas();};
class Cilindro : public NodoGrafoEscenaParam{public: Cilindro();};
class Caballo : public NodoGrafoEscenaParam{public: Caballo();};
  
#endif
