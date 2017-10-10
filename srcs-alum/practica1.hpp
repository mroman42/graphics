// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA1_HPP
#define IG_PRACTICA1_HPP

#include "MallaInd.hpp"
#include "aux.hpp"
#include "tuplasg.hpp"

void P1_Inicializar(int argc, char *argv[]);
bool P1_FGE_PulsarTeclaNormal(unsigned char tecla);
void P1_DibujarObjetos(ContextoVis & cv);

class Cubo : public MallaInd {
public:
  Cubo();
};

class Tetraedro : public MallaInd {
public:
  Tetraedro();
};

#endif
