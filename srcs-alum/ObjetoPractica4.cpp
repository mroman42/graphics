#include "ObjetoPractica4.hpp"
#include "ColeccionFL.hpp"
#include "FuenteDireccional.hpp"
#include "FuentePosicional.hpp"

ObjetoPractica4::ObjetoPractica4() {
  // Datos globales de la escena
  nombre_objeto = "Escena de la práctica 4";
  const int nperfiles = 24;
  const std::string archivo_peon = "../plys/peon.ply";

  // Fuentes de luz
  ColeccionFL coleccion;
  coleccion.fuentes.push_back(new FuenteDireccional(0,0));
  coleccion.fuentes.push_back(new FuentePosicional(Tupla3f(0,3,3)));
  coleccion.activar();
  
  // Peón de madera
  agregar(new MaterialPeonBlanco());
  agregar(new MallaRevol(archivo_peon, nperfiles, true, true));
}

void ObjetoPractica4::aumentarAlpha() {}
void ObjetoPractica4::aumentarBeta() {}
void ObjetoPractica4::disminuirAlpha() {}
void ObjetoPractica4::disminuirBeta() {}

MaterialPeonMadera::MaterialPeonMadera() {
  // Textura del peón de madera
  textura = new Textura();
  textura->img = new jpg::Imagen("../imgs/text-madera.jpg");
  textura->mgct = 1;
  textura->cs = Tupla4f(2,0,0,0);
  textura->ct = Tupla4f(0,2,0,0);

  color[0] = Tupla4f(0.6,0.6,0.6,0.1);
  color[1] = Tupla4f(0.1,0.1,0.1,0.1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 5;
}

MaterialTapasLata::MaterialTapasLata() {
  textura = nullptr;
  color[0] = Tupla4f(0.6,0.6,0.6,0.1);
  color[1] = Tupla4f(0.1,0.1,0.1,0.1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 2;
}

MaterialPeonBlanco::MaterialPeonBlanco() {
  textura = nullptr;
  color[0] = Tupla4f(0.6,0.6,0.6,1);
  color[1] = Tupla4f(0.1,0.1,0.1,1);
  color[2] = Tupla4f(0.8,0.8,0.8,1);
  color[3] = Tupla4f(0.1,0.1,0.1,1);
  exponente = 8;
}

MaterialPeonNegro::MaterialPeonNegro() {
  textura = nullptr;
  color[0] = Tupla4f(0.1,0.1,0.1,1);
  color[1] = Tupla4f(0.1,0.1,0.1,1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(0.9,0.9,0.9,1);
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
