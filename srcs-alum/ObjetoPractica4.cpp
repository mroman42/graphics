#include <string>
#include "ObjetoPractica4.hpp"


ObjetoPractica4::ObjetoPractica4() {
  // Datos globales de la escena
  nombre_objeto = "Escena de la práctica 4";
  const int nperfiles = 48;
  const std::string archivo_peon = "../plys/peon.ply";
  const std::string archivo_lata_pcue = "../plys/lata-pcue.ply";
  const std::string archivo_lata_psup = "../plys/lata-psup.ply";
  const std::string archivo_lata_pinf = "../plys/lata-pinf.ply";

  // Fuentes de luz
  direccional = new FuenteDireccional(1,5);
  posicional  = new FuentePosicional(Tupla3f(0,3,3));
  coleccion.fuentes.push_back(direccional);
  coleccion.fuentes.push_back(posicional);
  coleccion.activar();

  // Escalado general
  agregar(MAT_Escalado(0.2,0.2,0.2));
  
  // Lata
  agregar(MAT_Escalado(2,2,2));
  agregar(new MaterialLata());
  agregar(new MallaRevol(archivo_lata_pcue, nperfiles, true, false));
  agregar(new MaterialTapasLata());
  agregar(new MallaRevol(archivo_lata_pinf, nperfiles, true, false));
  agregar(MAT_Traslacion(0,0.025,0));
  agregar(new MallaRevol(archivo_lata_psup, nperfiles, true, false));
  
  // Peones
  agregar(MAT_Escalado(0.25,0.25,0.25));
  agregar(MAT_Traslacion(2.5,1.3,2.5));
  agregar(new MaterialPeonBlanco());
  agregar(new MallaRevol(archivo_peon, nperfiles, true, false));
  agregar(MAT_Traslacion(3,0,0));
  agregar(new MaterialPeonNegro());
  agregar(new MallaRevol(archivo_peon, nperfiles, true, false));
  agregar(MAT_Traslacion(-6,0,0));
  agregar(new MaterialPeonMadera());
  agregar(new MallaRevol(archivo_peon, nperfiles, true, false));
}

void ObjetoPractica4::aumentarAlpha()  { direccional -> variarAngulo(0,4);  coleccion.activar(); }
void ObjetoPractica4::aumentarBeta()   { direccional -> variarAngulo(1,4);  coleccion.activar(); }
void ObjetoPractica4::disminuirAlpha() { direccional -> variarAngulo(0,-4); coleccion.activar(); }
void ObjetoPractica4::disminuirBeta()  { direccional -> variarAngulo(1,-4); coleccion.activar(); }

MaterialPeonMadera::MaterialPeonMadera() {
  // Textura del peón de madera
  textura = new Textura();
  textura->img = new jpg::Imagen("../imgs/text-madera.jpg");
  textura->mgct = 0;
  textura->cs = Tupla4f(1,0,0,0);
  textura->ct = Tupla4f(0,1,0,0);

  color[0] = Tupla4f(0.6,0.6,0.6,0.1);
  color[1] = Tupla4f(0.1,0.1,0.1,0.1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 5;
}

MaterialLata::MaterialLata() {
  // Textura de la lata de refresco
  textura = new Textura();
  textura->img = new jpg::Imagen("../imgs/lata-coke.jpg");
  textura->mgct = 0;
  textura->cs = Tupla4f(1,0,0,0);
  textura->ct = Tupla4f(0,1,0,0);

  color[0] = Tupla4f(0.6,0.6,0.6,0.1);
  color[1] = Tupla4f(0.1,0.1,0.1,0.1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 5;
}

MaterialTapasLata::MaterialTapasLata() {
  textura = nullptr;
  color[0] = Tupla4f(0.6,0.6,0.6,1);
  color[1] = Tupla4f(0.2,0.2,0.2,1);
  color[2] = Tupla4f(0.2,0.2,0.2,1);
  color[3] = Tupla4f(0.9,0.9,0.9,1);
  exponente = 2;
}

MaterialPeonBlanco::MaterialPeonBlanco() {
  textura = nullptr;
  color[0] = Tupla4f(0.6,0.6,0.6,1);
  color[1] = Tupla4f(0.1,0.1,0.1,1);
  color[2] = Tupla4f(0.6,0.6,0.6,1);
  color[3] = Tupla4f(0.1,0.1,0.1,1);
  exponente = 5;
}

MaterialPeonNegro::MaterialPeonNegro() {
  textura = nullptr;
  color[0] = Tupla4f(0.1,0.1,0.1,1);
  color[1] = Tupla4f(0.1,0.1,0.1,1);
  color[2] = Tupla4f(0.1,0.1,0.1,1);
  color[3] = Tupla4f(0.9,0.9,0.9,1);
  exponente = 2;
}
