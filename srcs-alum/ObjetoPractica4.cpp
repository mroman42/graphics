#include "ObjetoPractica4.hpp"


ObjetoPractica4::ObjetoPractica4() {
  nombre_objeto = "Escena de la práctica 4";

  Material* material_peon_madera = new MaterialPeonMadera();
  agregar(material_peon_madera);

  const std::string archivo_peon = "../plys/peon.ply";
  const int nperfiles = 24;
  MallaInd* peon = new MallaRevol(archivo_peon, nperfiles, true, true);
  agregar(peon);
}

void ObjetoPractica4::aumentarAlpha() {}
void ObjetoPractica4::aumentarBeta() {}
void ObjetoPractica4::disminuirAlpha() {}
void ObjetoPractica4::disminuirBeta() {}

MaterialPeonMadera::MaterialPeonMadera() {
  // Textura del peón de madera
  textura = new Textura();
  textura->img = new jpg::Imagen("../imgs/text-madera.jpg");
  textura->idText = 1234;
  textura->mgct = 1;
  textura->cs = Tupla4f(2,0,0,0);
  textura->ct = Tupla4f(0,2,0,0);
}

MaterialTapasLata::MaterialTapasLata() {
  color[0] = Tupla4f(0.6,0.6,0.6,0.1);
  color[1] = Tupla4f(0.1,0.1,0.1,0.1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 2;
}

MaterialLata::MaterialLata() {
  
}

Fuente1::Fuente1() {
  posvec = Tupla4f(0,0,0,0);
  colores[0] = Tupla4f(1,1,1,1);
  colores[1] = Tupla4f(0,0,0,0);
  longi = 0;
  lati = 0;
  activar(1);
}
